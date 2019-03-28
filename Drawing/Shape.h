#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

//creating a struct that holds the information about the shape




struct ShapeInfo
{
	Color color;
	Vector2f position;
	ShapeEnum whichshape;


};


// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeInfo shape;

public:
	
	//two polymorphic functions
	//two pure virtual functions
	

	virtual void draw(RenderWindow&) = 0;
	virtual ShapeInfo getRecord() = 0;
	
	
	//virtual RecordData
	//save function


};

// add Circle, Square classes below. These are derived from DrawingShape
//remember they are derived

class Circle : public DrawingShape
{

private:
	CircleShape circle;
	ShapeInfo shape;

public:
	Circle(Vector2f pos, Color color)
	{
		circle.setFillColor(color);
		circle.setPosition(pos);
		circle.setRadius(10); //setting the brush radius ourselves

		//putting the data into the struct 
		shape.color = color;
		shape.position = pos;
		shape.whichshape = ShapeEnum::CIRCLE; 

	}
	void draw(RenderWindow& win)
	{
		win.draw(circle); //one liner that draws the circle
	}
	
	//RecordData function that returns a struct of data
	//get Struct
	ShapeInfo getRecord()
	{
		return shape;
	}
	
};

class Square : public DrawingShape
{

private:
	RectangleShape square;
	ShapeInfo shape;

public:

	Square(Vector2f pos, Color color)
	{
		Vector2f size(20, 20); //setting the brush size

		square.setFillColor(color);
		square.setPosition(pos);
		square.setSize(size); //setting the size of the brush
	
		//putting the data into the struct 
		shape.color = color;
		shape.position = pos;
		shape.whichshape = ShapeEnum::SQUARE;
	
	}

	void draw(RenderWindow& win)
	{
		win.draw(square); //one liner that draws the circle
	}
	
	
	//RecordData function that returns a struct of data
	//get Struct
	ShapeInfo getRecord()
	{
		return shape;
	}

};


