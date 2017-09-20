#ifndef _PAYROLL_H
#define _PAYROLL_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
using namespace std;

bool isNumber(double input);
bool isInRange(double input, double range1, double range2);
bool isLetter(string input);
string getEmployeeName(int employee);
string getEmployeeType();
double getRegularHours();
double getOTHours(double hours);
double getPayRate();
double getOTPayRate();
double getOTPay(double otHours, double otPayRate);
double getRegularPay(string employee, double hours, double payRate);
double getRegularPay(string employee);
double getGrossPay(double regularPay, double otPay); // hourly
double getGrossPay(double regularPay); // salary
double getFIT(double grossPay);
double getFICASSN(double grossPay);
double getFICAMED(double grossPay);
double getNetPay(double grossPay, double fedIncomeTax, double ficaSSN, double ficaMED);
string printHeaderLine();
string printLineOfDashes(char position);
string addDollarSign(double input);
string storePayrollHourly(string employee, string fullName, double hours, double otHours, double payRate, double otRate, double regularPay,
					double otPay, double grossPay, double ficaSSN, double ficaMED, double fedIncomeTax, double netPay);
string storePayrollSalary(string employee, string fullName, double regularPay, double grossPay, double ficaSSN, double ficaMED, double fedIncomeTax, double netPay);

#endif
