// Author:  Brandon Tran 
// Date:    4/23/2020
// Purpose: Convert temperatures between Fahrenheit and Celsius.
#include <iostream>		// Access input output stream
#include <iomanip>      	// Access manipulators
using namespace std;    	// Access cout, endl, cin

int main()
{
	int n = 1; // line number for each separation line for readability
	double tc, tf; // temperature C,  temperature F
	cout << "Welcome to the Temperature Conversion Tool of Brandon Tran!" << endl;

	while (true) // an infinite loop to be stopped by user's input of -999
	{ //while loop 
		cout << n++ << "=============================================================" << endl;
		cout << "Please enter a temperature in Fahrenheit: (-999 to quit) ";
		cin >> tf;
		
		if (tf == -999)  // exit the while loop since temperature is -999
			break;

		cout << tf << " degree F = " 
			<< 5./9.*(tf - 32) << " degree C." << endl;

		cout << "Please enter a temperature in Celsius: (-999 to quit)  ";
		cin >> tc;

		if (tc == -999)  // exit the while loop since temperature is -999
			break;

		cout << tc << " degree C = "
			<< 9./5.*tc + 32 << " degree F." << endl;

	} // end of while loop
	cout << n++ << "=====================================================" << endl;
	cout << "Thank you for using the Temperature Conversion Tool of Brandon Tran!" << endl;
	cout << n++ << "=====================================================" << endl;
	int quit;
	cout << "To really quit this game, please enter a number: " << endl;
	cin >> quit;
	return 0;       	// Indicates successful completion
} // end main ( ) ========================================================.