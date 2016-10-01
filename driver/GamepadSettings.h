#ifndef GAMEPADSETTINGS_H
#define GAMEPADSETTINGS_H

class GamepadSettings
{
public:
    GamepadSettings(int fastSpeed, int slowSpeed,
                    int stopThreshold, int fastThreshold,
                    int horizontalThreshold, int verticalThreshold);

    GamepadSettings(int fastSpeed, int slowSpeed);

    int fastSpeed() const;
    void setFastSpeed(int fastSpeed);

    int slowSpeed() const;
    void setSlowSpeed(int slowSpeed);

    int stopThreshold() const;
    void setStopThreshold(int stopThreshold);

    int fastThreshold() const;
    void setFastThreshold(int fastThreshold);

    int horizontalThreshold() const;
    void setHorizontalThreshold(int horizontalThreshold);

    int verticalThreshold() const;
    void setVerticalThreshold(int verticalThreshold);

private:
    int _fastSpeed;
    int _slowSpeed;
    int _stopThreshold;
    int _fastThreshold;

    int _horizontalThreshold;
    int _verticalThreshold;
};

#endif // GAMEPADSETTINGS_H
