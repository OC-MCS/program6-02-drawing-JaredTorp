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
	
	//======================================================
	// function name: ShapeMgr
	// parameters:none
	// return type:none, its a default constructor that does nothing
	//======================================================
	ShapeMgr()  
	{
		//we cant do anything because we dont know the size of the vector
	}

	//======================================================
	// function name: addShape
	// parameters:
	// Vector2f pos- pass the position
	//ShapeEnum whichShape- we need to pass which shape, whether its a circle or square
	//Color color- we pass the color 
	// return type: none, its a void
	//======================================================
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
	
	
	//======================================================
	// function name: getVector()
	// parameters:none
	// return type:Vector <DrawingShape*>- we need to get the vector of pointers to drawingshape
	//======================================================
	vector <DrawingShape*> getVector()  const
	{
		return vec; 
	}

	
	//======================================================
	// function name: readFile
	// parameters:fstream& file, we pass the file by reference
	// return type:none, its a void
	//======================================================
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

	//======================================================
	// function name: writeFile
	// parameters:fstream& file, we pass the file by reference
	// return type:none, its a void
	//======================================================
	void writeFile(fstream& file)
	{
		//create temporary ShapeInfo
		ShapeInfo temp;

		for (unsigned i = 0; i < vec.size(); i++)
		{
			temp.color = vec[i]->getRecord().color; //put the color into the temp ShapeInfo
			temp.position = vec[i]->getRecord().position;//put the position into the temp ShapeInfo
			temp.whichshape = vec[i]->getRecord().whichshape;//put the shape into the temp ShapeInfo
			
			file.write(reinterpret_cast<char *>(&temp), sizeof(ShapeInfo)); //write it to the file
		}
		

	}

	

	
};
