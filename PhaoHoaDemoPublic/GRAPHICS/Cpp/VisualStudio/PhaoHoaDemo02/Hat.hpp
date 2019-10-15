#ifndef _HAT_
#define _HAT_


#include "Point.hpp"
#include "graphics.h"

// hạt sáng
class Hat
{
public:
    Point ToaDo;        // tọa độ
    Point VanToc;       // vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn

    int ThoiGianSong;   // thời gian sống, thời gian sống <= 0 tức là đã chết


    Hat()
    {
        
    }


    Hat(Point toado, Point vantoc, int thoigiansong)
    {
        this->ToaDo = toado;
        this->VanToc = vantoc;
        this->ThoiGianSong = thoigiansong;
    }


    virtual void Ve()
    {
        bar(ToaDo.X - 1, ToaDo.Y - 1, ToaDo.X + 1, ToaDo.Y + 1);
    }


    // trả về true nếu hạt còn sống, trả về false nếu hạt đã chết (hết thời gian sống)
    virtual bool CapNhat()
    {
        if (ThoiGianSong <= 0)
            return false;

        ToaDo.X += VanToc.X;
        ToaDo.Y += VanToc.Y;

        ThoiGianSong--;

        Ve();

        return (ThoiGianSong > 0);
    }
};


#endif