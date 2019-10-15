#include <cstdlib>
#include <ctime>
#include "PhaoHoa.hpp"
#include "graphics.h"


int Global::WindowWidth = 700;
int Global::WindowHeight = 500;


int main( )
{
    std::srand(std::time(0));

    initwindow(Global::WindowWidth, Global::WindowHeight, "Phao hoa demo 01");
    
    
    PhaoHoa phaoHoa;

    while (true)
    {
        cleardevice();
        phaoHoa.CapNhat();

        Sleep(40);
    }

    getch();
    return 0;
}
