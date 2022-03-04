#include "krug.h"

krug::krug() {
	circle.setRadius(radius = 40.f);
	center.x = radius, center.y = radius;
	circle.setOrigin(center);
}
