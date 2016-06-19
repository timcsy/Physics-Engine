#include "System.h"
#include "Body.h"
#include "Field.h"
#include "Effect.h"
#include <iostream>
using namespace std;
using namespace Effect;

void Effect::effect(System * Sa, System * Sb)
{
	if(Body *Ba = dynamic_cast<Body*>(Sa))
	{
		if(Body *Bb = dynamic_cast<Body*>(Sb))
		{
			effect(Ba,Bb);
		}
		else if(Field *Fb = dynamic_cast<Field*>(Sb))
		{
			effect(Ba,Fb);
		}
		else
		{
			effect(Ba,Sb);
		}
    }
	else if(Field *Fa = dynamic_cast<Field*>(Sa))
	{
		if(Field *Fb = dynamic_cast<Field*>(Sb))
		{
			effect(Fa,Fb);
		}
		else if(Body *Bb = dynamic_cast<Body*>(Sb))
		{
			effect(Fa,Bb);
		}
		else
		{
			effect(Fa,Sb);
		}
    }
    else if(Body *Bb = dynamic_cast<Body*>(Sb))
	{
        effect(Sa,Bb);
    }
	else if(Field *Fb = dynamic_cast<Field*>(Sb))
	{
        effect(Sa,Fb);
    }
	else
	{
		//cout<<"Sa,Sb"<<endl;
		for(int i = 0; i < Sa->subSystem.size(); i++)
		{
			effect(Sa->subSystem[i], Sb);
		}
		for(int i = 0; i < Sb->subSystem.size(); i++)
		{
			effect(Sa, Sb->subSystem[i]);
		}
		for(int i = 0; i < Sa->subSystem.size(); i++)
		{
			for(int j = 0; j != i && j < Sa->subSystem.size(); j++)
				effect(Sa->subSystem[i], Sa->subSystem[j]);
			Sa->subSystem[i].changeState();
		}
		for(int i = 0; i < Sb->subSystem.size(); i++)
		{
			for(int j = 0; j != i && j < Sb->subSystem.size(); j++)
				effect(Sa->subSystem[i], Sb->subSystem[j]);
			Sb->subSystem[i].changeState();
		}
		
	}
}
void Effect::effect(Body * Ba, Body * Bb)
{
	Body &Bap = *(Ba->prevSystem);
	Body &Bbp = *Bb->prevSystem;
	IntersectInfo intersectInfo = intersect(Bap.shape, Bbp.shape);
	if(intersectInfo.isIntersect)
	{
		//collide
		double e = Bbp.e;
		Vector normal = intersectInfo.axis.perp();
		Vector point = intersectInfo.point;
		Vector vb = Bbp.v + Bbp.w;
		Vector vbn = Bbp.v.projectVector(normal);
		Vector vcn = ((Bap.m)*van+(Bbp.m)*vbn)/((Bap.m)+(Bbp.m));
		//consider prev and now
		Vector vbnf = 2*vcn-e*vbn;
		Vector dpbn = (Bbp.m)*(vbnf-vbn);
		w += (point-r).cross(dpbn)/I;
		
		//friction force
		Vector vbt = Bbp.v.projectVector(normal);
	}
}

void Effect::effect(Body * Ba, System * Sb)
{
	cout<<"Ba,Sb"<<endl;
}

void Effect::effect(System * Sa, Body * Bb)
{
	cout<<"Sa,Bb"<<endl;
}

void Effect::effect(Field * Fa, Field * Fb)
{
	cout<<"Fa,Fb"<<endl;
}

void Effect::effect(Field * Fa, System * Sb)
{
	cout<<"Fa,Sb"<<endl;
}

void Effect::effect(System * Sa, Field * Fb)
{
	cout<<"Sa,Fb"<<endl;
}

void Effect::effect(Body * Ba, Field * Fb)
{
	cout<<"Ba,Fb"<<endl;
}

void Effect::effect(Field * Fa, Body * Bb)
{
	cout<<"Fa,Bb"<<endl;
}