

#ifndef FIELD_H
#define FIELD_H

#include "System.h"
using namespace std;

class Field : public System
{
	public:
		void changeState(); // with time increases, how will the state of System change?
		friend void Effect::effect(Field * Fa, Field * Fb);
		friend void Effect::effect(Field * Fa, System * Sb);
		friend void Effect::effect(System * Sa, Field * Fb);
		friend void Effect::effect(Field * Fa, Body * Bb);
		friend void Effect::effect(Body * Ba, Field * Fb);
		
	protected:
		
};

#endif