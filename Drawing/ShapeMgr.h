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
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		//adds a shape to the vector of pointers
		//is the color and the whichshape sent to the constructor of Drawingshape as "nessessary information?"
		//DrawingUI will draw this, this is just sending the info to the shapes
	}
	
	
	//function that returns a const referecnce/ptr to its list of shapes, so that DrawingUI can access the list of shapes to draw them
	 DrawingShape* getVector() 
	{
		/*return vec;*/ //Ask how to fix this lol
	}
	//function that returns a const referecnce/ptr to its list of shapes, so that DrawingUI can access the list of shapes to draw them
	
};
