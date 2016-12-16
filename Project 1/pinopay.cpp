//
// CS 31 Winter 2015
// File: HW #1 - Show Me the Money
// Author:
// SID:
// Date: 2015-1-19
// Version 1.0
// Description: Project #1 for Computer Science 31
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "pinopay (v1.0)" << endl;
	cout << "Copyright 2015 Pets In-N-Out" << endl;

	//Grab employee name
	string employeeName;
	cout << "Employee Name (First Last): ";
	getline(std::cin, employeeName);

	//Error trapping
	if (employeeName.length() < 1) {
		cout << "You must enter an employee name." << endl;
		return 0;
	}

	//Grab Employee ID
	string employeeID;
	cout << "Employee ID (5-digit): ";
	getline(std::cin, employeeID);

	//Error trapping
	if (employeeID.length() < 1) {
		cout << "You must enter an employee ID." << endl;
		return 0;
	}
	if (employeeID.length() != 5) {
		cout << "You must enter a 5-digit employee ID." << endl;
		return 0;
	}

	//Grab number of hours worked
	double numberOfHours;
	cout << "Number of Hours Worked: ";
	cin >> numberOfHours;

	//Error trapping
	if (numberOfHours < 0) {
		cout << "The number of working hours must be nonnegative." << endl;
		return 0;
	}

	//roundedHours is the final result of numberOfHours rounded to the nearest half hour
	//roundedHours_int stands for the numberOfHours variable in integer form
	double roundedHours;  
	int roundedHours_int; 
	roundedHours_int = numberOfHours;
	if (numberOfHours - roundedHours_int < .5) {
		roundedHours = roundedHours_int;
	}
	else {
		roundedHours = roundedHours_int + .5;
	}

	//Grab pay rate
	double payRate;
	cout << "Pay Rate: $";
	cin >> payRate;

	//Error trapping
	if (payRate < 9) {
		cout << "The pay rate must be at least $9." << endl;
		return 0;
	}

	//Calculate overtime pay
	double overTime;
	double overTimePay;
	if (numberOfHours >= 40) {
		overTime = numberOfHours - 40;
		overTimePay = (payRate * 1.5 * overTime) + (roundedHours * payRate);
	}

	char fedTax;
	cout << "Federal Income Tax Withheld (Y/N): ";
	cin >> fedTax;

	//Error trapping
	if (fedTax != 'Y' && fedTax != 'N') {
		cout << "You must enter either Y or N." << endl;
		return 0;
	}

	//Calculate gross pay and net pay
	double grossPay;
	double netPay;
	grossPay = roundedHours * payRate;
	if (grossPay > 280 && fedTax == 'Y') {
		netPay = grossPay - (.15 * grossPay);
	}
	if (grossPay > 280 && fedTax == 'N') {
		netPay = grossPay;
	}
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	int unionDue;
	unionDue = 15;
	if (grossPay > 150 && fedTax == 'Y') {
		netPay = grossPay - (.15 * grossPay) - unionDue;
	}
	if (grossPay > 150 && fedTax == 'N') {
		netPay = grossPay - unionDue;
	}
	
	cout << employeeName << "'s Weekly Gross Pay: $" << grossPay << endl;
	cout << employeeName << "'s Weekly Net Pay: $" << netPay << endl;
	return 0;
}
