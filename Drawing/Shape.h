#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

//creating a struct that holds the information about the shape and work with the bin file
struct ShapeInfo
{
	Color color; //a color object
	Vector2f position; //a vector2f object to save the position
	ShapeEnum whichshape; //a ShapEnum that keeps track of the shape


};


// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeInfo shape; //a ShapeInfo object

public:
	
	//two polymorphic functions
	//two pure virtual functions
	virtual void draw(RenderWindow&) = 0;
	virtual ShapeInfo getRecord() = 0;

};

// add Circle, Square classes below. These are derived from DrawingShape
//both circle and square are derived

class Circle : public DrawingShape
{

private:
	CircleShape circle; //a circleshape object 
	ShapeInfo shape; //a ShapeInfo struct object

public:
	//======================================================
	// function name: Circle
	// parameters:
	// Vector2f pos- pass the position of the circle
	// Color color- passing the color of the circle
	// return type: none, its a constructor
	//======================================================
	Circle(Vector2f pos, Color color)
	{
		//setting the fill color and the position
		circle.setFillColor(color);
		circle.setPosition(pos);
		circle.setRadius(10); //setting the brush radius ourselves

		//putting the data into the struct 
		shape.color = color;
		shape.position = pos;
		shape.whichshape = ShapeEnum::CIRCLE; 

	}
	
	//======================================================
	// function name: draw
	// parameters:
	// Renderwindow&- passing the renderwindow by reference
	// return type: none, its a void
	//======================================================
	void draw(RenderWindow& win)
	{
		win.draw(circle); //one liner that draws the circle
	}
	
	//======================================================
	// function name: getrecord
	// parameters:none
	// return type:ShapeInfo- we want to get the struct of info
	//======================================================
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

		//setting the fill color and position
		square.setFillColor(color);
		square.setPosition(pos);
		square.setSize(size); //setting the size of the brush
	
		//putting the data into the struct 
		shape.color = color;
		shape.position = pos;
		shape.whichshape = ShapeEnum::SQUARE;
	
	}
	
	//======================================================
	// function name: draw
	// parameters:
	// Renderwindow&- passing the renderwindow by reference
	// return type: none, its a void
	//======================================================
	void draw(RenderWindow& win)
	{
		win.draw(square); //one liner that draws the circle
	}
	
	
	//======================================================
	// function name: getrecord
	// parameters:none
	// return type:ShapeInfo- we want to get the struct of info
	//======================================================
	ShapeInfo getRecord()
	{
		return shape;
	}

};


