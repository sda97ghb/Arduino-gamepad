#include <cstring>

#include "GamepadDriver.h"
#include "Presets.h"

int main(int argc, char** argv)
{
    GamepadSettings settings = TerrariaSettings;
    if (argc >= 2)
    {
        if (strcmp(argv[1], "Terraria") == 0)
            settings = TerrariaSettings;
        if (strcmp(argv[1], "HotlimeMiami2") == 0)
            settings = HotlimeMiami2Settings;
        if (strcmp(argv[1], "left4dead2") == 0)
            settings = Left4Dead2Settings;
    }

    GamepadDriver driver("/dev/ttyACM0", settings);

    while (true)
        driver.update();

    return 0;
}
