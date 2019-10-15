#include <cstdlib>
#include <ctime>
#include "PhaoHoaManager.hpp"
#include "graphics.h"


int Global::WindowWidth = 700;
int Global::WindowHeight = 500;


int main( )
{
    std::srand(std::time(0));

    initwindow(Global::WindowWidth, Global::WindowHeight, "Phao hoa demo 02");
    
    
    PhaoHoaManager manager;

    while (true)
    {
        manager.CapNhat();
        Sleep(40);
    }

    getch();
    return 0;
}
