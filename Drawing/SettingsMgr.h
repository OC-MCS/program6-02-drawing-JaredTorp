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
	//default consturctor, do we need one is the main is passing a color?
	SettingsMgr()
	{
		//come back later
	}

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

	
	//loading the setting from a binary file, or do we do this in main?
	void loadsettings()
	{


	}


	//saving the settings into the binary file
	void saveSettings()
	{

	}




};
