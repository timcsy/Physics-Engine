// This file should be included in System.h and its child class .h

#ifndef EFFECT_H
#define EFFECT_H

class System;
class Body;
class Field;

namespace Effect
{
	void effect(System * Sa, System * Sb);
	void effect(Body * Ba, Body * Bb);
	void effect(Body * Ba, System * Sb);
	void effect(System * Sa, Body * Bb);
	void effect(Field * Fa, Field * Fb);
	void effect(Field * Fa, System * Sb);
	void effect(System * Sa, Field * Fb);
	void effect(Body * Ba, Field * Fb);
	void effect(Field * Fa, Body * Bb);
};

#endif