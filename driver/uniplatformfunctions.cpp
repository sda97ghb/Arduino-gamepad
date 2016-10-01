#include "UniplatformFunctions.h"

void Uniplatform::initialize()
{
#ifdef linux
    X11::openDisplay();
#endif
}

void Uniplatform::finalize()
{
#ifdef linux
    X11::closeDisplay();
#endif
}

void Uniplatform::mouseDownLeft()
{
#ifdef linux
    X11::mouseDownLeft();
#endif
}

void Uniplatform::mouseUpLeft()
{
#ifdef linux
    X11::mouseUpLeft();
#endif
}

void Uniplatform::mouseDownRight()
{
#ifdef linux
    X11::mouseDownRight();
#endif
}

void Uniplatform::mouseUpRight()
{
#ifdef linux
    X11::mouseUpRight();
#endif
}

void Uniplatform::moveCursor(int dx, int dy)
{
#ifdef linux
    X11::moveCursor(dx, dy);
#endif
}

void Uniplatform::downKey(int key)
{
#ifdef linux
    X11::downKey(key);
#endif
}

void Uniplatform::upKey(int key)
{
#ifdef linux
    X11::upKey(key);
#endif
}
