#ifndef _GLOBAL_
#define _GLOBAL_

#include <Windows.h>


class Global
{
public:
    static int WindowHeight;
    static int WindowWidth;

    static double PI;

    static const int ArrDxDy[2];

    static HANDLE hConsole;


    static void GotoXY(int column, int line)
    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(hConsole, coord);
    }


    static void TextColor(int color)
    {
        SetConsoleTextAttribute(hConsole, color);
    }


    static void ClearScreen()
    {
        CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
        COORD	Home = { 0, 0 };
        DWORD	dummy;

        GetConsoleScreenBufferInfo(hConsole, &csbiInfo);

        FillConsoleOutputCharacter(hConsole, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
        csbiInfo.dwCursorPosition.X = 0;
        csbiInfo.dwCursorPosition.Y = 0;
        SetConsoleCursorPosition(hConsole, csbiInfo.dwCursorPosition);
    }
};


#endif