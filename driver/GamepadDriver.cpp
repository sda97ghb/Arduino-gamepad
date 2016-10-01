#include "GamepadDriver.h"

GamepadDriver::GamepadDriver(const std::string& device, GamepadSettings settings) :
    _io(),
    _port(_io),
    _data(),
    _settings(settings)
{
    _port.open(device);
    _port.set_option(boost::asio::serial_port_base::baud_rate(9600));

    Uniplatform::initialize();
}

GamepadDriver::~GamepadDriver()
{
    Uniplatform::finalize();
}

void GamepadDriver::update()
{
    bool previousLeftButtonState = _data.mouseButtonState(MouseButton::Left);
    bool previousRightButtonState = _data.mouseButtonState(MouseButton::Right);

    updateData();

    moveCursor();
    updateMouseButtons(previousLeftButtonState, previousRightButtonState);
    emulateKeyboard();
}

std::string GamepadDriver::readLine()
{
    char c = '\0';
    std::string buf = "";
    while (true)
        try
        {
            boost::asio::read(_port, boost::asio::buffer(&c, 1));
            if (c == '\n')
                break;
            buf += c;
        }
        catch (...) {}
    return buf;
}

void GamepadDriver::updateData()
{
    std::stringstream stream(readLine());

    auto parsePoint = [&stream] () -> Point2D
    {
        int x, y;
        stream >> x >> y;
        return Point2D{x, y};
    };
    auto parseBool = [&stream] () -> bool
    {
        int b;
        stream >> b;
        return b == 1;
    };

    _data.setJoystick(1, parsePoint());
    _data.setJoystick(2, parsePoint());
    _data.setMouseButtonState(MouseButton::Left, parseBool());
    static bool b = true;
    if (b)
    {
        b = false;
        return;
    }
    _data.setMouseButtonState(MouseButton::Right, parseBool());
}

void GamepadDriver::moveCursor()
{
    auto getChange = [this] (int deviation) -> int
    {
        auto getSpeed = [this] (int deviation)
        {
            if (abs(deviation) < _settings.stopThreshold())
                return 0;
            if (abs(deviation) > _settings.fastThreshold())
                return _settings.fastSpeed();
            return _settings.slowSpeed();
        };
        int speed = getSpeed(deviation);
        return (deviation < 0) ? - speed : speed;
    };
    int dx = getChange(_data.joystick(1).x);
    int dy = - getChange(_data.joystick(1).y);
    Uniplatform::moveCursor(dx, dy);
}

void GamepadDriver::updateMouseButtons(bool previousLeftButtonState,
                                       bool previousRightButtonState)
{
    bool leftButtonState = _data.mouseButtonState(MouseButton::Left);
    bool rightButtonState = _data.mouseButtonState(MouseButton::Right);

    if (leftButtonState && !previousLeftButtonState)
        Uniplatform::mouseDownLeft();
    else if (!leftButtonState && previousLeftButtonState)
        Uniplatform::mouseUpLeft();

    if (rightButtonState && !previousRightButtonState)
        Uniplatform::mouseDownRight();
    else if (!rightButtonState && previousRightButtonState)
        Uniplatform::mouseUpRight();
}

void GamepadDriver::emulateKeyboard()
{
    Point2D joystick2 = _data.joystick(2);
    if (joystick2.x > _settings.horizontalThreshold())
    {
        Uniplatform::downKey(Key::D);
        Uniplatform::upKey(Key::A);
    }
    if (joystick2.x < - _settings.horizontalThreshold())
    {
        Uniplatform::downKey(Key::A);
        Uniplatform::upKey(Key::D);
    }
    if (joystick2.x > - _settings.horizontalThreshold() &&
        joystick2.x < _settings.horizontalThreshold())
    {
        Uniplatform::upKey(Key::D);
        Uniplatform::upKey(Key::A);
    }
    if (joystick2.y > _settings.verticalThreshold())
    {
        Uniplatform::downKey(Key::W);
        Uniplatform::upKey(Key::S);
    }
    if (joystick2.y < - _settings.verticalThreshold())
    {
        Uniplatform::downKey(Key::S);
        Uniplatform::upKey(Key::W);
    }
    if (joystick2.y > - _settings.verticalThreshold() &&
        joystick2.y < _settings.verticalThreshold())
    {
        Uniplatform::upKey(Key::W);
        Uniplatform::upKey(Key::S);
    }
}
