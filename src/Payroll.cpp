#include "Payroll.h"
#include <math.h>
#include <iostream>
#include <string>
#include <sstream> // storing streams to strings
#include <iomanip>
#include <cctype>
using namespace std;

bool isNumber(double input)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(123456789, '\n');
		cout << "~~~Please use numbers only.~~~" << endl;
		return false;
	}
	else return true;
}

bool isInRange(double input, double range1, double range2)
{
	if (input < range1 || input > range2)
	{
		cout << "~~~Out of range, please enter a number between " << range1 << " and " << range2 << ".~~~" << endl;
		return false;
	}
	else return true;
}

string getEmployeeName(int employee)
{
	string firstName, lastName;
	if (employee == 1)
	{
		cout << "\nFirst Employee:" << endl;
	}
	else if (employee == 2)
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

	string fullName = firstName + " " + lastName;
	return fullName;
}

bool isLetter(string input)
{
	bool returnValue = false;
	char letter = input[0];
	if (isalpha(letter))
	{
		returnValue = true;
	}
	else
	{
		cout << "~~~Not an option, please try again.~~~" << endl;
		returnValue = false;
	}
	return returnValue;
}

string getEmployeeType()
{
	char input = 'a';
	string employeeType = " ";
	do
	{
		bool checkInput = false;
		while (checkInput == false)
		{
			cout << "3) Enter type of employee, Hourly or Salary: ";
			cin >> employeeType;
			checkInput = isLetter(employeeType);
		}
		input = toupper(employeeType[0]);
		if (input == 'H')
		{
			employeeType = "Hourly";
		}
		else if (input == 'S')
		{
			employeeType = "Salary";
		}
		else cout << "~~~Not an option, please try again.~~~" << endl;
	} while (input != 'H' && input != 'S');
	return employeeType;
}

double getRegularHours()
{
	bool checkRange = false;
	double hours = 0.0;
	do
	{
		bool checkInput = false;
		while (checkInput == false)
		{
			cout << "4) Enter total hours worked: ";
			cin >> hours;

			checkInput = isNumber(hours);
		}
		checkRange = isInRange(hours, 0.0, 60.0);
	} while (checkRange == false);
	return hours;
}

double getOTHours(double hours)
{
	double otHours = 0.0;
	if (hours > 40.0)
	{
		otHours = hours - 40.0;
	}
	return otHours;
}

double getPayRate()
{
	bool checkRange = false;
	double payRate = 0.0;
	do
	{
		bool checkInput = false;
		while (checkInput == false)
		{
			cout << "5) Enter hourly pay rate: ";
			cin >> payRate;

			checkInput = isNumber(payRate);
		}
		checkRange = isInRange(payRate, 0.0, 50.0);
	} while (checkRange == false);
	return payRate;
}

double getOTPayRate()
{
	bool checkRange = false;
	double otPayRate = 0.0;
	do
	{
		bool checkInput = false;
		while (checkInput == false)
		{
			cout << "6) Enter overtime hourly pay rate: ";
			cin >> otPayRate;

			checkInput = isNumber(otPayRate);
		}
		checkRange = isInRange(otPayRate, 0.0, 75.0);
	} while (checkRange == false);
	return otPayRate;
}

double getOTPay(double otHours, double otPayRate)
{
	double otPay = otPayRate * otHours;
	return otPay;
}

double getRegularPay(string employee, double hours, double payRate)
{
	double regularPay = hours * payRate;
	return regularPay;
}

double getRegularPay(string employee)
{
	bool checkRange = false;
	double regularPay = 0.0;
	do
	{
		bool checkInput = false;
		while (checkInput == false)
		{
			cout << "4) Enter yearly salary: ";
			cin >> regularPay;

			checkInput = isNumber(regularPay);
		}
		checkRange = isInRange(regularPay, 20000.0, 100000.0);
		break;
	} while (checkRange == false);
	return regularPay;
}

double getGrossPay(double regularPay, double otPay) // hourly
{
	double grossPay = regularPay + otPay;
	return grossPay;
}

double getGrossPay(double regularPay) // salary
{
	double grossPay = regularPay / 26;
	return grossPay;
}

double getFIT(double grossPay)
{
	double fedIncomeTax = 0.15 * grossPay;
	return fedIncomeTax;
}

double getFICASSN(double grossPay)
{
	double ficaSSN = 0.062 * grossPay;
	return ficaSSN;
}

double getFICAMED(double grossPay)
{
	double ficaMED = 0.0145 * grossPay;
	return ficaMED;
}

double getNetPay(double grossPay, double fedIncomeTax, double ficaSSN, double ficaMED)
{
	double netPay = grossPay - fedIncomeTax - ficaSSN - ficaMED;
	return netPay;
}

string printHeaderLine()
{
	// setw() constants:
	const int nameWidth = 17;
	const int normalWidth = 13;
	const int largeWidth = 20;
	const string columnLine = " |";

	ostringstream headerLine;

	// title bar
	headerLine << columnLine
			   << left << setw(nameWidth) << "Name" << columnLine
			   << right << setw(normalWidth) << "Hours" << columnLine
			   << right << setw(normalWidth) << "OT Hours" << columnLine
			   << right << setw(normalWidth) << "Hourly Rate" << columnLine
			   << right << setw(normalWidth) << "OT Rate" << columnLine
			   << right << setw(normalWidth) << "Regular Pay" << columnLine
			   << right << setw(normalWidth) << "OT Pay" << columnLine
			   << right << setw(normalWidth) << "Gross Pay" << columnLine
			   << right << setw(normalWidth) << "FICA SSN" << columnLine
			   << right << setw(largeWidth) << "FICA Medicare" << columnLine
			   << right << setw(largeWidth) << "Federal Income Tax" << columnLine
			   << right << setw(normalWidth) << "Net Pay" << columnLine << endl;

	return headerLine.str();
}

string printLineOfDashes(char position)
{
	ostringstream dashes;

	if (position == 'T' || position == 'B') // if top or bottom
	{
		dashes << " " << string(199, '-') << endl;
	}
	else
	{
		dashes << " |" << string(197, '-') << "|" << endl;
	}
	return dashes.str();
}

string addDollarSign(double input)
{
	ostringstream makeItMoney;

	makeItMoney << fixed << setprecision(2) << "$" << input;

	return makeItMoney.str();
}

string storePayrollHourly(string employee, string fullName, double hours, double otHours, double payRate, double otRate, double regularPay,
						  double otPay, double grossPay, double ficaSSN, double ficaMED, double fedIncomeTax, double netPay)
{
	// setw() constants:
	const int nameWidth = 17;
	const int normalWidth = 13;
	const int largeWidth = 20;
	const string columnLine = " |";

	ostringstream employeeData;

	// employee data
	employeeData << columnLine
				 << left << setw(nameWidth)  << fullName << columnLine
				 << right << setw(normalWidth) << fixed << setprecision(2) << hours << columnLine
				 << right << setw(normalWidth) << fixed << setprecision(2) << otHours << columnLine
				 << right << setw(normalWidth) << addDollarSign(payRate) << columnLine
				 << right << setw(normalWidth) << addDollarSign(otRate) << columnLine
				 << right << setw(normalWidth) << addDollarSign(regularPay) << columnLine
				 << right << setw(normalWidth) << addDollarSign(otPay) << columnLine
				 << right << setw(normalWidth) << addDollarSign(grossPay) << columnLine
				 << right << setw(normalWidth) << addDollarSign(ficaSSN) << columnLine
				 << right << setw(largeWidth) << addDollarSign(ficaMED) << columnLine
				 << right << setw(largeWidth) << addDollarSign(fedIncomeTax) << columnLine
				 << right << setw(normalWidth) << addDollarSign(netPay) << columnLine << endl;

	return employeeData.str();
}

string storePayrollSalary(string employee, string fullName, double regularPay, double grossPay, double ficaSSN, double ficaMED, double fedIncomeTax, double netPay)
{
	const int nameWidth = 17;
	const int normalWidth = 13;
	const int largeWidth = 20;
	const string columnLine = " |";

	ostringstream employeeData;

	employeeData << columnLine
				 << left << setw(nameWidth) << fullName << columnLine
				 << right << setw(normalWidth) << "n/a" << columnLine
				 << right << setw(normalWidth) << "n/a" << columnLine
				 << right << setw(normalWidth) << "n/a" << columnLine
				 << right << setw(normalWidth) << "n/a" << columnLine
				 << right << setw(normalWidth) << addDollarSign(regularPay) << columnLine
				 << right << setw(normalWidth) << "n/a" << columnLine
				 << right << setw(normalWidth) << addDollarSign(grossPay) << columnLine
				 << right << setw(normalWidth) << addDollarSign(ficaSSN) << columnLine
				 << right << setw(largeWidth) << addDollarSign(ficaMED) << columnLine
				 << right << setw(largeWidth) << addDollarSign(fedIncomeTax) << columnLine
				 << right << setw(normalWidth) << addDollarSign(netPay) << columnLine << endl;

	return employeeData.str();
}

