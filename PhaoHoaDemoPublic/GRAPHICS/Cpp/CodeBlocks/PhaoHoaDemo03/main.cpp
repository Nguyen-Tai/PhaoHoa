#include <cstdlib>
#include <ctime>
#include "PhaoHoaManager.hpp"
#include "graphics.h"


int Global::WindowWidth = 700;
int Global::WindowHeight = 500;
Point Global::GiaToc(0, 0.15f);


int main( )
{
    std::srand(std::time(0));

    initwindow(Global::WindowWidth, Global::WindowHeight, "Phao hoa demo 03");
    
    
    PhaoHoaManager manager;

    while (true)
    {
        manager.CapNhat();
        Sleep(20);
    }

    getch();
    return 0;
}
