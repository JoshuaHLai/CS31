//
// CS 31 Winter 2015
// File: HW #4 - Hooray to the Songs!
// Author:
// SID:
// Date: 2015-2-24
// Version 1.0
// Description: Project #4 for Computer Science 31
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//Data Structures Used
enum SPI_Class
{
	SPI_PLATIUM = 1,
	SPI_GOLD,
	SPI_SILVER,
	SPI_COPPER,
	SPI_PAPER
};

enum SPI_Change
{
	SPI_CHANGE_NO = 0,
	SPI_CHANGE_UP = 1,
	SPI_CHANGE_DOWN = -1
};

const int TOTAL_NO_SONGS = 1000;

//Function #1
//==============================================================================
//	int computeSPI(SPI_Class spi[], SPI_Change spi_change[], const int votes[],
//		const bool grammy[], int size) does the following:
//	1. The function uses the data structures at the top to rank the specificed
//		song based off of the previous week's data
//	2. Update the spi based off the new data (votes and grammy)for the new week
//	3. Indicate whether or not the spi changed and in what direction
//==============================================================================
int computeSPI(SPI_Class spi[], SPI_Change spi_change[], const int votes[], const bool grammy[], int size)
{
	//Returns -1 if a negative array size is passed in
	if (size < 0)
		return -1;

	//Returns -1 if a negative vote value is passed in
	for (int j = 0; j < size; j++)
	{
		if (votes[j] < 0)
			return -1;
	}

	for (int i = 0; i < size; i++)
	{
		//Save a copy of the old SPI for comparison in change later
		int oldSPI = spi[i];

		if (grammy[i] == true)
		{
			//Platinum is obtained only if the song won a grammy and will not change based on votes
			spi[i] = SPI_PLATIUM;

		}
		else
		{
			if (votes[i] < 500)
				spi[i] = SPI_PAPER;        //The Paper class is won if the song has less than 500 votes
			else if (votes[i] < 2000)
				spi[i] = SPI_COPPER;       //The Copper class is won if the song has more than 500 but less than 2000 votes
			else if (votes[i] < 5000)
				spi[i] = SPI_SILVER;       //The Silver class is won if the song has more than 2000 but less than 5000 votes
			else if (votes[i] >= 5000)
				spi[i] = SPI_GOLD;         //The Gold classs is won if the song has more than 5000 votes
		}

		//Update and indicate whether or not there was a change in the SPI
		if (oldSPI == spi[i])
			spi_change[i] = SPI_CHANGE_NO;
		else if (oldSPI > spi[i])
			spi_change[i] = SPI_CHANGE_UP;
		else if (oldSPI < spi[i])
			spi_change[i] = SPI_CHANGE_DOWN;
	}
	return 0;
}

//Function #2
//==============================================================================
//	int getRankingList(const SPI_Class spi[], SPI_Class spi_class, int songList[]
//		, int size) does the following:
//	1. The function will return a list of song indices based off the SPI Class
//		i.e. return all the songs in the Platinum class
//==============================================================================
int getRankingList(const SPI_Class spi[], SPI_Class spi_class, int songList[], int size)
{
	//Initilize songList so that the calling program does not crash
	//while trying to print the value in songList.  The calling program
	//should be checking for the return value not equal to -1
	//before printing.  Just in case, it is taken care of in the function
	songList[0] = -1;

	//Returns -1 if a negative array size is passed in
	if (size < 0)
		return -1;

	//This variable is the counter for songList
	int j = 0;

	//This loop will bring out the songs in the indices into the songList
	for (int i = 0; i < size; i++)
	{
		if (spi[i] == spi_class)
		{
			songList[j] = i;
			j++;
		}
	}

	//This line is to indicate that there is no more useful data in the array
	songList[j] = -1;

	return 0;
}

//Function #3
//==============================================================================
//	int getChangeList(const SPI_Change spi_change[], SPI_Change an_spi_change, 
//		int songList[], int size) does the following:
//	1. The function will return a list of the songs SPI changes in a certain class
//		i.e. return all the songs with SPI changes in the Platinum class
//==============================================================================
int getChangeList(const SPI_Change spi_change[], SPI_Change an_spi_change, int songList[], int size)
{
	//Initilize songList so that the calling program does not crash
	//while trying to print the value in songList.  The calling program
	//should be checking for the return value not equal to -1
	//before printing.  Just in case, it is taken care of in the function
	songList[0] = -1;

	//Returns -1 if a negative array size is passed in
	if (size < 0)
		return -1;

	//This variable is the counter for songList
	int j = 0;

	//This loop will bring out the songs with a change in the SPI
	//of a specific song index into the songList
	for (int i = 0; i < size; i++)
	{
		if (spi_change[i] == an_spi_change)
		{
			songList[j] = i;
			j++;
		}
	}

	//This line is to indicate that there is no more useful data in the array
	songList[j] = -1;

	return 0;
}

//Function #4
//==============================================================================
//	int getGrammyList(const bool grammy[], int songList, int size) does the
//		following:
//	1. The function will return a list of the songs that won a 2015 Grammy
//		Award
//==============================================================================
int getGrammyList(const bool grammy[], int songList[], int size)
{
	//Initilize songList so that the calling program does not crash
	//while trying to print the value in songList.  The calling program
	//should be checking for the return value not equal to -1
	//before printing.  Just in case, it is taken care of in the function
	songList[0] = -1;

	//Returns -1 if a negative array size is passed in
	if (size < 0)
		return -1;

	//This variable is the counter for songList
	int j = 0;

	//This loop will bring out the songs that won a grammy into
	//the songList.
	for (int i = 0; i < size; i++)
	{
		if (grammy[i] == true)
		{
			songList[j] = i;
			j++;
		}
	}

	//This line is to indicate that there is no more useful data in the array
	songList[j] = -1;

	return 0;
}

//Function #5
//==============================================================================
//	int merge(const string a1[], int size1, const string a2[], int size2, 
//		string result[], int size) does the following:
//	1. The function will combine two arrays into a single array and sort them
//		alphabetically backwards.
//==============================================================================
int merge(const string a1[], int size1, const string a2[], int size2, string result[], int size)
{
	int i = 0, j = 0, k = 0;            //i goes with a1	j goes with a2		k goes with result

	//Error trapping
	int m;

	//Checks if the first array is placed in alphabetical order backwards
	for (m = 0; m < size1 - 1; m++)
		if (strcmp(a1[i].c_str(), a1[i + 1].c_str()) < 0)
			return -1;

	//Checks if the second array is placed in alphabetical order backwards
	for (m = 0; m < size2 - 1; m++)
		if (strcmp(a2[i].c_str(), a2[i + 1].c_str()) < 0)
			return -1;

	//Returns -1 if a negative array size is passed in
	if (size1 < 0 || size2 < 0 || size < 0)
		return -1;

	//Returns -1 if the size of the two arrays is bigger than the final array
	if (size1 + size2 > size)
		return -1;

	//The while loop will break when one of the arrays is used up
	while (i < size1 && j < size2)
	{
		//Converts the string into a C-String and compares the strings
		//Places the elements in alphabetical order backwards into
		//a new array
		if (strcmp(a1[i].c_str(), a2[j].c_str()) > 0)
		{
			result[k] = a1[i];
			i++;
		}
		else
		{
			result[k] = a2[j];
			j++;
		}
		k++;
	}

	//Moves the remainder of the array into the new array
	if (i < size1)
	{
		for (int m = i; m < size1; m++)
		{
			result[k] = a1[m];
			k++;
		}
	}
	else if (j < size2)
	{
		for (int m = j; m < size2; m++)
		{
			result[k] = a2[m];
			k++;
		}
	}

	return k;
}

//Function #6
//==============================================================================
//	int deleteDuplicates(string a[], int size) does the following:
//	1. The function will delete any strings that are repeated
//		consecutively in the array
//==============================================================================
int deleteDuplicates(string a[], int size)
{
	//Returns -1 if a negative array size is passed in
	if (size < 0)
		return -1;

	string song[TOTAL_NO_SONGS];
	song[0] = a[0];

	int j = 1;

	//Overwrite any repeated consecutive data 
	for (int i = 0; i < size - 1; i++)
	{
		if (a[i] != a[i + 1])
		{
			song[j] = a[i + 1];
			j++;
		}
	}

	//Moves what is left of the original array into a new array
	for (int i = 0; i < j; i++)
	{
		a[i] = song[i];
	}

	return j;
}

//Function #7
//==============================================================================
//	int moveToStart(string a[], int n, int loc) does the following:
//	1. The function will move the specificed element in the array to the
//		beginning of the array.
//==============================================================================
int moveToStart(string a[], int n, int loc)
{
	//Returns -1 if a negative array size is passed in
	if (n < 0)
		return -1;

	//Returns -1 if the location passed in is negative
	if (loc < 0)
		return -1;

	//Saves the value of the original element that is to be moved
	//to the first element in the array
	string saved_index = a[loc];

	int i = loc;

	//Shifts the elements into a new spot on the right
	//Replaces the first element with the element chosen
	//to be moved to the front
	while (i >= 1)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = saved_index;

	return loc;
}

//Function #8
//==============================================================================
//	int moveToEnd(string a[], int n, int loc) does the following:
//	1. The function will move the specificed element in the array to the
//		end of the array.
//==============================================================================
int moveToEnd(string a[], int n, int loc)
{
	//Returns -1 if a negative array size is passed in
	if (n < 0)
		return -1;

	//Returns -1 if the location passed in is negative
	if (loc < 0)
		return -1;

	//Saves the value of the original element that is to be moved
	//to the first element in the array
	string saved_index = a[loc];

	//Moves the elements to the left by overwriting it and replacing it
	for (int i = loc; i < n - 1; i++)
		a[i] = a[i + 1];

	a[n - 1] = saved_index;

	return loc;
}
