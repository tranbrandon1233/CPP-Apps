// Author: Brandon Tran
//Date: 5/20/20
//Purpose: Find max, min, sum. and average of set of numbers and find position of each number in the array.
int A[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int N; // number of integers to be processed per user’s request
int K; // key number to be search in A[20] array per user’s request 
int pos; // position for the number K found in A[20] array, -1 if not found
int posFound; //Check if number is in A[20] array

#include <iostream>

using namespace::std;
int max(int A[20], int N); // return max of first N integers in array A
int min(int A[20], int N); // return min of first N integers in array A
int sum(int A[20], int N); // return sum of first N integers in array A
int avg(int A[20], int N); // return average of first N integers in array A
void show(int A[20], int N); // print the first N integers in array A
int search(int A[20], int N, int K);

int main()
{
    int n = 1;
    cout << "Welcome to the Array Searching Game of Brandon Tran!" << endl;
    cout << n++ << "=================================================================================." << endl;
    while (true) {
        cout << "Please enter how many integers you would like to play (up to 20, 0 to stop) > ";
        cin >> N;
        if (N == 0){
            break;
        }
        else if (N < 0) {
            continue;
        }
        cout << "Please enter " << N << " integers in any order > ";
        for (int num = 0; num < N; num++) {
            cin >> A[num];
       }
        show(A, N);
        cout << "Max is " << max(A, N) << ", Min is " << min(A, N) << ", Sum is " << sum(A, N) << ", and Average is " << avg(A, N) << endl;
        cout << n++ << "=================================================================================." << endl;
        while (true) {
            cout << "Please enter a number to search(-1 to end the search) > ";
            cin >> K;
            if (K == -1) {
                cout << n++ << "=================================================================================." << endl;
                break;
            }
            if (search(A, N, K) == -1) {
                cout << "The number " << K << " is not found." << endl;
            }
            else {
                cout << "The number " << K << " is found at the position " << search(A, N, K) + 1 << endl;
            }
        }
        }
    cout << n++ << "=================================================================================." << endl;
    cout << "Thank you for playing this Array Searching Game of Brandon Tran!" << endl;
    cout << n++ << "=================================================================================." << endl;
}

int max(int A[20], int N) // return max of first N integers in array A
{ /* your code */
    int largestNum = A[0]; //Initialize var to store the largest number
    for (int num = 0; num < N; num++) { //For each item in array,
        if (A[num] > largestNum) { //If a number in the array is larger than the current largest number,
            largestNum = A[num]; //Reassign the largest number as that number in the array
        }
    }
    return largestNum;
}
int min(int A[20], int N) // return min of first N integers in array A
{ /* your code */
    int smallestNum = A[0]; //Initialize var to store the smallest number
    for (int num = 0; num < N; num++) { //For each item in array,
        if (A[num] < smallestNum) { //If a number in the array is smaller than the current smallest number,
            smallestNum = A[num]; //Reassign the smallest number as that number in the array
        }
    }
    return smallestNum;
}
int sum(int A[20], int N) // return sum of first N integers in array A
{ /* your code */
    int sum{}; //Initialize var to store the sum
    for (int num = 0; num < N; num++) { //For each item in array,
        sum += A[num]; //Add to the total sum
    }
    return sum;
}
int avg(int A[20], int N){ // return average of first N integers in array A
    int sum{};
    float average;
    for (int num = 0; num < N; num++) { //For each item in array,
        sum += A[num]; //Add to the total sum
    }
    average = sum / N;
    return average;
}
void show(int A[20], int N) // print the first N integers in array A
{ /* your code */
    cout << "Your " << N << " integers are: ";
    for (int num = 0; num < N; num++) { //For each item in array,
        cout << A[num] << " ";
    }
    cout << endl;
}
int search(int A[20], int N, int K) // return position of K found in array A
{ /* your code */
    for (int pos = 0; pos < N; pos++) {
        if (A[pos] == K && posFound == 0) {
            return pos;
            posFound = 1;
        }
    }
    if (posFound == 0) {
        return -1;
    }
}  // return -1 if K is not found in array A