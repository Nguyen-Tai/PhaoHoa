#ifndef _HAT_BAN_
#define _HAT_BAN_


#include "Hat.hpp"


class HatBan : public Hat
{
public:
    HatBan()
    {

    }


    HatBan(Point toado, Point vantoc, int thoigiansong) : Hat(toado, vantoc, thoigiansong)
    {

    }


    void Ve() override
    {
        circle(ToaDo.X, ToaDo.Y, 3);
    }
};


#endif