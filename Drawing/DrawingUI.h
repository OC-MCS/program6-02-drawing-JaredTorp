#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	
	RectangleShape canvas; //a rectangle shape canvas
	RectangleShape settingsOutline; // a recatngleshape that will outline the settings
	ShapeMgr* shapePtr; //a pointer to a shapeMgr that will be assigned to the pointer that is passed 

public:

//======================================================
// function name: DrawingUI
// parameters: We pass it the canvas Pos that was passed in main
// return type: none, it is a constructor
//======================================================
	DrawingUI(Vector2f canvasPos)
	{
		//setting the canvas position with the value passed
		//setting the attributes of the canvas
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Blue);
		canvas.setOutlineThickness(2);
		canvas.setSize(Vector2f(568, 596));
		canvas.setFillColor(Color::Transparent);

		

		//draw the outline of the settings menu
		//setting the attributes of the setting outline
		Vector2f settPos(2, 2);
		settingsOutline.setPosition(settPos);
		settingsOutline.setOutlineColor(Color::Blue);
		settingsOutline.setOutlineThickness(2);
		settingsOutline.setSize(Vector2f(226, 596));
		settingsOutline.setFillColor(Color::Transparent);

		
		
	}
//======================================================
// function name: Draw
// parameters: 
//RenderWindow& win- we pass the renderwindow object to draw
//ShapeMgr *mgr- 
// return type: none, its a void
//======================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		//draw the canvas
		win.draw(canvas);
		
		//draw the settings ouline
		win.draw(settingsOutline);

		//get the vector of pointers
		vector <DrawingShape*> copy = mgr->getVector();

		//this loop im trying to draw the entire Vector of pointers to the shapes
		for (int i = 0; i < copy.size(); i++)
		{
			copy[i]->draw(win);
	
			
		}

	}
	//======================================================
	// function name: isMouseInCanvas
	// parameters: Vector2f mousePos, we pass the position of the mouse
	// return type: bool, we check if it is in the canvas
	//======================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		//checks to see if the mouse in inside the canvas
		
		bool inCanvas = false; //we only care if the mouse is inside the canvas

		//check to see if the mouse is in the shape of the canvas
		if (canvas.getGlobalBounds().contains(mousePos) && mousePos.x < 780 && mousePos.y < 580) //so the shape doesnt go off screen
		{
			inCanvas = true;
		}
			
		//return true or false
		return inCanvas; 

	}

};

