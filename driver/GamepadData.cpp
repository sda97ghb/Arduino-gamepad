#include "GamepadData.h"

GamepadData::GamepadData() :
    _joystick1{0, 0},
    _joystick2{0, 0},
    _mouseLeftState(false),
    _mouseRightState(false)
{
}

const Point2D& GamepadData::joystick(int n) const
{
    switch (n)
    {
    case 1 : return _joystick1;
    case 2 : return _joystick2;
    default :
    {
        std::string ERROR_MESSAGE = "can't get: there is no joystick with number ";
        ERROR_MESSAGE += n;
        throw std::logic_error(ERROR_MESSAGE);
    }
    }
}

void GamepadData::setJoystick(int n, const Point2D& pos)
{
    switch (n)
    {
    case 1 : _joystick1 = pos; break;
    case 2 : _joystick2 = pos; break;
    default :
    {
        std::string ERROR_MESSAGE = "can't set: there is no joystick with number ";
        ERROR_MESSAGE += n;
        throw std::logic_error(ERROR_MESSAGE);
    }
    }
}

bool GamepadData::mouseButtonState(int button) const
{
    switch (button)
    {
    case MouseButton::Left : return _mouseLeftState;
    case MouseButton::Right : return _mouseRightState;
    };
}

void GamepadData::setMouseButtonState(int button, bool state)
{
    switch (button)
    {
    case MouseButton::Left : _mouseLeftState = state; break;
    case MouseButton::Right : _mouseRightState = state; break;
    };
}
