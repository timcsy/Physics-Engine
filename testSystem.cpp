// Test System class
#include "Body.h"
#include "Field.h"
#include <typeinfo>
using namespace Effect;

int main()
{
	Body r;
	Field f;
	System s;
	System *sr=&r;
	System *sf=&f;
	effect(&s,&s);
	effect(&s,&r);
	effect(&r,&s);
	effect(sr,&s);
	effect(&s,sr);
	return 0;
}