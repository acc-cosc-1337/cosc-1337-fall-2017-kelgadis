#pragma once
#ifndef _PAYROLL_H_INCLUDED
#define _PAYROLL_H_INCLUDED
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void printErrorMessage(string option, double range1, double range2);
double makeNumber(string userInput);
int getEmployeeType(string userInput, char letter1, char letter2);
double isInRange(double input, double range1, double range2);
double getOTHours(double hours);
double getOTPay(double otHours, double otPayRate);
double getRegularPay(double hours, double payRate);
double getGrossPay(double regularPay, double otPay); // hourly
double getGrossPay(double regularPay); // salary
double getFIT(double grossPay);
double getFICASSN(double grossPay);
double getFICAMED(double grossPay);
double getNetPay(double grossPay, double fedIncomeTax, double ficaSSN, double ficaMED);
string printTitleBar();
string printLineOfDashes(char position);
void printEmployeeData(int employee, string fullName, double hours, double otHours, double payRate, double otRate, double regularPay,
					   double otPay, double grossPay, double ficaSSN, double ficaMED, double fedIncomeTax, double netPay);

#endif // _PAYROLL_H_INCLUDED
