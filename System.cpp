#include "System.h"
using namespace Effect;

void System::changeState()
{
	for(int i = 0; i < subSystem.size(); i++)
	{
		for(int j = 0; j != i && j < subSystem.size(); j++)
		{
			effect(subSystem[i], subSystem[j]);
		}
		subSystem[i].changeState();
	}
	if(isTopSystem)
	{
		changePrev();
		systemTime += dt;
	}
}

void System::add(System * S)
{
	subSystem.push_back(S);
}

void System::changePrev()
{
	for(int i = 0; i < subSystem.size(); i++)
	{
		subSystem[i].changePrev();
	}
	delete prevSystem;
	prevSystem = this;
}