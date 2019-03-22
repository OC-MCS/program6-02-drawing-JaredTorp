#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:

public:
	
	//two polymorphic functions
	//two pure virtual functions
	
	//virtual draw
	//virtual RecordData

	//draw and save function


};

// add Circle, Square classes below. These are derived from DrawingShape
//remember they are derived

class Circle : public DrawingShape
{

private:
	CircleShape circle;

public:


};

class Square : public DrawingShape
{

private:
	RectangleShape square;

public:


};


