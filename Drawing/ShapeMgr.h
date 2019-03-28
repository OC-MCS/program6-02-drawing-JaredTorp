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
	
	//default constructor
	ShapeMgr()  
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		//adds a shape to the vector of pointers
		//Shape.h will draw this, this is just sending the info to the shapes

		if (whichShape == ShapeEnum::CIRCLE) //check to see if it is a circle
		{
			Circle* circlePtr = new Circle(pos, color); //initializing the values of a circle
			vec.push_back(circlePtr); //pushing back the vector, using the address of temp
		}
		else //its a square
		{
			Square* squarePtr = new Square(pos, color); //initialize the values to a square
			vec.push_back(squarePtr); //pushing back the vector, using the address of temp
		}


		

	}
	
	
	//function that returns a const referecnce/ptr to its list of shapes, so that DrawingUI can access the list of shapes to draw them
	vector <DrawingShape*> getVector()  const
	{
		return vec; 
	}

	
	//function to read the data from a bin file (if there is one)
	void readFile(fstream& file)
	{
		//create a temporary struct
		ShapeInfo temp;
		//create a temp pointer to a circle
		Circle* tempCircle;
		//create a temp pointer to a square
		Square* tempSquare;


		//EOF loop
		while (file.read(reinterpret_cast<char *> (&temp), sizeof(ShapeInfo)))
		{
			//check the shape
			//if it is a circle
			if (temp.whichshape == ShapeEnum::CIRCLE)
			{
				tempCircle = new Circle(temp.position, temp.color); //dynamically allocate a new circle and construct circle
				vec.push_back(tempCircle); //pushing back the vector, using the temp
				
			}
			//it must be a square
			else if (temp.whichshape == ShapeEnum::SQUARE)
			{
				tempSquare = new Square(temp.position, temp.color); // //dynamically allocate a new circle and construct circle
				vec.push_back(tempSquare); //pushing back the vector, using temp

			}




		}

	}

	//function to write the data into the bin file
	void writeFile(fstream& file)
	{
		//create temporary ShapeInfo
		ShapeInfo temp;

		for (unsigned i = 0; i < vec.size(); i++)
		{
			temp.color = vec[i]->getRecord().color;
			temp.position = vec[i]->getRecord().position;
			temp.whichshape = vec[i]->getRecord().whichshape;
			
			file.write(reinterpret_cast<char *>(&temp), sizeof(ShapeInfo));
		}



		

	}

	

	
};
