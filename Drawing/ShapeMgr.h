#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector <DrawingShape*> vec; //this is a vector of pointers that point to drawingshape

public:
	ShapeMgr() //we need this constructor? 
	{
		//for debugging purposes, how to we go about this default constructor?
		cout << "The Shapemgr constructor was called" << endl;

	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		//adds a shape to the vector of pointers
		//Shape.h will draw this, this is just sending the info to the shapes

		if (whichShape == ShapeEnum::CIRCLE) //check to see if it is a circle
		{
			Circle tempCircle(pos, color); //initializing the values of a circle
			vec.push_back(&tempCircle); //pushing back the vector, using the address of temp
		}
		else //its a square
		{
			Square tempSquare(pos, color); //initialize the values to a square
			vec.push_back(&tempSquare); //pushing back the vector, using the address of temp
		}


		

	}
	
	
	//function that returns a const referecnce/ptr to its list of shapes, so that DrawingUI can access the list of shapes to draw them
	vector <DrawingShape*> getVector() 
	{
		return vec; 
	}
	//function that returns a const referecnce/ptr to its list of shapes, so that DrawingUI can access the list of shapes to draw them
	
};
