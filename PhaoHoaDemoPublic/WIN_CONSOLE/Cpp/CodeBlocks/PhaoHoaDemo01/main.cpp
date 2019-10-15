#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "PhaoHoa.hpp"


int main( )
{
    std::srand(std::time(0));

    PhaoHoa phaohoa;

    while (true)
    {
        bool ret = phaohoa.CapNhat();
        Global::GotoXY(0, 0);
        Sleep(100);

        if (ret == false)
            break;
    }

    while (getchar() != 10);

    return 0;
}


int Global::WindowWidth = 79;
int Global::WindowHeight = 29;

double Global::PI = 3.1415926535;
const int Global::ArrDxDy[2] = { -1, 1 };

HANDLE Global::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);