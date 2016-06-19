#include "Shape.h"
#include "Convex.h"
#include "Intersect.h"
using namespace Intersect;

IntersectInfo Intersect::intersect(Shape * Sa, Shape * Sb)
{
	if(Convex *Ca = dynamic_cast<Convex*>(Sa))
	{
		if(Convex *Cb = dynamic_cast<Convex*>(Sb))
		{
			intersect(Ca,Cb);
		}
		else
		{
			intersect(Ca,Sb);
		}
    }
	else if(Convex *Cb = dynamic_cast<Convex*>(Sb))
	{
        intersect(Sa,Cb);
    }
	else
	{
		//cout<<"Sa,Sb"<<endl;
	}
}

IntersectInfo Intersect::intersect(Convex * Ca, Convex * Cb)
{
	//cout<<"Ca,Cb"<<endl;
	vector<Vector> Axis;
	for(int i = 0; i < Ca.vertex.size(); i++)
	{
		int CaSize = Ca.vertex.size();
		Vector newAxis = Ca.vertex[(i+Ca.firstVertex+1)%CaSize] - Ca.vertex[(i+Ca.firstVertex)%CaSize];
		bool notRepeated = true;
		for(int j = 0; j < Axis.size(); j++)
		{
			if(newAxis == Axis[j])
			{
				notRepeated = false;
				break;
			}
		}
		if(notRepeated)
		{
			Axis.push_back(newAxis);
			Ca.project(newAxis);
			Cb.project(newAxis);
			if(Ca.projectInfo.maxProj >= Cb.projectInfo.minProj && Cb.projectInfo.maxProj >= Ca.projectInfo.minProj)
			{
				//intersect and overlap
				
			}
		}
	}
}

IntersectInfo Intersect::intersect(Shape * Sa, Convex * Cb)
{
	//cout<<"Sa,Cb"<<endl;
}

IntersectInfo Intersect::intersect(Convex * Ca, Shape * Sb)
{
	//cout<<"Ca,Sb"<<endl;
}