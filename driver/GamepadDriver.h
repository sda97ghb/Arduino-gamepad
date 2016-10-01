#ifndef GAMEPADDRIVER_H
#define GAMEPADDRIVER_H

#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>

#include "GamepadData.h"
#include "GamepadSettings.h"

#include "UniplatformFunctions.h"

class GamepadDriver
{
public:
    GamepadDriver(const std::string& device, GamepadSettings settings);
    ~GamepadDriver();

    void update();

private:
    std::string readLine();
    void updateData();

    void moveCursor();

    void updateMouseButtons(bool previousLeftButtonState,
                            bool previousRightButtonState);

    void emulateKeyboard();

private:
    boost::asio::io_service _io;
    boost::asio::serial_port _port;

    GamepadData _data;
    GamepadSettings _settings;
};


#endif // GAMEPADDRIVER_H
