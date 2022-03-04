#pragma once
#include "point.h"
class ellipse :
    public point
{
public:
    ellipse();
    void update(int w, int h);    
private:
    float b, p, c;
};

