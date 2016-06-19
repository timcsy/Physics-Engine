#include "Body.h"
using namespace Effect;

void Body::changeState()
{
	cm += (prevSystem->v) * dt;
	angle += (prevSystem->w) * dt;
}