#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

//consts for the circles and squares
const int RADIUS = 20; //const radius for the circle buttons

class SettingsUI
{
private:
		//all of the buttons
		CircleShape blueBtn;
		CircleShape redBtn;
		CircleShape greenBtn;
		CircleShape circleBtn;
		RectangleShape squareBtn;
		SettingsMgr* mgrPtr; //settings manager pointer

public:
	//======================================================
	// function name: SettingsUI
	// parameters: SettingsMgr *mgr- we pass a pointer to a settingMgr 
	// return type: none, constructor
	//======================================================
	SettingsUI(SettingsMgr *mgr)
	{
		//setting the mgrPtr to point to wherever mgr points to
		mgrPtr = mgr;
		
		//drawing the circles here
		//the blue button 

		Vector2f bluePos(80, 70);
		blueBtn.setPosition(bluePos);
		blueBtn.setRadius(RADIUS);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Transparent);

		//the red button

		Vector2f redPos(80, 140);
		redBtn.setPosition(redPos);
		redBtn.setRadius(RADIUS);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Transparent);

		//the green button

		Vector2f greenPos(80, 210);
		greenBtn.setPosition(greenPos);
		greenBtn.setRadius(RADIUS);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);

		//the button to outline the circle drawing shape

		Vector2f drawPos(80, 400);
		circleBtn.setPosition(drawPos);
		circleBtn.setRadius(RADIUS);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(Color::Transparent);

		//now the square button

		Vector2f sqPos(80, 475);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setFillColor(Color::Transparent);

		
	}

	
	//======================================================
	// function name: draw
	// parameters: RenderWindow& win - we pass the renderwindow object by reference
	// return type: none, its a void
	//======================================================
	void draw(RenderWindow& win)
	{

		//draw the title of the settings
		//load the font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
			

		//title for the selected color
		Text topTitle("Selected Color", font, 25);
		topTitle.setPosition(30, 25);
		win.draw(topTitle);
	
		

		//check to see if the current color is blue
		
		if (mgrPtr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}
		else
		{
			blueBtn.setFillColor(Color::Transparent);
		}

		//draw the blue button
		win.draw(blueBtn);


		

		//check to see if the current color is red
		if (mgrPtr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}
		else
		{
			redBtn.setFillColor(Color::Transparent);
		}

		//draw the Red button
		win.draw(redBtn);


		

		//check to see if the current color is green
		if (mgrPtr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}
		else
		{
			greenBtn.setFillColor(Color::Transparent);
		}

		//draw the green button
		win.draw(greenBtn);



		//text for the selected shape
		Text bottomTitle("Selected Shape", font, 25);
		bottomTitle.setPosition(30, 350);
		win.draw(bottomTitle); //draw the string


		//check to see if the current shape is circle
		if (mgrPtr->getCurShape() == ShapeEnum::CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}
		else
		{
			circleBtn.setFillColor(Color::Transparent);
		}

		win.draw(circleBtn);

		//check to see if the current shape is square
		if (mgrPtr->getCurShape() == ShapeEnum::SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}
		else
		{
			squareBtn.setFillColor(Color::Transparent);
		}

		win.draw(squareBtn);


	}
	
	//======================================================
	// function name: handleMouseUp
	// parameters: Wectorsf mouse- we pass the position of the mouse
	// return type: none, its a void
	//======================================================
	void handleMouseUp(Vector2f mouse)
	{
		//handle the mouse clicks
		
		
		//if the blue button is pressed
		if (blueBtn.getGlobalBounds().contains(mouse)) //mouse is a Vector2f
		{

			mgrPtr->setCurColor(Color::Blue); //setting current color in settingsmgr

		}

		//if the red button is pressed
		if (redBtn.getGlobalBounds().contains(mouse)) 
		{
			mgrPtr->setCurColor(Color::Red);//setting current color in settingsmgr

		}

		//if the green button is pressed
		if (greenBtn.getGlobalBounds().contains(mouse)) 
		{
			mgrPtr->setCurColor(Color::Green);//setting current color in settingsmgr

		}
		
		//if the circle button is pressed
		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurShape(ShapeEnum::CIRCLE);//setting current shape in settingsmgr
		}
		//if the square button is pressed
		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurShape(ShapeEnum::SQUARE);//setting current shape in settingsmgr
		}

	}

	//======================================================
	// function name: die
	// parameters: string msg- we pass the message if failed
	// return type: none, its a void
	//======================================================

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}



};
