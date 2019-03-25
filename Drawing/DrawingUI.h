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

public:
	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		//draw the canvas
		
		Vector2f canvasPos(230, 2);
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Blue);
		canvas.setOutlineThickness(2);
		canvas.setSize(Vector2f(568, 596));
		canvas.setFillColor(Color::Transparent);

		win.draw(canvas);

		//draw the outline of the settings menu

		Vector2f settPos(2, 2);
		settingsOutline.setPosition(settPos);
		settingsOutline.setOutlineColor(Color::Blue);
		settingsOutline.setOutlineThickness(2);
		settingsOutline.setSize(Vector2f(226, 596));
		settingsOutline.setFillColor(Color::Transparent);

		win.draw(settingsOutline);


	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		//checks to see if the mouse in inside the canvas
		
		bool inCanvas = false; //we only care if the mouse is inside the canvas

		//check to see if the mouse is in the shape of the canvas
		if (canvas.getGlobalBounds().contains(mousePos))
		{
			inCanvas = true;
		}
			

		return inCanvas; // just to make it compile

	}

};

