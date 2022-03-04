#pragma once
#include "row.h"
class rect : public row
{
public:
	rect();
	void update(int, int);

protected:
	void rotate();
	float angle[2];
	bool check;
};

