#pragma once
#include "row.h"
class rect : public row
{
public:
	rect();
	rect(float sizeA, float sizeB);
	void update();

protected:
	void rotate();
	float angle[2];
	bool check;
};

