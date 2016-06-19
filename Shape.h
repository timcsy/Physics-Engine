

#ifndef SHAPE_H
#define SHAPE_H

#include "Intersect.h"
#include "Vector.h"
using namespace Intersect;

class Shape
{
	public:
		friend IntersectInfo Intersect::intersect(Shape * Sa, Shape * Sb); // check if intersect
		virtual density();
		virtual area();
		virtual mass();
		virtual I();
};

#endif