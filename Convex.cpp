#include "Convex.h"

ProjectInfo Convex::project(const Vector & Axis)
{
	int& minVertex = projectInfo.minVertex;
	double& minProj = projectInfo.minProj;
	int& maxVertex = projectInfo.maxVertex;
	double& maxProj = projectInfo.maxProj;
	double proj = vertex[firstVertex].projectLength(Axis);
	minVertex = firstVertex;
	minProj = proj;
	maxVertex = firstVertex;
	maxProj = proj;
	for(int i = 1; i < vertex.size(); i++)
	{
		point = (i+firstVertex)%vertex.size();
		proj = vertex[(i+firstVertex)%vertex.size()].projectLength(Axis);
		if(proj < minProj)
		{
			minProj = proj;
			minVertex = point;
		}
		if(proj > maxProj)
		{
			maxProj = proj;
			maxVertex = point;
		}
	}
	return projectInfo;
}
