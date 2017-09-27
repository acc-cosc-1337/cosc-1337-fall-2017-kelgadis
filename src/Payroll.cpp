#include "Payroll.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

const double STANDARD_HOURS = 40.0;
const double BIWEEKLY = 26.0;
const double FIT = 0.15;
const double FICASSN = 0.062;
const double FICAMED = 0.0145;

/*
	Prints error messages

	@param option is type of error
	@param range1 is lower range limit
	@param range2 is upper range limit
*/

void printErrorMessage(string option, double range1, double range2)
{
	if (option == "Number")
	{
		cout << "~~~Please use numbers only.~~~" << endl;
	}
	else if (option == "Letter")
	{
		cout << "~~~Not an option, please try again.~~~" << endl;
	}
	else if (option == "Range")
	{
		cout << "~~~Out of range, please enter a number between " << range1 << " and " << range2 << ".~~~" << endl;
	}
}

/*
	Converts string user input to number and assures no letters were entered

	@param userInput is input entered by user

	@returns number
*/

double makeNumber(string userInput)
{
	double number = 0.0;
	for (int i = 0; i < userInput.size(); i++)
	{
		if (isalpha(userInput[i]))
		{
			number = -1.0;
			return number;
		}
	}
	number = stod(userInput);
	return number;
}

/*
	Gets ASCII value for employee type & verifies good input

	@param userInput is what the user entered
	@param letter1 is first option required
	@param letter2 is second option required

	@returns employee type
*/

int getEmployeeType(string userInput, char letter1, char letter2)
{
	int employee = 0;
	for (int i = 0; i < userInput.size(); i++)
	{
		if (!isalpha(userInput[i]))
		{
			employee = -1;
		}
	}
	char converter = toupper(userInput[0]);
	if (converter != letter1 && converter != letter2)
	{
		employee = -1;
	}
	else if (converter == letter1 || converter == letter2)
	{
		employee = int(converter);
	}
	return employee;
}

/*
	Ensures input entered is within range required

	@param input is number entered by user
	@param range1 is lower limit
	@param range2 is upper limit

	returns input
*/

double isInRange(double input, double range1, double range2)
{
	if (input < range1 || input > range2)
	{
		input = -1;
	}
	return input;
}

/*
	Calculates overtime hours

	@param hours is hours worked in one week

	@returns overtime hours worked in one week
*/

double getOTHours(double hours)
{
	double otHours = 0.0;
	if (hours > STANDARD_HOURS)
	{
		otHours = hours - STANDARD_HOURS;
	}
	return otHours;
}

/*
	Calculates overtime pay for hourly employees

	@param otHours is overtime hours worked in one week
	@param otPayRate is overtime hourly pay rate

	@returns overtime pay
*/

double getOTPay(double otHours, double otPayRate)
{
	double otPay = otPayRate * otHours;
	return otPay;
}

/*
	Calculates regular pay for hourly employees

	@param hours is hours worked in one week
	@param payRate is hourly pay rate

	@returns regular pay
*/

double getRegularPay(double hours, double payRate)
{
	double regularPay = hours * payRate;
	return regularPay;
}

/*
	Calculates gross pay for hourly employees

	@param regularPay is pay earned in one week for hourly employees
	@param otPay is overtime pay earned in one week for hourly employees

	@returns gross pay
*/

double getGrossPay(double regularPay, double otPay)
{
	double grossPay = regularPay + otPay;
	return grossPay;
}

/*
	Calculates gross pay for salary employees

	@param regularPay is yearly salary for salary employees
	
	@returns gross pay
*/

double getGrossPay(double regularPay)
{
	double grossPay = regularPay / BIWEEKLY;
	return grossPay;
}

/*
	Calculates federal income tax deduction

	@param grossPay is gross pay for either type of employee

	@returns federal income tax deduction
*/

double getFIT(double grossPay)
{
	double fedIncomeTax = FIT * grossPay;
	return fedIncomeTax;
}

/*
	Calculates FICA Social Security deduction

	@param grossPay is gross pay for either type of employee

	@returns FICA Social Security deduction
*/

double getFICASSN(double grossPay)
{
	double ficaSSN = FICASSN * grossPay;
	return ficaSSN;
}

/*
	Calculates FICA Medicare deduction

	@param grossPay is gross pay for either type of employee

	@returns FICA Medicare deduction
*/

double getFICAMED(double grossPay)
{
	double ficaMED = FICAMED * grossPay;
	return ficaMED;
}

/*
	Calculates net pay

	@param grossPay is gross pay for either type of employee
	@param fedIncomeTax is federal income tax deduction
	@param ficaSSN is FICA Social Security deduction
	@param ficaMED is FICA Medicare deduction

	@returns net pay
*/

double getNetPay(double grossPay, double fedIncomeTax, double ficaSSN, double ficaMED)
{
	double netPay = grossPay - fedIncomeTax - ficaSSN - ficaMED;
	return netPay;
}

/*
	Prints title bar for employee data output

	@returns title bar as string
*/

string printTitleBar()
{
	const int name = 17;
	const int normal = 13;
	const int large = 20;
	const string column = " |";

	ostringstream titleBar;

	titleBar << column
		<< left << setw(name) << "Name" << column
		<< right << setw(normal) << "Hours" << column
		<< right << setw(normal) << "OT Hours" << column
		<< right << setw(normal) << "Hourly Rate" << column
		<< right << setw(normal) << "OT Rate" << column
		<< right << setw(normal) << "Regular Pay" << column
		<< right << setw(normal) << "OT Pay" << column
		<< right << setw(normal) << "Gross Pay" << column
		<< right << setw(normal) << "FICA SS" << column
		<< right << setw(large) << "FICA Medicare" << column
		<< right << setw(large) << "Federal Income Tax" << column
		<< right << setw(normal) << "Net Pay" << column << endl;

	return titleBar.str();
}

/*
	Prints separator line

	@returns dashed line as string
*/

string printLineOfDashes(char position)
{
	ostringstream dashes;

	if (position == 'T' || position == 'B')
	{
		dashes << " " << string(199, '-') << endl;
	}
	else
	{
		dashes << " |" << string(197, '-') << "|" << endl;
	}
	return dashes.str();
}

/*
	Converts money type data to strings and prints all employee data to screen
*/

void printEmployeeData(int employee, string fullName, double hours, double otHours, double payRate, double otRate, double regularPay,
					   double otPay, double grossPay, double ficaSSN, double ficaMED, double fedIncomeTax, double netPay)
{
	enum employeeType { Hourly = 72, Salary = 83 };
	const int name = 17;
	const int normal = 13;
	const int large = 20;
	const string column = " |";

	ostringstream pr, otr, rp, otp, gp, fssn, fmed, fit, np;
	pr << fixed << setprecision(2) << "$" << payRate;
	otr << fixed << setprecision(2) << "$" << otRate;
	rp << fixed << setprecision(2) << "$" << regularPay;
	otp << fixed << setprecision(2) << "$" << otPay;
	gp << fixed << setprecision(2) << "$" << grossPay;
	fssn << fixed << setprecision(2) << "$" << ficaSSN;
	fmed << fixed << setprecision(2) << "$" << ficaMED;
	fit << fixed << setprecision(2) << "$" << fedIncomeTax;
	np << fixed << setprecision(2) << "$" << netPay;

	string stringPayRate, stringOTRate, stringRegularPay, stringOTPay, stringGrossPay, stringFSSN, stringFMED, stringFIT, stringNetPay;
	stringPayRate = pr.str();
	stringOTRate = otr.str();
	stringRegularPay = rp.str();
	stringOTPay = otp.str();
	stringGrossPay = gp.str();
	stringFSSN = fssn.str();
	stringFMED = fmed.str();
	stringFIT = fit.str();
	stringNetPay = np.str();

	cout << column << left << setw(name) << fullName << column;
	if (employee == Salary)
	{
		cout << right << setw(normal) << "n/a" << column
			 << right << setw(normal) << "n/a" << column
			 << right << setw(normal) << "n/a" << column
			 << right << setw(normal) << "n/a" << column 
			 << right << setw(normal) << stringRegularPay << column
			 << right << setw(normal) << "n/a" << column;
	}
	else
	{
		cout << right << setw(normal) << fixed << setprecision(2) << hours << column
			 << right << setw(normal) << fixed << setprecision(2) << otHours << column
			 << right << setw(normal) << stringPayRate << column
			 << right << setw(normal) << stringOTRate << column
			 << right << setw(normal) << stringRegularPay << column
			 << right << setw(normal) << stringOTPay << column;
	}
	cout << right << setw(normal) << stringGrossPay << column
		 << right << setw(normal) << stringFSSN << column
		 << right << setw(large) << stringFMED << column
		 << right << setw(large) << stringFIT << column
		 << right << setw(normal) << stringNetPay << column << endl;
}
