#include <iostream>

using namespace std;

int max(int p, int q, int r); //method headers to initialize methods to be defined later
int min(int p, int q, int r);
int mid(int p, int q, int r);

int main() {
    int n = 1;
    int num1, num2, num3;
    char response;
    cout << "Welcome to the Number Game by Brandon Tran." << endl; //

    while (true) { //loop until user tells the program to stop
        cout << n++ << "================================================" << endl;
        cout << "Please enter 3 integer numbers in any order: "; //user prompt
        cin >> num1 >> num2 >> num3; //user input

        cout << "\nYou just entered 3 numbers: " << num1 << ", " << num2 << ", " << num3 << endl; //print user input
        cout << "The sum is " << num1 + num2 + num3 << " and the average is " << (float(num1) + float(num2) + float(num3)) / 3 << endl; //print sorted list using methods   defined later
        cout << "The sum is " << num1 + num2 + num3 << " and the average is " << float((num1 + num2 + num3) / 3) << endl; //print sum and average of user input
        cout << "Do you want to repeat this program? (Y or N): "; //ask to repeat
        cin >> response; //accept response
        if (tolower(response) == 'y') { //check user response; if yes,
            cout << "\n";
            continue; //continue looping
        }
        else{ //if response is not yes,
            break; //break the loop
        }
    }
    cout << n++ << "===========================================================" << endl;
    cout << "Thank you for playing.";
}

int max(int p, int q, int r) { //find largest number using 3 numbers as parameters
    int maxNum = q; //store the largest num in this variable with an initial value
    if (p > q && p > r) { //if p is the largest number
        maxNum = p; //assign the variable to p
    }
    else if (q > p && q > r) { //if q is the largest number
        maxNum = q; //assign the variable to q
    }
    else if (r > p && r > q) {
        maxNum = r;  //assign the variable to r
    }
    else if (r == q) { //if q and r are equal
        if (r > p) { // if r is greater than p,
            maxNum = r; //the largest number is r OR q
        }
        else if (p > r) { //if p is greater than r,
            maxNum = p; // the largest number is p
        }
    }
    else if (r == p) { //if r and p are equal
        if (r > q) { // if r is greater than q,
            maxNum = r; //the largest number is r OR p
        }
        else if (q > r) { // if q is greater than r,
            maxNum = q; //the largest number is q
        }
    }
    else if (p == q) { // else if p and q are equal,
        if (r > p) { //if r is greater than p
            maxNum = r; //the largest number is r 
        }
        else if (p > r) { //if p is greater than r
            maxNum = p; //the largest number is p OR q
        }
    }
    return maxNum; //return the variable
}

int min(int p, int q, int r) { //find the smallest number
    int minNum = q; //store the smallest num in this variable with an initial value
    if (p < q && p < r) { //if p is the smallest number
        minNum = p; //assign variable to p
    }
    else if (q < p && q < r) { //if q is the smallest number
        minNum = q; //assign variable to p
    }
    else if (r < p && r < q) { //if r is the smallest number
        minNum = r; //assign the variable to r
    }
    else if (r == q) { //if r and q are equal
        if (r < p) { //if r is less than p
            minNum = r; //assign the variable to r OR q
        }
        else if (p < r) { //if p is less than r
            minNum = p; //assign the variable to p
        }
    }
    else if (r == p) { //if r and p are equal
        if (r < q) { // if r is less than q
            minNum = r; //assign the variable to r
        }
        else if (q < r) { //if q is less than r
            minNum = q; //assign the variable to q
        }
    }
    else if (p == q) { //if p and q are equal
        if (r < p) { // if r is less than p
            minNum = r; //assign the variable to r
        }
        else if (p < r) {  // if p is less than r
            minNum = p; //assign the variable to p
        }
    }
    return minNum; //return the variable
}
int mid(int p, int q, int r) { //find the middle number
    int midNum = q; //store the middle num in this variable with an initial value
    if (p < q && p < r) { //if p is the smallest number
        if (q > r) { //if q is greater than r
            midNum = r; //the middle number is r
        }
        else if (q < r) { //if q is less than r
            midNum = q; // the middle number is q
        }
    }
    else if (r < q && r < p) { //if r is the smallest number
        if (q > p) { //if q is greater than p
            midNum = p; //the middle number is p
        }
        else if (q < p) { //if q is less than p
            midNum = q; //the middle number is q
        }
    }
    else if (q < r && q < p) { // if q is the smallest number
        if (r > p) { //if r is greater than p
            midNum = p; //p is the middle number
        }
        else if (r < p) { //if r is less than p
            midNum = r; // ri is the middle number
        }
    }
    else if (r == q) { // if r and q are the same
        midNum = q; //q is the middle number
    }
    else if (r == p) { // if r and p are the same
        midNum = r; //r is the middle number
    }
    else if (p == q) { // if p and q are the same
        midNum = p; //p is the middle number
    }
    else if (p == q && r == p) { // if all of the numbers are equal
        midNum = r; //r is the middle number
    }
    return midNum; //return the middle number
}
