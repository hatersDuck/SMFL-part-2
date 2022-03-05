#pragma once
#include "point.h"
class ellipse :
    public point
{
public:
    ellipse();
    void update();    
private:
    float b, p, c;
};

