// This file should be included in Shape.h and its child class .h

#ifndef INTERSECT_H
#define INTERSECT_H

#include "Shape.h"
#include "Convex.h"

class Shape;
class Convex;

namespace Intersect
{
	void intersect(Shape * Sa, Shape * Sb);
	void intersect(Convex * Sa, Convex * Cb);
	void intersect(Convex * Ca, Shape * Sb);
	void intersect(Shape * Sa, Convex * Cb);
	
	class IntersectInfo
	{
		public:
			bool isIntersect;
			Vector axis;
			Vector point;
	}
};

#endif