#ifndef _HAT_
#define _HAT_


#include <stdio.h>
#include "Point.hpp"
#include "Global.hpp"


// hạt sáng
class Hat
{
public:
    Point ToaDo;        // tọa độ
    Point VanToc;       // vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn

    int ThoiGianSong;   // thời gian sống, thời gian sống <= 0 tức là đã chết

    Point ToaDoCu;      // tọa độ cũ


    Hat()
    {
        
    }


    Hat(Point toado, Point vantoc, int thoigiansong)
    {
        this->ToaDo = toado;
        this->VanToc = vantoc;
        this->ThoiGianSong = thoigiansong;
    }


    
    virtual void Ve(bool xoaToaDoCu)
    {
        if (xoaToaDoCu)
            VeXoa(ToaDoCu);

        Global::GotoXY(ToaDo.X, ToaDo.Y);
        putchar('*');
    }


    virtual void VeXoa(Point toado)
    {
        Global::GotoXY(toado.X, toado.Y);
        putchar(' ');
    }


    // trả về true nếu hạt còn sống, trả về false nếu hạt đã chết (hết thời gian sống)
    virtual bool CapNhat(bool xoaToaDoCu)
    {
        if (ThoiGianSong <= 0)
            return false;

        ToaDoCu = ToaDo;

        ToaDo.X += VanToc.X;
        ToaDo.Y += VanToc.Y;

        ThoiGianSong--;

        Ve(xoaToaDoCu);

        if (ThoiGianSong <= 0)
            VeXoa(ToaDo);

        return (ThoiGianSong > 0);
    }
};


#endif