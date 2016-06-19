//2D Vector class

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
using namespace std;

class Vector
{
	public:
		Vector();
		Vector(double _x, double _y);
		
		double getX() const;
		void setX(double _x);
		double getY() const;
		void setY(double _y);
		void setXY(double _x, double _y);
		
		double length() const; // The length of the vector
		Vector unit() const; // unit vector of the vector
		double angle(const Vector & v) const; // count the angle between two vectors
		double cross(const Vector & v) const; //count the scalar cross product
		Vector projectVector(const Vector & v) const; // projection vector w.r.t v
		double projectLength(const Vector & v) const; // projection length w.r.t v
		Vector perp() const; // perpendicular vector(on the right hand side !!
		
		Vector operator+(const Vector & v) const; // Addition
		Vector operator-(const Vector & v) const; // Subtraction
		Vector operator*(double c) const; // Scalar multiplication
		friend Vector operator*(double c,const Vector & v); // Scalar multiplication (It is friend function)
		double operator*(const Vector & v) const; // Dot product
		Vector operator/(double c) const; // Scalar multiplication
		Vector operator-() const; // the inverse addition element
		
		Vector& operator+=(const Vector & v); // define += operator
		Vector& operator-=(const Vector & v); // define -= operator
		Vector& operator*=(double c); // define -= operator, scalar muriplication
		Vector& operator/=(double c); // define /= operator, scalar muriplication
		
		bool operator==(const Vector v) const; // judge if Vectors are equal
		bool operator!=(const Vector v) const; // judge if Vectors not equal
		
		double& operator[](int i); // obtain Vector component by index i(0:x, 1:y)
		Vector& operator=(const Vector & v); // define assignment operator
		
		string toString() const; // convert Vector to string form
		friend ostream& operator<<(ostream& output, const Vector & v); // define output stream (It is friend function)
		
	protected:
		double x; // x component
		double y; // y component
};

#endif