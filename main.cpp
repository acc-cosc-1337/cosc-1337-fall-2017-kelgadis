#include "Payroll.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
	enum storeData{ Hourly = 1, Salary};
	double hours = 0.0, otHours = 0.0, payRate = 0.0, otRate = 0.0, otPay = 0.0, regularPay = 0.0, grossPay = 0.0, ficaSSN = 0.0, ficaMed = 0.0, fedIncomeTax = 0.0, netPay = 0.0;
	string employeeName = "", employeeType = "", employee1 = "", employee2 = "", employee3 = "", dashLineToB = "", dashLineMid = "";
	int switchEmployee = 0;

	// print title of program
	cout << "~~Welcome to the payroll calculator!~~\n";

	int dataLoop;
	for (dataLoop = 1; dataLoop <= 3; dataLoop++)
	{
		employeeName = getEmployeeName(dataLoop);
		employeeType = getEmployeeType();
		if (employeeType == "Hourly")
		{	
			switchEmployee = Hourly;
			hours = getRegularHours();
			otHours = getOTHours(hours);
			payRate = getPayRate();
			otRate = getOTPayRate();
			regularPay = getRegularPay(employeeType, hours, payRate);
			otPay = getOTPay(otHours, otRate);
			grossPay = getGrossPay(regularPay, otPay);
		}
		else if (employeeType == "Salary")
		{
			switchEmployee = Salary;
			regularPay = getRegularPay(employeeType);
			grossPay = getGrossPay(regularPay);
		}	
		fedIncomeTax = getFIT(grossPay);
		ficaSSN = getFICASSN(grossPay);
		ficaMed = getFICAMED(grossPay);
		netPay = getNetPay(grossPay, fedIncomeTax, ficaSSN, ficaMed);

		switch (switchEmployee)
		{
			case Hourly:
				if (dataLoop == 1)
				{
					employee1 = storePayrollHourly(employeeType, employeeName, hours, otHours, payRate, otRate, regularPay, otPay, grossPay, ficaSSN, ficaMed, fedIncomeTax, netPay);
				}
				else if (dataLoop == 2)
				{
					employee2 = storePayrollHourly(employeeType, employeeName, hours, otHours, payRate, otRate, regularPay, otPay, grossPay, ficaSSN, ficaMed, fedIncomeTax, netPay);
				}
				else employee3 = storePayrollHourly(employeeType, employeeName, hours, otHours, payRate, otRate, regularPay, otPay, grossPay, ficaSSN, ficaMed, fedIncomeTax, netPay);
				break;
			case Salary:
				if (dataLoop == 1)
				{
					employee1 = storePayrollSalary(employeeType, employeeName, regularPay, grossPay, ficaSSN, ficaMed, fedIncomeTax, netPay);
				}
				else if (dataLoop == 2)
				{
					employee2 = storePayrollSalary(employeeType, employeeName, regularPay, grossPay, ficaSSN, ficaMed, fedIncomeTax, netPay);
				}
				else employee3 = storePayrollSalary(employeeType, employeeName, regularPay, grossPay, ficaSSN, ficaMed, fedIncomeTax, netPay);
				break;
		}
	}
	// display results (T = Top, M = Middle, B = Bottom)
	cout << "\n" << printLineOfDashes('T') << printHeaderLine() << printLineOfDashes('M') << employee1 << printLineOfDashes('M') << employee2 << printLineOfDashes('M') << employee3 << printLineOfDashes('B') << endl;

    return 0;
}
