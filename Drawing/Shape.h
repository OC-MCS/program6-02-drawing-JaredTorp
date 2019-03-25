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
	
	virtual void draw() = 0;
	
	
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
	Circle(Vector2f pos, Color color)
	{
		circle.setFillColor(color);
		circle.setPosition(pos);
		circle.setRadius(10); //setting the brush radius ourselves
	}
	void draw()
	{
		win.draw(circle); //one liner that draws the circle
	}
	
};

class Square : public DrawingShape
{

private:
	RectangleShape square;

public:
	Square(Vector2f pos, Color color)
	{
		Vector2f size(10, 10); //setting the brush size

		square.setFillColor(color);
		square.setPosition(pos);
		square.setSize(size); //setting the size of the brush
	}

	//RecordData

};


