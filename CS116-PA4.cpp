//Author: Brandon Tran
//Date: 5/11/20
//Purpose: Check if password is secure

#include <string>	      // for string input
#include <iostream>	// Access input output stream
using namespace std;    // Access cout, endl, cin
// global variables and prototypes of functions

string pw; // global pw for the password
bool r1, r2, r3, r4, r5, r6, r7; // global 7 boolean flags for violations
void s1(); void s2(); void s3(); void s4(); void s5();
void s6(); void s7(); // 7 prototypes of functions to be defined after main() 

int main()
{ // begin of main ==================================================.
	int n = 1;
	cout << "Welcome to the PASSWORD game designed by Brandon Tran!" << endl;

	while (pw != "quit")  // the password is not “quit”
	{ //begin of while loop
		cout << n++ << "============================================================." << endl;
		cout << "Please enter a password: ";
		getline(cin, pw); // pw may have blanks anywhere, so must use getline( )
		cout << "Your password \"" << pw << "\" ";
		if (pw == "quit") {
			break;
		}
		s1(); s2(); s3(); s4();
		s5(); s6(); s7();  // call to check all 7 rules for satisfaction/violation

		if (r1 && r2 && r3 && r4 && r5 && r6 && r7) // all 7 rules satisfied
			cout << "is very secure! Congratulations!" << endl;
		else // insecure password

		{ // begin print all the violated rules in detail ================. 
			cout << "violates the following rule(s):" << endl;
			if (!r1) cout << "Rule 1: Length invalid - The length of the password must be 8 to 12 only." << endl;
			if (!r2) cout << "Rule 2: No Space - The password must not contain any space or blank character." << endl;
			if (!r3) cout << "Rule 3: At least 2 digits - The password must contain at least 2 digits." << endl;
			if (!r4) cout << "Rule 4: At least 1 upper-case letter - The password must contain at least one upper-case letter." << endl;
			if (!r5) cout << "Rule 5: At least 1 lower-case letter - The password must contain at least one lower-case letter." << endl;
			if (!r6) cout << "Rule 6: At least 1 special character - The password must contain at least one special character, which can be o!="ne of the following 7 choices: '$', '#', '@', '&', '*', '?', or '!'." << endl;
			if (!r7) cout << "Rule 7: No special numbers - The password must not contain any of the following 4 numbers: 2020, 2019, 2018, or 2017." << endl;
		} // end print all the violated rules in detail =====================.
	} // end of while loop ==============================================.

	cout << "is to quit the game." << endl;
	cout << n++ << "============================================================." << endl;
	cout << "Thank you for playing the PASSWORD game designed by Brandon Tran!" << endl;
	cout << n++ << "============================================================." << endl;
	return 0; // normally done now
} // end of main =========================================================.

void s1() { //to check for rule 1
	if (pw.length() >= 8 && pw.length() <= 12)
		r1 = true;
	else
		r1 = false;
}

void s2() { // to check for security rule 2
	if (pw.find(" ") == string::npos) {
		r2 = true;
	}
	else
		r2 = false;
}

void s3() // to check for security rule 3
{ // begin of s3( )
	char c;    int countDigits;
	string digits = "0123456789";
	countDigits = 0;  r3 = false;
	for (int i = 0; i < pw.length(); i++)
	{
		c = pw.at(i);
		if (digits.find(c) != string::npos)  countDigits++;
	}
	if (countDigits >= 2)
		r3 = true; // for Rule 3 checking: at least 2 digits   
} // end of s3( )

void s4() { // to check for security rule 4
	char x;    
	string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	r4 = false;
	for (int i = 0; i < pw.length(); i++)
	{
		x = pw.at(i);
		if (upperChars.find(x) != string::npos)  r4 = true; // for Rule 4 checking: at least 1 uppercase letter
	}
} // end of s4( )

void s5() { // to check for security rule 5
	char x;    
	string lowerChars = "abcdefghijklmnopqrstuvwxyz";
	r5 = false;
	for (int i = 0; i < pw.length(); i++)
	{
		x = pw.at(i);
		if (lowerChars.find(x) != string::npos)  r5 = true; // for Rule 5 checking: at least 1 lowercase letter 
	} 
} // end of s5( )

void s6() { // to check for security rule 6
	char x;    
	string specialChars = "$#@&*?!";
	r6 = false;
	for (int i = 0; i < pw.length(); i++)
	{
		x = pw.at(i);
		if (specialChars.find(x) != string::npos)  r6 = true; // for Rule 6 checking: at least 1 special character   ;
	}		
} // end of s6( )

void s7() { // to check for security rule 7
	r7 = false;
	if (pw.find("2017") == string::npos && pw.find("2018") == string::npos && pw.find("2019") == string::npos && pw.find("2020") == string::npos)
		r7 = true; // for Rule 7 checking: special numbers do not appear   
} // end of s6( )