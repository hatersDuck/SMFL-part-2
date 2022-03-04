#pragma once
#include "row.h"
class triengale : public row
{
public:
	triengale();
	void update(int, int);
private:
	void rotate();

	float r[3], angle[3];
};

