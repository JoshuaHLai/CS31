//
// CS 31 Winter 2015
// File: HW #5 - Get to the Point!
// Author:
// SID:
// Date: 2015-3-09
// Version 1.0
// Description: Project #5 for Computer Science 31
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>


using namespace std;

const int PHB_LIST_LENGTH = 1000;
const int PHB_LIST_MAX_VAL = 100;
const int PHB_LIST_MAGIC_NUM = 31;

enum PHB_LIST_ORDER
{
	PHB_LIST_ORDER_INC,
	PHB_LIST_ORDER_DEC
};

bool PHB_list_check(const int *in_list, const int *in_len, int *out_list);
bool PHB_list_delete_duplicates(int *in_list, const int *len);
bool PHB_list_fill_up(int *list, const int *len);
bool PHB_list_reverse(int *list, const int *len);
bool PHB_list_sort(int *list, const int *len, const PHB_LIST_ORDER *ord);
bool PHB_list_sum_31(const int *in_list, const int *in_len, int *out_list, int *out_len);

//Function #1
//==============================================================================
//	bool PHB_list_check(const int *in_list, const int *in_len, int *out_list)
//		does the following:
//	1. The function will check the values in the PHB List are between 1 and 100.
//	2. If all the numbers fall when in the range, the function will return 
//		true
//	3. If any number falls outside the range, the function will return false and
//		specify the location in the list.
//==============================================================================
bool PHB_list_check(const int *in_list, const int *in_len, int *out_list)
{
	//Keeps count of the size of the out_list
	int j = 0;

	//Checks if an empty list is passed in
	if (*in_len < 1)
		return false;

	bool returnValue = true;

	//Loops through the list that was passed in
	for (int i = 0; i < *in_len; i++)
	{
		//Checks if each element falls with in the parameters
		if (*(in_list + i) < 1 || *(in_list + i) > 100)
		{
			//Moves the location of the invalid data element into the out_list and the return false.
			returnValue = false;
			*(out_list + j) = i;
			j++;
		}
	}

	return returnValue;
}

//Function #2
//==============================================================================
//	bool PHB_list_delete_duplicates(int *in_list, const int *len)
//		does the following:
//	1. The function will check the values in the PHB List and see if there are
//		any duplicates in the list.
//	2. If there are duplicates in the list, it will delete them and point to a 
//		new list that contains the original elements without the duplicated
//		elements.
//==============================================================================
bool PHB_list_delete_duplicates(int *in_list, const int *len)
{
	int indexOfList = 0;
	int listSize = *len;

	int result[PHB_LIST_LENGTH];		//Local array that stores the end result
	int lengthOfResult = 0;				//Length of the resulting array

	bool duplicate;						//Boolean value to check whether or not there is a duplicate

	//ERROR TRAPPING
	for (int i = 0; i < *len; i++)
	{
		if (in_list[i] < 0)
			return false;
	}

	//Loops through the list to see if there are duplicate numbers
	for (int i = 0; i < listSize; i++)
	{
		//Initialize to false first in order to know that there are no duplicates in the first element
		duplicate = false;

		//Loop through each individual element in the list to check for duplicates.
		//If there is a duplicate, it breaks out of the loop.
		for (int j = 0; j < lengthOfResult; j++)
		{
			if (in_list[i] == result[j])
			{
				duplicate = true;
				break;
			}
		}

		//If there isn't a duplicate, it copies in the value to the resulting array.
		if (duplicate == false)
		{
			result[lengthOfResult] = in_list[i];
			lengthOfResult++;
		}
	}

	//Copies in the non-duplicate values into the original array
	for (int i = 0; i < lengthOfResult; i++)
	{
		in_list[i] = result[i];
	}

	return true;
}

//Function #3
//==============================================================================
//	bool PHB_list_fill_up(int *list, const int *len) does the following:
//	1. The function will change each element of the list into a random number
//		between 1 and 100.
//==============================================================================
bool PHB_list_fill_up(int *list, const int *len)
{
	//ERROR TRAPPING
	for (int i = 0; i < *len; i++)
	{
		if (list[i] < 0)
			return false;
	}

	//Initialize a random number generator and generate a different seed
	srand(static_cast <unsigned int> (time(NULL)));

	//Loops through the list and checks each element
	for (int i = 0; i < *len; i++)
	{
		//Creates a new variable that will generate a random number between 1 and 100.
		int randomNumber = rand() % 100 + 1;

		//Goes through the loop and assigns a random number to each element in the list.
		*(list + i) = randomNumber;
	}
	return true;
}

//Function #4
//==============================================================================
//	bool PHB_list_reverse(int *list, const int *len) does the following:
//	1. The function will analyze the list that was passed in via pointer and 
//		reverse each of the elements in the list, making it backwards.
//==============================================================================
bool PHB_list_reverse(int *list, const int *len)
{
	//ERROR TRAPPING
	for (int i = 0; i < *len; i++)
	{
		if (list[i] < 0)
			return false;
	}

	//Loops through the list that was passed in
	for (int i = 0; i < *len / 2; i++)
	{
		//Variable to reverse the elements in the list
		int reverseElement;

		//Sets the reverseElement to the value of the specified element.
		//After, sets the value of the specified element to its counterpart.
		//Sets the counterpart element to reverseElement, which is the original specified element.
		reverseElement = *(list + i);
		*(list + i) = *(list + *len - 1 - i);
		*(list + *len - 1 - i) = reverseElement;
	}
	return true;
}

//Function #5
//==============================================================================
//	bool PHB_list_sort(int *list, const int *len, const PHB_LIST_ORDER *ord)
//		does the following:
//	1. The function will analyze the list that is passed in and sort the values 
//		of the list in a specified order, whether it would be increasing or
//		decreasing.
//==============================================================================
bool PHB_list_sort(int *list, const int *len, const PHB_LIST_ORDER *ord)
{
	//Error trapping
	for (int i = 0; i < *len; i++)
	{
		if (list[i] < 0)
			return false;
	}

	int i = 0;
	int switchElement;

	if (*ord == PHB_LIST_ORDER_INC)
	{
		while (i < (*len - 1))
		{
			for (i = 0; i < (*len - 1); i++)
			{
				if (list[i + 1] < list[i])
				{
					switchElement = list[i];
					list[i] = list[i + 1];
					list[i + 1] = switchElement;
					break;
				}
			}
		}
	}
	else if (*ord == PHB_LIST_ORDER_DEC)
	{
		while (i < (*len - 1))
		{
			for (i = 0; i < (*len - 1); i++)
			{
				if (list[i + 1] > list[i])
				{
					switchElement = list[i];
					list[i] = list[i + 1];
					list[i + 1] = switchElement;
					break;
				}
			}
		}
	}
	return true;
}

//Function #6
//==============================================================================
//	bool PHB_list_sum_31(const int *in_list, const int *in_len, int *out_list,
//		int *out_len) does the following:
//	1. The function will see if it is possible to generate the number 31 with 
//		5 consecutive elements in the list.
//	2. If it is possible, it returns a list of the numbers that add up to 31 and
//		their positions.  It also returns the length of the outlist.
//==============================================================================
bool PHB_list_sum_31(const int *in_list, const int *in_len, int *out_list, int *out_len)
{
	//Error trapping
	for (int i = 0; i < *in_len; i++)
	{
		if (in_list[i] < 0)
			return false;
	}
	//Checks if an insufficient list is passed in
	if (*in_len < 5)
		return false;

	int i, j, k;

	for (i = 0; i < i < *in_len - 4; i++)
	{
		//In the case of 5 elements
		//1 2 3 4 5
		if (in_list[i] + in_list[i + 1] + in_list[i + 2] + in_list[i + 3] + in_list[i + 4] == 31)
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 2;
			out_list[3] = i + 3;
			out_list[4] = i + 4;
			*out_len = 5;
			break;
		}
		//In the case of 4 elements
		//1 2 3 4
		else if (in_list[i] + in_list[i + 1] + in_list[i + 2] + in_list[i + 3] == 31)
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 2;
			out_list[3] = i + 3;
			*out_len = 4;
			break;
		}
		//1 2 3 5
		else if (in_list[i] + in_list[i + 1] + in_list[i + 2] + in_list[i + 4] == 31)
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 2;
			out_list[3] = i + 4;
			*out_len = 4;
			break;
		}
		//1 2 4 5
		else if ((in_list[i] + in_list[i + 1] + in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 3;
			out_list[3] = i + 4;
			*out_len = 4;
			break;
		}
		//1 3 4 5
		else if ((in_list[i] + in_list[i + 2] + in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 2;
			out_list[2] = i + 3;
			out_list[3] = i + 4;
			*out_len = 4;
			break;
		}
		//2 3 4 5
		else if ((in_list[i + 1] + in_list[i + 2] + in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 2;
			out_list[2] = i + 3;
			out_list[3] = i + 4;
			*out_len = 4;
			break;
		}
		//In the case of 3 elements
		//1 2 3
		else if ((in_list[i] + in_list[i + 1] + in_list[i + 2] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 2;
			*out_len = 3;
			break;
		}
		//1 2 4
		else if ((in_list[i] + in_list[i + 1] + in_list[i + 3] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 3;
			*out_len = 3;
			break;
		}
		//1 2 5
		else if ((in_list[i] + in_list[i + 1] + in_list[i + 4] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			out_list[2] = i + 4;
			*out_len = 3;
			break;
		}
		//1 3 4
		else if ((in_list[i] + in_list[i + 2] + in_list[i + 3] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 2;
			out_list[2] = i + 3;
			*out_len = 3;
			break;
		}
		//1 3 5
		else if ((in_list[i] + in_list[i + 2] + in_list[i + 4] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 2;
			out_list[2] = i + 4;
			*out_len = 3;
			break;
		}
		//1 4 5
		else if ((in_list[i] + in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 3;
			out_list[2] = i + 4;
			*out_len = 3;
			break;
		}
		//2 3 4
		else if ((in_list[i + 1] + in_list[i + 2] + in_list[i + 3] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 2;
			out_list[2] = i + 3;
			*out_len = 3;
			break;
		}
		//2 3 5
		else if ((in_list[i + 1] + in_list[i + 2] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 2;
			out_list[2] = i + 4;
			*out_len = 3;
			break;
		}
		//2 4 5
		else if ((in_list[i + 1] + in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 3;
			out_list[2] = i + 4;
			*out_len = 3;
			break;
		}
		//3 4 5
		else if ((in_list[i + 2] + in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 2;
			out_list[1] = i + 3;
			out_list[2] = i + 4;
			*out_len = 3;
			break;
		}
		//1 2
		else if ((in_list[i] + in_list[i + 1] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 1;
			*out_len = 2;
			break;
		}
		//1 3
		else if ((in_list[i] + in_list[i + 2] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 2;
			*out_len = 2;
			break;
		}
		//1 4
		else if ((in_list[i] + in_list[i + 3] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 3;
			*out_len = 2;
			break;
		}
		//1 5
		else if ((in_list[i] + in_list[i + 4] == 31))
		{
			out_list[0] = i;
			out_list[1] = i + 4;
			*out_len = 2;
			break;
		}
		//2 3
		else if ((in_list[i + 1] + in_list[i + 2] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 2;
			*out_len = 2;
			break;
		}
		//2 4
		else if ((in_list[i + 1] + in_list[i + 3] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 3;
			*out_len = 2;
			break;
		}
		//2 5
		else if ((in_list[i + 1] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 1;
			out_list[1] = i + 4;
			*out_len = 2;
			break;
		}
		//3 4
		else if ((in_list[i + 2] + in_list[i + 3] == 31))
		{
			out_list[0] = i + 2;
			out_list[1] = i + 3;
			*out_len = 2;
			break;
		}
		//3 5
		else if ((in_list[i + 2] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 2;
			out_list[1] = i + 4;
			*out_len = 2;
			break;
		}
		//4 5
		else if ((in_list[i + 3] + in_list[i + 4] == 31))
		{
			out_list[0] = i + 3;
			out_list[1] = i + 4;
			*out_len = 2;
			break;
		}
		//1
		else if ((in_list[i] == 31))
		{
			out_list[0] = i;
			*out_len = 1;
			break;
		}
		//2
		else if ((in_list[i + 1] == 31))
		{
			out_list[0] = i + 1;
			*out_len = 1;
			break;
		}
		//3
		else if ((in_list[i + 2] == 31))
		{
			out_list[0] = i + 2;
			*out_len = 1;
			break;
		}
		//4
		else if ((in_list[i + 3] == 31))
		{
			out_list[0] = i + 3;
			*out_len = 1;
			break;
		}
		//5
		else if ((in_list[i + 4] == 31))
		{
			out_list[0] = i + 4;
			*out_len = 1;
			break;
		}
	}
	return true;
}
