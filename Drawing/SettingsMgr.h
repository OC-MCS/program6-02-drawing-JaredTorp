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
	Color currentColor;
	ShapeEnum currentShape;

public:

	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		currentColor = startingColor; //sets the current to the starting color
		currentShape = startingShape;
	}

	Color getCurColor()
	{
		return currentColor; // returns the current color
	}


	ShapeEnum getCurShape()
	{
		return currentShape; // returns the shape 
	}


	void setCurColor(Color otherColor)
	{
		currentColor = otherColor;
	}
	
	void setCurShape(ShapeEnum shape)
	{
		currentShape = shape;
	}



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
	
	
	
	
	//writing the setting from a binary file, or do we do this in main?
	void writeSettings(fstream& file)
	{
		//represent the color as an integer
		unsigned colorNumber = currentColor.toInteger();
		

		file.write(reinterpret_cast<char *> (&colorNumber), sizeof(colorNumber));

		file.write(reinterpret_cast<char *> (&currentShape), sizeof(currentShape));


	}






};
