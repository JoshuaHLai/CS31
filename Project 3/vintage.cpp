//
// CS 31 Winter 2015
// File: HW #3 - Vintage Graphics
// Author:
// SID:
// Date: 2015-2-3
// Version 1.0
// Description: Homework Assignment #3 for Computer Science 31
//This program will draw various shapes based off of the users desire.  The program
//will take the user input in order to draw the correct shape.
//


#include <iostream>
#include <string>
#include "vgraphlib.h"


using namespace std;

int main()
{
	//Variables
	string userOption;
	int numericUserOption;
	bool canvasSelected = false;
	bool penSelected = false;
	char shapeOption;
	bool returnValue;
	int canvasHeight;
	int canvasWidth;
	char penCharacter;
	int pictureHeight;
	int pictureWidth;
	char shapeType;


	do
	{
		print_main_menu();
		cin >> userOption;
		userOption = numericUserOption;
		switch (numericUserOption)
		{
			//Set up canvas
		case 1:
			returnValue = cmd_canvas_setup(canvasHeight, canvasWidth);
			canvasSelected = returnValue;
			break;
			//Select pen type
		case '2':
			returnValue = cmd_pen_selection(penCharacter);
			penSelected = true;
			break;
			//Draw the shape
		case '3':
			//Checks to see if option 1 has been completed
			if (canvasSelected == false)
			{
				cout << "Canvas must be set up first." << endl;
			}

			//Checks to see if option 2 has been completed
			if (penSelected == false)
			{
				cout << "Pen must be selected first." << endl;
			}

			//Print the shape menu if option 1 and 2 have been completed
			if (canvasSelected == true && penSelected == true)
			{
				do
				{
					cout << "====================================" << endl;
					cout << "vintage v1.0 - Copyright 2015 Simba" << endl;
					cout << "Select the shape you'd like to draw:" << endl;
					cout << "1 - Vertical line" << endl;
					cout << "2 - Horizontal line" << endl;
					cout << "3 - Rectangle" << endl;
					cout << "4 - Right triangle" << endl;
					cout << "5 - Return to Main Menu" << endl;
					cout << "====================================" << endl;
					cin >> shapeOption;
					switch (shapeOption)
					{
						//Vertical Line
					case '1':
						//Get the picture height
						pictureHeight = get_picture_height(canvasHeight);
						//Draw one vertical line
						returnValue = cmd_draw_vertical_line(penCharacter, pictureHeight);
						break;

						//Horizontal line
					case '2':
						//Get the picture width
						pictureWidth = get_picture_width(canvasWidth);
						//Draw one horizontal line
						returnValue = cmd_draw_horizontal_line(penCharacter, pictureWidth);
						break;

						//Rectangle
					case '3':
						//Get shape type
						shapeType = get_picture_type();

						//Get the picture height
						pictureHeight = get_picture_height(canvasHeight);

						//Get the picture width
						pictureWidth = get_picture_width(canvasWidth);

						//Print the rectangle
						returnValue = cmd_draw_rectangle(penCharacter, shapeType, pictureHeight, pictureWidth);
						break;

						//Right Triangle
					case '4':
						//Get picture type
						shapeType = get_picture_type();

						//Get the picture width
						pictureWidth = get_picture_width(canvasWidth);

						//Print the right triangle
						returnValue = cmd_draw_right_triangle(penCharacter, shapeType, pictureWidth);
						break;

						//Return to main menu
					case '5':
						break;

						//Invalid input
					default:
						cout << "Incorrect options. Try again" << endl;
						break;
					}
				} while (shapeOption != '5');
			}

			break;
			//Exit program
		case '4':
			cout << "Thank you. Bye now." << endl;
			return 0;
			break;
		default:
			cout << "Incorrect options. Try again" << endl;
			break;
		}
	} while (numericUserOption != '4');
}
