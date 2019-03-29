#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color currentColor; //holds the current color
	ShapeEnum currentShape; //holds the current shape

public:
	//======================================================
	// function name: SettingsMgr
	// parameters: 
	// Color startingColor - we pass the color to set the default
	// ShapeEnum Startingshape -  we pass the ShapeEnum to set the default shape
	// return type: none, its a constructor
	//======================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		currentColor = startingColor; //sets the current to the starting color
		currentShape = startingShape; //sets the current to the starting color
	}
	
	//======================================================
	// function name: getCurColor()
	// parameters: none
	// return type: Color, we need the current color
	//======================================================
	Color getCurColor()
	{
		return currentColor; // returns the current color
	}

	//======================================================
	// function name: getCurShape()
	// parameters: none
	// return type: ShapeEnum, we need the current color
	//======================================================
	ShapeEnum getCurShape()
	{
		return currentShape; // returns the shape 
	}

	//======================================================
	// function name: setCurColor(Color otherColor)
	// parameters: Color otherColor- sets the current color
	// return type: none, its a void
	//======================================================
	void setCurColor(Color otherColor)
	{
		currentColor = otherColor;
	}
	
	//======================================================
	// function name: setCurShape(ShapeEnum shape)
	// parameters: ShapeEnum shape- sets the 
	// return type: none, its a void
	//======================================================
	void setCurShape(ShapeEnum shape)
	{
		currentShape = shape;
	}


	//======================================================
	// function name: readSettings(fstream& file)
	// parameters: fstream& file- we pass the file by reference 
	// return type: none, its a void
//======================================================
	//reading the settings into the binary file (if it exists)
	void readSettings(fstream& file)
	{
		//read the color number from a file

		int colorNumber; //an int to hold the integer when we read the data

		file.read(reinterpret_cast<char *>(&colorNumber), sizeof(int));
		
		Color aColor(colorNumber); //use the number to change it to a color

		currentColor = aColor; //set that color as the current color

		//now reading for the shape button
		//we dont have to transform the shape because its a number (Enumerator)
		file.read(reinterpret_cast<char*> (&currentShape), sizeof(currentShape));
		
	}
	
	
	
	//======================================================
	// function name: writeSettings
	// parameters: fstream& file- we pass the file by reference
	// return type: none, its a void
	//======================================================
	//writing the setting from a binary file, or do we do this in main?
	void writeSettings(fstream& file)
	{
		//represent the color as an integer
		unsigned colorNumber = currentColor.toInteger();
		//write the data for colornumber and currentshape
		file.write(reinterpret_cast<char *> (&colorNumber), sizeof(colorNumber));

		file.write(reinterpret_cast<char *> (&currentShape), sizeof(currentShape));


	}


};
