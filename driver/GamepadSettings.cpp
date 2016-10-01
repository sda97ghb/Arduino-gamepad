#include "GamepadSettings.h"

GamepadSettings::GamepadSettings(int fastSpeed, int slowSpeed,
                int stopThreshold, int fastThreshold,
                int horizontalThreshold, int verticalThreshold) :
    _fastSpeed(fastSpeed),
    _slowSpeed(slowSpeed),
    _stopThreshold(stopThreshold),
    _fastThreshold(fastThreshold),
    _horizontalThreshold(horizontalThreshold),
    _verticalThreshold(verticalThreshold)
{
}

GamepadSettings::GamepadSettings(int fastSpeed, int slowSpeed) :
    _fastSpeed(fastSpeed),
    _slowSpeed(slowSpeed),
    _stopThreshold(5),
    _fastThreshold(95),
    _horizontalThreshold(80),
    _verticalThreshold(70)
{
}

int GamepadSettings::fastSpeed() const
{
    return _fastSpeed;
}

void GamepadSettings::setFastSpeed(int fastSpeed)
{
    _fastSpeed = fastSpeed;
}

int GamepadSettings::slowSpeed() const
{
    return _slowSpeed;
}

void GamepadSettings::setSlowSpeed(int slowSpeed)
{
    _slowSpeed = slowSpeed;
}

int GamepadSettings::stopThreshold() const
{
    return _stopThreshold;
}

void GamepadSettings::setStopThreshold(int stopThreshold)
{
    _stopThreshold = stopThreshold;
}

int GamepadSettings::fastThreshold() const
{
    return _fastThreshold;
}

void GamepadSettings::setFastThreshold(int fastThreshold)
{
    _fastThreshold = fastThreshold;
}

int GamepadSettings::horizontalThreshold() const
{
    return _horizontalThreshold;
}

void GamepadSettings::setHorizontalThreshold(int horizontalThreshold)
{
    _horizontalThreshold = horizontalThreshold;
}

int GamepadSettings::verticalThreshold() const
{
    return _verticalThreshold;
}

void GamepadSettings::setVerticalThreshold(int verticalThreshold)
{
    _verticalThreshold = verticalThreshold;
}
