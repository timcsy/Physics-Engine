// Test Vector class
#include "Vector.h"

int main()
{
	Vector a;
	Vector b(1.2,3);
	cout<<a.getX()<<" "<<a.getY()<<" "<<a<<endl;
	a.setXY(4,5.6);
	cout<<a.getX()<<" "<<a.getY()<<" "<<a<<endl;
	cout<<b.getX()<<" "<<b.getY()<<" "<<b<<endl;
	b.setX(10); b.setY(15.8);
	cout<<b.getX()<<" "<<b.getY()<<" "<<b<<endl;
	
	Vector c(3,4);
	Vector zero(0,0);
	cout<<c.length()<<" "<<zero.length()<<endl;
	cout<<c.unit()<<" "<<zero.unit()<<endl;
	Vector d(-1,0);
	cout<<c.angle(d)/3.14159*180<<" "<<c.angle(zero)<<endl;
	
	Vector p(1,2);
	Vector q(3,4);
	cout<<"pxq = "<<p.cross(q)<<endl;
	
	Vector e(10,0);
	cout<<c.projectVector(e)<<" "<<c.projectVector(zero)<<endl;
	cout<<c.projectLength(e)<<" "<<c.projectLength(zero)<<endl;
	cout<<c.perp()<<" "<<zero.perp()<<endl;
	
	Vector A(1,2);
	Vector B(3,4);
	double C = 0.1;
	int n = 2;
	cout<<"A + B ="<<A+B<<endl;
	cout<<"A - B ="<<A-B<<endl;
	cout<<"C * A ="<<C*A<<endl;
	cout<<"A * C ="<<A*C<<endl;
	cout<<"n * A ="<<n*A<<endl;
	cout<<"A * n ="<<A*n<<endl;
	cout<<"A * B ="<<A*B<<endl;
	cout<<"A / C ="<<A/C<<endl;
	cout<<"A / n ="<<A/n<<endl;
	cout<<"-A ="<<-A<<endl;
	A+=B;
	cout<<"A += B =>"<<A<<endl;
	A-=B;
	cout<<"A -= B =>"<<A<<endl;
	A*=n;
	cout<<"A *= n =>"<<A<<endl;
	A/=n;
	cout<<"A /= n =>"<<A<<endl;
	A*=C;
	cout<<"A *= C =>"<<A<<endl;
	A/=C;
	cout<<"A /= C =>"<<A<<endl;
	
	cout<<"A == B =>"<<(A==B)<<endl; // must plus ()
	cout<<"A != B =>"<<(A!=B)<<endl;
	Vector D(1,2);
	cout<<"A == D =>"<<(A==D)<<endl;
	cout<<"A != D =>"<<(A!=D)<<endl;
	
	cout<<A[0]<<" "<<A[1]<<endl;
	A=B;
	cout<<A<<endl;
	
	return 0;
}