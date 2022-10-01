// Author:  Brandon Tran
// Date:    4/22/20                              CS116-Lab2
// Purpose: Compute 3 mortgage payments and print a table of 3 rows.

// #include "pch.h"     // may not need it here
#include <iostream>	   // Access output stream
#include <iomanip>      // Access manipulators
using namespace std;    // Access cout, endl, cin
// All 6 global variables here
double loan_amount = 50000.00; // No change at all in this program.
int    number_of_years = 5; // No change at all in this program.
double yearly_percent_int;  // INPUT & also for display on output
double yearly_interest;      // to be computed = yearly_percent_int / 100.   
double monthly_interest; // to be computed = yearly_interest / 12.
int    number_payments;  // to be computed = number_of_years * 12  

double getpayment(double apr) // function to compute payment for apr
{
	double payment;
	yearly_percent_int = apr; // input parameter from the caller
	yearly_interest = yearly_percent_int / 100.; // example: 0.015 , 1.50 %
	monthly_interest = yearly_interest / 12;      // 12 months per year 
	number_payments = number_of_years * 12;      // 12 payments per year 
	payment = (loan_amount *
		pow(monthly_interest + 1, number_payments) * monthly_interest) /
		(pow(1 + monthly_interest, number_payments) - 1);
	return payment; 
}

void print(double yearly_percent_int, double payment)
{	// function to print this row of payment for apr
	cout << fixed << setprecision(2) //Round to 2 digits after decimal point
		<< loan_amount << setw(22) << yearly_percent_int
		<<setw(26) << number_of_years
		<< setw(22) << "$" << payment << endl;
	//end of print function 
}
int main() // main program starts here
{ // begin main()  // get 3 APRs and print their payments information
	int n = 1; // line number control for line separator =========.
	double apr1, apr2, apr3; // 3 annual percent interest rates // No array here.
	double pay1, pay2, pay3; // 3 payments for 3 APRs           // No array here.
	cout << "Welcome to the Mortgage Payment Tool of Brandon Tran!" << endl << endl;
	cout << n++ << "=====================================================." << endl << endl;
	cout << ">> Enter 3 Annual % Interest Rate (such as 1.5  2.75  4.50):" << endl;
	cin >> apr1 >> apr2 >> apr3;        // get 3 APR values from the user
	cout << endl << n++ << "=====================================================." << endl;
	pay1 = getpayment(apr1); // compute payment for apr1
	pay2 = getpayment(apr2); // compute payment for apr2
	pay3 = getpayment(apr3); // compute payment for apr3
	cout << endl; // a blank line as separator
// print 2 header lines of 4 columns each

	// Your Coding here
	cout << "Loan Amount      " << "Annual % Interest Rate		"
		<< "Number of years		 " << "Monthly Payment" <<endl;
	cout << "-----------	" << " ----------------------		"
		<< "---------------		" << "---------------" << endl;
									  
	print(apr1, pay1); // print row 1
	print(apr2, pay2); // print row 2
	print(apr3, pay3); // print row 3
	cout << endl; // a blank line as separator
	cout << endl << n++ << "=====================================================." << endl;
	cout << "Thank you for using the Mortgage Payment Tool of Brandon Tran!" << endl;
	cout << n++ << "=====================================================." << endl << endl;
	cout << "To really quit the game, please enter a number: " << endl;
	cin >> n;
	return 0;   	// Indicates successful completion
} // end main() 