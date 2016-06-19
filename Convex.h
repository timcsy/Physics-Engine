

#ifndef CONVEX_H
#define CONVEX_H

#include "Shape.h"
#include <vector>
using namespace std;

class ProjectInfo;

class Convex : public Shape
{
	public:
		friend IntersectInfo Intersect::intersect(Convex * Ca, Convex * Cb);
		friend IntersectInfo Intersect::intersect(Shape * Sa, Convex * Cb);
		friend IntersectInfo Intersect::intersect(Convex * Ca, Shape * Sb);
		ProjectInfo project(const Vector & Axis);
		
	protected:
		vector<Vector> vertex; // store vertices of the convex
		int firstVertex; // store the first vertex among vertices
		ProjectInfo projectInfo;
};

class ProjectInfo
{
	public:
		int minVertex;
		double minProj;
		int maxVertex;
		double maxProj;
}

#endif