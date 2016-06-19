

#ifndef BODY_H
#define BODY_H

#include "System.h"
#include "Shape.h"
using namespace std;

class Body : public System
{
	public:
		void changeState(); // with time increases, how will the state of System change?
		friend void Effect::effect(Body * Ba, Body * Bb);
		friend void Effect::effect(Body * Ba, System * Sb);
		friend void Effect::effect(System * Sa, Body * Bb);
		friend void Effect::effect(Body * Ba, Field * Fb);
		friend void Effect::effect(Field * Fa, Body * Bb);
		
	protected:
		Shape *shape; // The shape of the rigid body
		Vector cm; // position of center of mass
		double angle; // state of the rotation angle
		Vector v; // current velocity of center of mass
		double w; // current angular velocity(omega) w.r.t. center of mass
		double e;
		double mus;
		double muk;
};

#endif