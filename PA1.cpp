// Author:  Brandon Tran
// Date:    4/27/2020
// Purpose: Create a table of 7 temperatures from Fahrenheit to Celsius.
#include <iostream>	   // Access input output stream
#include <iomanip>      // Access manipulators
using namespace std;    // Access cout, endl, cin

int main()
{
	cout << "Welcome to the Temperature Tool of Brandon Tran!\n" << endl << endl;
	double tf1, tf2, tf3, tf4, tf5, tf6, tf7; // temperature F, 7 of them
	double tc1, tc2, tc3, tc4, tc5, tc6, tc7; // temperature C, 7 of them
	cout << "Please enter 7 temperatures in Fahrenheit: ";
	cin >> tf1 >> tf2 >> tf3 >> tf4 >> tf5 >> tf6 >> tf7; // get 7 values

	tc1 = 5. / 9. * (tf1 - 32); //equation for tc1
	tc2 = 5. / 9. * (tf2 - 32); //equation for tc2
	tc3 = 5. / 9. * (tf3 - 32); //equation for tc3
	tc4 = 5. / 9. * (tf4 - 32); //equation for tc4
	tc5 = 5. / 9. * (tf5 - 32); //equation for tc5
	tc6 = 5. / 9. * (tf6 - 32); //equation for tc6
	tc7 = 5. / 9. * (tf7 - 32); //equation for tc7
	
	cout << fixed << setprecision(1) << endl; //1 digit after decimal point
	cout << "degree F" << setw(10) << "degree C" << endl; //heading 1
	cout << "=========" << setw(10) << "=========" << endl;  //heading 2
	cout << setw(8) << tf1 << setw(10) << tc1 << endl; //print tf1 and tc1
	cout << setw(8) << tf2 << setw(10) << tc2 << endl; //print tf2 and tc2
	cout << setw(8) << tf3 << setw(10) << tc3 << endl; //print tf3 and tc3
	cout << setw(8) << tf4 << setw(10) << tc4 << endl; //print tf4 and tc4
	cout << setw(8) << tf5 << setw(10) << tc5 << endl; //print tf5 and tc5
	cout << setw(8) << tf6 << setw(10) << tc6 << endl; //print tf6 and tc6
	cout << setw(8) << tf7 << setw(10) << tc7 << endl; //print tf7 and tc7

	cout << endl << "Thank you for using the Temperature Tool of Brandon Tran!\n" << endl;
	int quit;
	cout << "To really quit this game, please enter a number: " << endl;
	cin >> quit;
	return 0;       	// Indicates successful completion
} // end main ( ) ===========================================================.

