#pragma once
#include "stdafx.h"
#include "Transform.h"
#include <math.h>
#include <algorithm>

bool clip(point &A, point &B, point Pmin, point Pmax) {
	double tmin = 0, tmax = 1;
	int pi = 0, qi = 0;
	for(int i =1; i<5; i++)
	{
		switch(i) {
			case 1:
				pi = A.x - B.x;
				qi = A.x - Pmin.x;
				break;
			case 2:
				pi = B.x - A.x;
				qi = Pmax.x - A.x;
				break;
			case 3:
				pi = A.y - B.y;
				qi = A.y - Pmin.y;
				break;
			case 4:
				pi = B.y - A.y;
				qi = Pmax.y - A.y;
				break;
		}
		if(pi == 0)
		{
			if(qi < 0)
				return false;
			continue;
		}
		else
		{
			if(pi > 0)
				tmax = std::min(tmax, (double)qi/pi);
			else
				tmin = std::max(tmin, (double)qi/pi);
			if(tmin > tmax)
				return false;
			continue;
		}
	}

	point An, Bn;
	An.x = A.x + (B.x - A.x)*tmin;
	An.y = A.y + (B.y - A.y)*tmin;
	Bn.x = A.x + (B.x - A.x)*tmax;
	Bn.y = A.y + (B.y - A.y)*tmax;
	A = An;
	B = Bn;
	return true;
}