//Author: Brandon Tran
//Date: 05/06/20
//Purpose: Calculate loan payments

#include <iostream> //Access output stream
#include <iomanip>      // Access manipulators
using namespace std;    // Access cout, endl, cin

int main() {
	double loanAmount, annualIntPercent, anunalInt, monthlyPay;
	double intPaid, debtPaid, loanBalance, finalPay;
	double monthlyInt, totalInt;
	int month = 1; // month count starts with 1
	cout << "Welcome to use the Loan Payment Report of Brandon Tran!" << endl;
	cout << "Please enter monthly payment amount (e.g. 50, 100, 180) > ";
	cin >> monthlyPay;  // get monthly payment
	cout << endl; // blank line before the actual report
	annualIntPercent = 18.00;  // annual interest percent is 18%
	anunalInt = annualIntPercent / 100;  // example: 18.00 now becomes 0.18 
	monthlyInt = anunalInt / 12;  // Monthly interest is annual divided by 12 months
	loanAmount = 1000.0; // Loan amount
	totalInt =0; //Total Amount of Interest Paid
	loanBalance = loanAmount; // Initial loan balance

	cout << "Loan amount: $" << loanAmount << "\t" << "Annual Interest Rate: " << annualIntPercent << "%" << "\t" << "Monthly Payment: $"
		<< monthlyPay << ".00" << endl; //Print payment information
	cout << "\n" << "Month#" << setw(17) << "Monthly-Payment" << setw(14) << "Interest-Paid" << setw(12) << "Debt-Paid" << setw(19) << "Loan-Balance" << endl;
	cout << "-------" << setw(16) << "---------------" << setw(15) << "--------------" << setw(12) << "----------" << setw(19) << "-------------"; //Print headings

	do { //do while loop for equations and printing
		intPaid = monthlyInt * loanBalance;
		totalInt += intPaid;
		debtPaid = monthlyPay - intPaid;
		loanBalance = loanBalance - debtPaid;
		cout << endl << month << "\t"; // tab control is better for column alignment
		cout << fixed << showpoint << setprecision(2);
		cout << "$" << monthlyPay << "\t\t" << "$" << intPaid << "\t\t";
		cout << "$" << debtPaid << "\t\t" << "$" << loanBalance;
		month++; // continue to the next month's payment
	}while (loanBalance >= monthlyPay);

	if (loanBalance > 0 && loanBalance < monthlyPay) {
		intPaid = monthlyInt * loanBalance;
		totalInt += intPaid;
		debtPaid = loanBalance;
		loanBalance = loanBalance - debtPaid;

		cout << endl << month << "\t"; // tab control is better for column alignment
		cout << fixed << showpoint << setprecision(2);
		cout << "$" << monthlyPay << "\t\t" << "$" << intPaid << "\t\t";
		cout << "$" << debtPaid << "\t\t" << "$" << loanBalance << "\n" << endl;
		month++; // continue to the next month's payment

		cout << "Total Amount of Interest Paid = $" << totalInt << endl;
		cout << "Thank you for using this Loan Payment Report of Brandon Tran!" << endl;
	}
}