#ifndef UNIPLATFORMFUNCTIONS_H
#define UNIPLATFORMFUNCTIONS_H

#ifdef linux
#include "LinuxFunctions.h"
#endif

#include "UniplatformConstants.h"

namespace Uniplatform {
    void initialize();
    void finalize();

    void mouseDownLeft();
    void mouseUpLeft();

    void mouseDownRight();
    void mouseUpRight();

    void moveCursor(int dx, int dy);

    void downKey(int key);
    void upKey(int key);
}

#endif // UNIPLATFORMFUNCTIONS_H
