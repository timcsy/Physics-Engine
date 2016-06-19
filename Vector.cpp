#include "Vector.h"
#include <cmath>
#include <sstream>

Vector::Vector(): x(0), y(0){}

Vector::Vector(double _x, double _y): x(_x), y(_y){}

double Vector::getX() const
{
	return x;
}

void Vector::setX(double _x)
{
	x = _x;
	return;
}

double Vector::getY() const
{
	return y;
}

void Vector::setY(double _y)
{
	y = _y;
	return;
}

void Vector::setXY(double _x, double _y)
{
	x = _x;
	y = _y;
	return;
}

double Vector::length() const // The length of the vector
{
	return sqrt((*this)*(*this));
}

Vector Vector::unit() const // unit vector of the vector
{
	if(this->length() == 0) return Vector(0,0);
	else return (*this) / this->length();
}

double Vector::angle(const Vector & v) const // count the angle between two vectors
{
	double lengthSquare = this->length() * v.length();
	if(lengthSquare == 0) return 0;
	else return acos(((*this) * v) / lengthSquare);
}

double Vector::cross(const Vector & v) const //count the scalar cross product
{
	return x*(v.y) - y*(v.x);
}

Vector Vector::projectVector(const Vector & v) const // projection vector w.r.t v
{
	if(v.length() == 0) return Vector(0,0);
	return (((*this)*v) / (v*v))*v;
}

double Vector::projectLength(const Vector & v) const // projection length w.r.t v
{
	if(v.length() == 0) return 0;
	return (((*this)*v) / v.length());
}

Vector Vector::perp() const // perpendicular vector(on the right hand side !!
{
	return Vector(y,-x);
}

Vector Vector::operator+(const Vector & v) const // Addition
{
	return Vector(x + v.getX(), y + v.getY());
}

Vector Vector::operator-(const Vector & v) const // Subtraction
{
	return Vector(x - v.getX(), y - v.getY());
}

Vector Vector::operator*(double c) const // Scalar multiplication
{
	return Vector(x * c, y * c);
}

Vector operator*(double c,const Vector & v) // Scalar multiplication (It is friend function)
{
	return Vector(c * v.getX(), c * v.getY());
}

double Vector::operator*(const Vector & v) const // Dot product
{
	return x * v.getX() + y * v.getY();
}

Vector Vector::operator/(double c) const // Scalar multiplication
{
	if(c == 0) throw "Cannot devide 0";
	else return Vector(x / c, y / c);
}

Vector Vector::operator-() const // the inverse addition element
{
	return Vector(-x, -y);
}

Vector& Vector::operator+=(const Vector & v) // define += operator
{
	(*this) = (*this) + v;
	return (*this);
}

Vector& Vector::operator-=(const Vector & v) // define -= operator
{
	(*this) = (*this) - v;
	return (*this);
}

Vector& Vector::operator*=(double c) // define -= operator, scalar muriplication
{
	(*this) = (*this) * c;
	return (*this);
}

Vector& Vector::operator/=(double c) // define /= operator, scalar muriplication
{
	(*this) = (*this) / c;
	return (*this);
}

bool Vector::operator==(const Vector v) const // judge if Vectors are equal
{
	if(x == v.getX() && y == v.getY()) return true;
	else false;
}

bool Vector::operator!=(const Vector v) const // judge if Vectors not equal
{
	return !((*this) == v);
}

double& Vector::operator[](int i) // obtain Vector component by index i(0:x, 1:y)
{
	switch(i)
	{
		case 0: return x;
		case 1: return y;
		default: throw "out of range";
	}
}

Vector& Vector::operator=(const Vector & v) // define assignment operator
{
	x = v.getX();
	y = v.getY();
	return (*this);
}

string Vector::toString() const // convert Vector to string form
{
	string s;
	stringstream ss;
	ss<<"("<<x<<","<<y<<")";
	ss>>s;
	return s;
}
ostream& operator<<(ostream& output, const Vector & v) // define output stream (It is friend function)
{
	output<<v.toString();
	return output;
}