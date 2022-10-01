//Author: Brandon Tran
//Date: 05/04/2020
//Purpose: Create a simple calculator

#include <iostream>   // Access input output stream
#include <iomanip>      // Access manipulators
using namespace std;    // Access cout, endl, cin

int main()
{
    int x = 1; //counts line number
    double N1, N2{}; //initialize variables
    char operation{};
    cout << "Welcome  to use the Simple Calculator of Brandon Tran!" << endl;

    while (true) //an infinite loop that can be stopped by user input of @
    { //while loop
        cout << x++ << "============================================================." << endl;
        cout << "Please enter your number, operator, and number > ";
        cin >> N1 >> operation >> N2;

        if (operation == '-')
        {
            cout << "Result: " << N1 << " " << operation << " " << N2 << " = " << N1 - N2 << endl;
        }
        else if (operation == '+')
        {
            cout << "Result: " << N1 << " " << operation << " " << N2 << " = " << N1 + N2 << endl;
        }
        else if (operation == '%')
        {
            while (N2 == 0)
            {
                cout << "Zero is not valid for division.  Please enter a valid number > ";
                cin >> N2;
            }
            if (N2 != 0)
            {
                cout << "Result: " << N1 << " " << operation << " " << N2 << " = " << fmod(N1, N2) << endl;
            }
        }
        else if (operation == '/')
        {
            while (N2 == 0)
            {
                cout << "Zero is not valid for division.  Please enter a valid number > ";
                cin >> N2;
            }
            if (N2 != 0)
            {
                cout << "Result: " << N1 << " " << operation << " " << N2 << " = " << N1 / N2 << endl;
            }
        }
        else if (operation == '*')
        {
            cout << "Result: " << N1 << " " << operation << " " << N2 << " = " << N1 * N2 << endl;
        }
        else if (operation == '^')
        {
            cout << "Result: " << N1 << " " << operation << " " << N2 << " = " << pow(N1, N2) << endl;
        }
        else if (operation == '@') //exit while loop if operation == @
        {
            break;
        }
        else
        {
            cout << "Sorry, the operator " << operation << " is not valid!" << endl;
        }

    }; //end of while loop
    cout << "Thank you for using the Simple Calculator of Brandon Tran!" << endl;
    cout << x++ << "============================================================." << endl;
    return 0; //Indicates successful completion
}
// end main()