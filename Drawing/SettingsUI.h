#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

//consts for the circles and squares
const int RADIUS = 20; //const radius for the circle buttons

CircleShape blueBtn;
CircleShape redBtn;
CircleShape greenBtn;
CircleShape circleBtn;
RectangleShape squareBtn;




class SettingsUI
{
private:

public:
	SettingsUI(SettingsMgr *mgr)
	{
		//i think this will take in the defaults and set to fill them?
		//mostly works with the binary file?
		
	}

	
	//function for drawing the menu
	void draw(RenderWindow& win)
	{
		//draw the title of the settings
		//load the font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
			

		//title
		Text topTitle("Selected Color", font, 25);
		topTitle.setPosition(30, 25);
		win.draw(topTitle);
		
		//increment the y position by 25
		//draw the circles here

		//the blue button 
		
		Vector2f bluePos(80, 70);
		blueBtn.setPosition(bluePos);
		blueBtn.setRadius(RADIUS);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		
		//just for the outlined button
		blueBtn.setFillColor(Color::Transparent);

		win.draw(blueBtn);


		//the red button
	
		Vector2f redPos(80, 140);
		redBtn.setPosition(redPos);
		redBtn.setRadius(RADIUS);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);

		//just for the outlined button
		redBtn.setFillColor(Color::Transparent);

		win.draw(redBtn);


		//the green button
		
		Vector2f greenPos(80, 210);
		greenBtn.setPosition(greenPos);
		greenBtn.setRadius(RADIUS);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);

		//just for the outlined button
		greenBtn.setFillColor(Color::Transparent);

		win.draw(greenBtn);



		//text for the selected shape
		Text bottomTitle("Selected Shape", font, 25);
		bottomTitle.setPosition(30, 350);
		win.draw(bottomTitle);

		//draw circle and square here

		//the button to outline the drawing shape
	
		Vector2f drawPos(80, 400);
		circleBtn.setPosition(drawPos);
		circleBtn.setRadius(RADIUS);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);

		//just for the outlined button
		circleBtn.setFillColor(Color::Transparent);

		win.draw(circleBtn);

		//now the square button
		
		Vector2f sqPos(80, 475);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setFillColor(Color::Transparent);

		win.draw(squareBtn);


	}
	
	void handleMouseUp(Vector2f mouse)
	{
		//handle the mouse clicks

		
		//if the blue button is pressed
		if (blueBtn.getGlobalBounds().contains(mouse)) //mouse is a Vector2f
		{
			blueBtn.setFillColor(Color::Blue);
			
			//testing to see if this works, probably not right but oh well


		}
		//if the red button is pressed
		if (redBtn.getGlobalBounds().contains(mouse)) 
		{
			redBtn.setFillColor(Color::Red);

		}
		//if the green button is pressed
		if (greenBtn.getGlobalBounds().contains(mouse)) 
		{
			greenBtn.setFillColor(Color::Green);

		}
		//if the circle button is pressed
		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			circleBtn.setFillColor(Color::White);

		}
		//if the square button is pressed
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			squareBtn.setFillColor(Color::White);

		}

	}

	//die if we need to bail out because of the font error

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}



};
