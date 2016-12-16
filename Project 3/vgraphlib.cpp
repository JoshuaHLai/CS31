#include <iostream>
#include <string>
#include <cctype>
#include "vgraphlib.h"

using namespace std;

//================================================================================
//	bool cmd_canvas_setup does the following:
//	1. the function will captures and returns the user input for height and width
//	2. it will check if the user input falls within the parameters
//	3. the function will return true if everything is correct
//================================================================================
bool cmd_canvas_setup(int & height, int & width)
{
	bool returnValue = true;

	//prompts user to input canvas height and width
	cout << "Input the canvas height you'd like to use: ";
	cin >> height;
	cout << "Input the canvas width you'd like to use: ";
	cin >> width;

	//checks if canvas height falls within the range
	if (height < 0 || height > CANVAS_HEIGHT)
	{
		cout << "Height must be between 0 and 40" << endl;
		returnValue = false;
	}

	//checks if canvas width falls within the range
	if (width < 0 || width > CANVAS_WIDTH)
	{
		cout << "Width must be between 0 and 50" << endl;
		returnValue = false;
	}

	return returnValue;
}

//==============================================================================================
//	bool cmd_pen_selection does the following:
//	1. the function will captures and returns the user input for the character as the pen type
//	2. it will check if the user input is a printable character
//	3. the function will return true if everything is correct
//==============================================================================================
bool cmd_pen_selection(char & pen)
{
	//prompt user to input pen type
	cout << "Input the character you'd like to use: ";
	cin >> pen;

	//checks if the input character is printable
	if (isprint(pen) == false)
	{
		cout << "Pen must be printable character." << endl;
		return false;
	}

	return true;
}

//=========================================================================================
//	bool cmd_draw_vertical_line does the following:
//	1. the function will draw a vertical line based off of the pen type and picture height
//	2. returns true
//=========================================================================================
bool cmd_draw_vertical_line(char pen, int height)
{
	int i;

	for (i = 1; i <= height; i++)
	{
		cout << pen << endl;
	}

	//the extra endline is used to create space between the drawing and 
	//the menu pop-up so the display is more readable to the user
	cout << endl;

	return true;
}

//==========================================================================================
//	bool cmd_draw_horizontal_line does the following:
//	1. the function will draw a horizontal line based off of the pen type and picture width
//	2. returns true
//==========================================================================================
bool cmd_draw_horizontal_line(char pen, int width)
{
	int i;

	for (i = 1; i <= width; i++)
	{
		cout << pen;
	}

	cout << endl;

	//the extra endline is used to create space between the drawing and 
	//the menu pop-up so the display is more readable to the user
	cout << endl;

	return true;
}

//===============================================================================
//	bool cmd_draw_rectangle does the following:
//	1. the function will draw a rectangle based off of the pen type, shape type,
//		picture height, and picture width
//	2. returns true
//===============================================================================
bool cmd_draw_rectangle(char pen, char type, int height, int width)
{
	int i;
	int j;

	switch (type)
	{
	case 'S':
	case 's':
		for (i = 1; i <= height; i++)
		{
			for (j = 1; j <= width; j++)
				cout << pen;
			cout << endl;
		}
		break;
	case 'H':
	case 'h':
		for (i = 1; i <= height; i++)
		{
			if (i == 1 || i == height)  //prints solid line
			{
				for (j = 1; j <= width; j++)
					cout << pen;
				cout << endl;
			}
			else    //prints hollow line of shape
			{
				for (j = 1; j <= width; j++)
				{
					if (j == 1 || j == width)
						cout << pen;
					else
						cout << " ";
				}
				cout << endl;
			}
		}
		break;
	default:
		cout << "Type must be H/h or S/s" << endl;
		break;
	}

	//the extra endline is used to create space between the drawing and 
	//the menu pop-up so the display is more readable to the user
	cout << endl;

	return true;
}

//====================================================================================
//	bool cmd_draw_right_triangle does the following:
//	1. the function will draw a right triangle based off of the pen type, shape type
//		and the picture width
//	2. returns true
//====================================================================================
bool cmd_draw_right_triangle(char pen, char type, int width)
{
	int i;
	int j;

	switch (type)
	{
	case 'S':
	case 's':
		for (i = 1; i <= width; i++)
		{
			for (j = 1; j <= i; j++)
				cout << pen;
			cout << endl;
		}
		break;
	case 'H':
	case 'h':
		for (i = 1; i <= width; i++)
		{
			if (i == width)
			{
				for (j = 1; j <= i; j++)
					cout << pen;
			}
			else
			{
				for (j = 1; j <= i; j++)
				{
					if (j == 1 || j == i)
						cout << pen;
					else
						cout << " ";
				}
			}

			cout << endl;
		}
		cout << endl;

		break;
	default:
		cout << "Type must be H/h or S/s" << endl;
		break;
	}

	//the extra endline is used to create space between the drawing and 
	//the menu pop-up so the display is more readable to the user
	cout << endl;

	return true;
}


//
//This section is for the custom functions that I used:
//


//===========================================================
//	void print_main_menu() does the following:
//	1. the function will print the main menu of the program
//===========================================================
void print_main_menu()
{
	//prints out main menu
	cout << "====================================" << endl;
	cout << "vintage v1.0 - Copyright 2015 Simba" << endl;
	cout << "Make the following selection:" << endl;
	cout << "1 - Set up the canvas" << endl;
	cout << "2 - Select the pen" << endl;
	cout << "3 - Draw the shape" << endl;
	cout << "4 - Exit" << endl;
	cout << "====================================" << endl;
}

//======================================================================
//	int get_picture_height does the following:
//	1. the function will capture the user input for the picture height
//	2. validates that the user input falls within the parameters
//	3. returns the picture height
//======================================================================
int get_picture_height(int canvas_h)
{
	int picture_h;

	//prompt user input for height
	cout << "Input the height: ";
	cin >> picture_h;

	//validating that the input falls within the conditions
	while (picture_h < 0 || picture_h > canvas_h)
	{
		cout << "Height must be between 0 and " << canvas_h << endl;
		cin >> picture_h;
	}

	return picture_h;
}

//======================================================================
//	int get_picture_height does the following:
//	1. the function will capture the user input for the picture width
//	2. validates that the user input falls within the parameters
//	3. returns the picture height
//======================================================================
int get_picture_width(int canvas_w)
{
	int picture_w;

	//prompt user input for width
	cout << "Input the width: ";
	cin >> picture_w;

	//validates the user input within the conditions
	while (picture_w < 0 || picture_w > canvas_w)
	{
		cout << "Width must be between 0 and " << canvas_w << endl;
		cin >> picture_w;
	}

	return picture_w;
}

//====================================================================
//	char get_picture_type() does the following:
//	1. the function will capture the user input for the picture type
//	2. validates that the user input falls within the conditions
//	3. returns the picture type
//====================================================================
char get_picture_type()
{
	char shape_t;

	//prompt user input for shape type (hollow or solid)
	cout << "Input the type: ";
	cin >> shape_t;
	while (shape_t != 'H' && shape_t != 'h' && shape_t != 'S' && shape_t != 's')
	{
		cout << "Type must be H/h or S/s" << endl;
		cin >> shape_t;
	}

	return shape_t;
}