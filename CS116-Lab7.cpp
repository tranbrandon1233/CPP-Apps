//Author: Brandon Tran
//Date: 5/20/20
//Purpose: Create a class to store information about students

#include <iostream>
#include <iomanip> //access setprecision
using namespace::std;// access cout, endl, and cin

static int countStudents = 0; // count the total number of students being constructed 
static double totalGpa = 0.0; // total GPA sum of all students  // don’t use float 
static double averageGpa = 0.0; // average GPA of all students  // don’t use float  
static string sidA[12]; // 5 static parallel arrays of 12 items each
static string lnameA[12]; // like 5 fields for each student record 
static string fnameA[12];
static double gpaA[12];
static string phoneA[12];

class Student {
	public:
		void createStudentObject(string studentID, string lastName, string firstName, double gpa, string phoneNumber);
		void generateReport(int n);
	private:
		string   studentID;   	// student’s ID 			such as   1 
		string   lastName;  	// student’s last name 		such as   Doe
		string   firstName;  	// student’s first name 		such as   John
		double  gpa;           	// student’s GPA 		such as   3.0
		string   phoneNumber;  // student’s phone number  	such as   626-111-1111 
};
int main()
{
	string   studentID;   	// student’s ID 			such as   1 
	string   lastName;  	// student’s last name 		such as   Doe
	string   firstName;  	// student’s first name 		such as   John
	double  gpa;           	// student’s GPA 		such as   3.0
	string   phoneNumber;  // student’s phone number  	such as   626-111-1111 
	int n = 1;
	Student studentInfo;
	cout << "Welcome to the Student GPA System of Brandon Tran!" << endl;
	while (true) {
		cout << n++ << "==========================================================." << endl;
		cout << "Please enter student ID, last name, first name, GPA, and phone number > " << endl;
		cin >> studentID >> lastName >> firstName >> gpa >> phoneNumber;
		if (studentID == "0" && lastName == "0" && firstName == "0" && gpa == 0 && phoneNumber == "0") {
			break;
		}
		studentInfo.createStudentObject(studentID, lastName, firstName, gpa, phoneNumber);
	}
	studentInfo.generateReport(n);
}
void Student::createStudentObject(string studentID, string lastName, string firstName, double gpa, string phoneNumber){
		countStudents++;
		totalGpa += gpa;
		averageGpa = totalGpa / countStudents;
		cout << "Student ID: " << studentID << ", Last name: " << lastName << ", First Name: " << firstName;
		cout << fixed << setprecision(2) << ", GPA: " << gpa << ", Phone Number: " << phoneNumber << endl;
		cout << fixed << setprecision(2) << "Current Student Count: " << countStudents << ", Total GPA: " << totalGpa << ", Average GPA: " << averageGpa << endl;
		sidA[countStudents - 1] = studentID;
		lnameA[countStudents - 1] = lastName;
		fnameA[countStudents - 1] = firstName;
		gpaA[countStudents - 1] = gpa;
		phoneA[countStudents - 1] = phoneNumber;
}

void Student::generateReport(int n) {
	cout << n++ << "==========================================================." << endl;
	cout << "Student GPA Report:" << '\n' << endl;
	cout << "ID" << setw(15) << "Last Name" << setw(20) << "First Name" << setw(16) << "GPA" << setw(24) << "Phone Number" << endl;
	cout << "-----" << setw(15) << "--------------" << setw(22) << "-----------------" << setw(15) << "----------" << setw(25) << "---------------------" << endl;
	for (int x = 1; x <= countStudents; x++) {
		cout << x << setw(15) << lnameA[x - 1] << setw(20) << fnameA[x - 1] << setw(18);
		cout << fixed << setprecision(2) << gpaA[x - 1] << setw(23) << phoneA[x - 1] << endl;
	}
	cout << "\n" << "The average GPA of the above " << countStudents << " students is " << averageGpa << '\n' << endl;
	cout << n++ << "==========================================================." << endl;
	cout << "Thank you for using the Student GPA System of Brandon Tran!" << endl;
	cout << n++ << "==========================================================." << endl;
}