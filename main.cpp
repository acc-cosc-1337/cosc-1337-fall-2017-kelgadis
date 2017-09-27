/// main.cpp 
// Kelly Slane COSC 1337 MW 5:40
/*
Chapter 8
In this assignment students will modify homework 3 to include arrays for payroll data
Students will use arrays as follows:

Create arrays for:
1)employee name
2) hours
3) ot hours
4) regular Rate
5) OT Rate
6) regular pay
7) ot pay
8) gross pay
9) ficassn
10) ficamed
11) fit
12) net pay

Program overview:
1) Collect data for 3 employees and store values in arrays
2) Process employee array data (calculations)
3) Output array data 
*/

#include "Payroll.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main()
{
	enum employee {Hourly = 72, Salary = 83};

	string firstName = "?", lastName = "?", worker = "?", number = "?";
	
	bool checkInput = false;
	
	const int SIZE = 3;
	
	string workforce[SIZE];

	int employeeType[SIZE];
	
	double hours[SIZE], otHours[SIZE], payRate[SIZE], otRate[SIZE], regularPay[SIZE], otPay[SIZE], 
		   grossPay[SIZE], ficaSSN[SIZE], ficaMED[SIZE], fedIncomeTax[SIZE], netPay[SIZE];

	cout << "~~Welcome to the payroll calculator!~~\n";

	for (int dataLoop = 0; dataLoop < SIZE; dataLoop++)
	{
		if (dataLoop == 0)
		{
			cout << "\nFirst Employee:" << endl;
		}
		else if (dataLoop == 1)
		{
			cout << "\nSecond Employee:" << endl;
		}
		else
		{
			cout << "\nThird Employee:" << endl;
		}
		cout << "1) Enter employee's first name: ";
		cin >> firstName;
		cout << "2) Enter employee's last name: ";
		cin >> lastName;
		workforce[dataLoop] = firstName + " " + lastName;
		do
		{
			cout << "3) Enter type of employee, Hourly or Salary (H or S): ";
			cin >> worker;
			employeeType[dataLoop] = getEmployeeType(worker, 'H', 'S');
			if (employeeType[dataLoop] == -1)
			{
				printErrorMessage("Letter", 0, 0);
			}
			else checkInput = true;
		} while (checkInput == false);

		if (employeeType[dataLoop] == Hourly)
		{
			do
			{
				checkInput = false;
				while (checkInput == false)
				{
					cout << "4) Enter total hours worked: ";
					cin >> number;
					hours[dataLoop] = makeNumber(number);
					if (hours[dataLoop] == -1.0)
					{
						printErrorMessage("Number", 0, 0);
					}
					else
					{
						checkInput = true;
						hours[dataLoop] = isInRange(hours[dataLoop], 0.0, 60.0);
						if (hours[dataLoop] == -1)
						{
							printErrorMessage("Range", 0, 60);
						}
					}
				}
			} while (hours[dataLoop] == -1);
			
			otHours[dataLoop] = getOTHours(hours[dataLoop]);

			do
			{
				checkInput = false;
				while (checkInput == false)
				{
					cout << "5) Enter hourly pay rate: ";
					cin >> number;
					payRate[dataLoop] = makeNumber(number);
					if (payRate[dataLoop] == -1.0)
					{
						printErrorMessage("Number", 0, 0);
					}
					else
					{
						checkInput = true;
						payRate[dataLoop] = isInRange(payRate[dataLoop], 0.0, 50.0);
						if (payRate[dataLoop] == -1)
						{
							printErrorMessage("Range", 0, 50);
						}
					}
				}
			} while (payRate[dataLoop] == -1);

			do
			{
				checkInput = false;
				while (checkInput == false)
				{
					cout << "6) Enter overtime hourly pay rate: ";
					cin >> number;
					otRate[dataLoop] = makeNumber(number);
					if (otRate[dataLoop] == -1.0)
					{
						printErrorMessage("Number", 0, 0);
					}
					else
					{
						checkInput = true;
						otRate[dataLoop] = isInRange(otRate[dataLoop], 0.0, 75.0);
						if (otRate[dataLoop] == -1)
						{
							printErrorMessage("Range", 0, 75);
						}
					}
				}
			} while (otRate[dataLoop] == -1);

			regularPay[dataLoop] = getRegularPay(hours[dataLoop], payRate[dataLoop]);
			otPay[dataLoop] = getOTPay(otHours[dataLoop], otRate[dataLoop]);
			grossPay[dataLoop] = getGrossPay(regularPay[dataLoop], otPay[dataLoop]);
		}
		else if (employeeType[dataLoop] == Salary)
		{
			do
			{
				checkInput = false;
				bool checkInput = false;
				while (checkInput == false)
				{
					cout << "4) Enter yearly salary: ";
					cin >> number;
					regularPay[dataLoop] = makeNumber(number);
					if (regularPay[dataLoop] == -1.0)
					{
						printErrorMessage("Number", 0, 0);
					}
					else
					{
						checkInput = true;
						regularPay[dataLoop] = isInRange(regularPay[dataLoop], 20000.0, 100000.0);
						if (regularPay[dataLoop] == -1)
						{
							printErrorMessage("Range", 20000, 100000);
						}
					}
				}
			} while (regularPay[dataLoop] == -1);

			grossPay[dataLoop] = getGrossPay(regularPay[dataLoop]);
		}

		fedIncomeTax[dataLoop] = getFIT(grossPay[dataLoop]);
		ficaSSN[dataLoop] = getFICASSN(grossPay[dataLoop]);
		ficaMED[dataLoop] = getFICAMED(grossPay[dataLoop]);
		netPay[dataLoop] = getNetPay(grossPay[dataLoop], fedIncomeTax[dataLoop], ficaSSN[dataLoop], ficaMED[dataLoop]);
	}

	cout << "\n" << printLineOfDashes('T') << printTitleBar() << printLineOfDashes('M');
	for (int i = 0; i < SIZE; i++)
	{
		printEmployeeData(employeeType[i], workforce[i], hours[i], otHours[i], payRate[i], otRate[i], regularPay[i],
						  otPay[i], grossPay[i], ficaSSN[i], ficaMED[i], fedIncomeTax[i], netPay[i]);
		if (i < (SIZE - 1))
		{
			cout << printLineOfDashes('M');
		}
		else cout << printLineOfDashes('B');
	}
	return 0;
}
