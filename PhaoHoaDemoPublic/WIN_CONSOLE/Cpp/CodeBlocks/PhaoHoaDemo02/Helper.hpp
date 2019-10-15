#ifndef _HELPER_
#define _HELPER_


#include <cstdlib>

class Helper
{
public:
    static int GetRandom(int maxValueUpper)
    {
        return std::rand() % maxValueUpper;
    }


    static int GetRandom(int minValue, int maxValueUpper)
    {
        return minValue + std::rand() % (maxValueUpper - minValue);
    }
};


#endif