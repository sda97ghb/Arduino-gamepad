#ifndef GAMEPADDATA_H
#define GAMEPADDATA_H

#include <stdexcept>

#include "Point2D.h"

#include "UniplatformConstants.h"

//////////////////////////////////////////////////////////////////////////////////
/// \brief The GamepadData class
///
class GamepadData
{
public:
    GamepadData();

    const Point2D& joystick(int n) const;
    void setJoystick(int n, const Point2D& pos);

    bool mouseButtonState(int button) const;
    void setMouseButtonState(int button, bool state);

private:
    Point2D _joystick1;
    Point2D _joystick2;

    bool _mouseLeftState;
    bool _mouseRightState;

};

#endif // GAMEPADDATA_H
