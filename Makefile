testVector:testVector.cpp Vector.o
	g++ -o testVector testVector.cpp Vector.o
testSystem:testSystem.cpp Vector.o Shape.o Effect.o System.o Body.o Field.o
	g++ -o testSystem testSystem.cpp Vector.o Shape.o Effect.o System.o Body.o Field.o
Vector.o:Vector.cpp Vector.h
	g++ -c Vector.cpp
Shape.o:Shape.cpp Shape.h
	g++ -c Shape.cpp
Effect.o:Effect.cpp Effect.h
	g++ -c Effect.cpp
System.o:System.cpp System.h
	g++ -c System.cpp
Body.o:Body.cpp Body.h
	g++ -c Body.cpp
Field.o:Field.cpp Field.h
	g++ -c Field.cpp
clean:
	rm testVector *.o