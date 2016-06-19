

#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <iostream>
#include "Effect.h"
using namespace std;

class System
{
	public:
		virtual void changeState(); // with time increases, how will the state of System change?
		//effect should be friend and define outside, using dynamic_cast<type_id>
		//peremeter and argument can't cast because it has already up-casted to parent class and view as parent class without using virtual syntex
		friend void Effect::effect(System * Sa, System * Sb); // how can Sa effect Sb
		friend void Effect::effect(Body * Ba, System * Sb);
		friend void Effect::effect(System * Sa, Body * Bb);
		friend void Effect::effect(Field * Fa, System * Sb);
		friend void Effect::effect(System * Sa, Field * Fb);
		
		virtual void add(System * S);
		virtual void changePrev();
		
	protected:
		vector<System*> subSystem; // to store sub systems belong to this system
		double systemTime;
		double dt;
		System * prevSystem;
		bool isTopSystem;
};

#endif