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
	//needs a rectangle shape for the canvas
	RectangleShape canvas;
	RectangleShape settingsOutline;
	ShapeMgr* shapePtr;

public:
	DrawingUI(Vector2f canvasPos)
	{
		//setting the canvas position with the value passed
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Blue);
		canvas.setOutlineThickness(2);
		canvas.setSize(Vector2f(568, 596));
		canvas.setFillColor(Color::Transparent);

		

		//draw the outline of the settings menu

		Vector2f settPos(2, 2);
		settingsOutline.setPosition(settPos);
		settingsOutline.setOutlineColor(Color::Blue);
		settingsOutline.setOutlineThickness(2);
		settingsOutline.setSize(Vector2f(226, 596));
		settingsOutline.setFillColor(Color::Transparent);

		
		
	}

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
			copy[i]->draw(win); //Hey the vector is not working
	
			
		}

	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		//checks to see if the mouse in inside the canvas
		
		bool inCanvas = false; //we only care if the mouse is inside the canvas

		//check to see if the mouse is in the shape of the canvas
		if (canvas.getGlobalBounds().contains(mousePos) && mousePos.x < 780 && mousePos.y < 580)
		{
			inCanvas = true;
		}
			

		return inCanvas; 

	}

};

