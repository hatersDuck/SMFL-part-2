#pragma once
#include "row.h"
class triengale : public row
{
public:
	triengale();
	void update();
private:
	void rotate();

	float r[3], angle[3];
};

