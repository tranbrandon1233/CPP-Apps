#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include "Set.h"

using namespace std;
int evaluate(string infix, const Set& trueValues, const Set& falseValues, string& postfix, bool& result){
    postfix = "";  // clear postfix
    stack<char> opStack;  //Stack to store operators
    int topPriority = 1;  //Track priorities of chars
    int charPriority = 1;
    int errTrack = 0;  // start with error tracker at 0
    int paranthesesTrack = 0;  // parentheses counter
    bool containsTrue, containsFalse; //Track if char is in true or false
    stack<bool> operandStack; //Create stack to store operands
	bool op1, op2;  //Create bools to store results of operands
    for (char ch : infix) {   //Repeat for every character in infix eqn
        switch (ch) {   //Check for each character
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h':  //If ch is a letter
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            if (errTrack) {
                return 1;  // should be at state 0
            }
            postfix += ch; //Add character to postfix
            errTrack = 1;
            break;
        case '(': // If ch is a left parenthesis
            if (errTrack) { //Return 1 if invalid infix format
                return 1;
            }
            errTrack = 0; //Update error tracker
			paranthesesTrack++;  // add to parantheses count
            opStack.push('(');  // push left parenthesis to the stack
            break;
        case ')':  //If ch is a right parenthesis
            if (!errTrack) {
                return 1; //Return 1 if invalid infix format
            }
            paranthesesTrack--; //Decrement parantheses tracker
            if (paranthesesTrack < 0) { //Return 1 if parantheses is less than 0
                return 1;
            }
            errTrack = 1;
            while (opStack.top() != '(') {  //Add char to postfix until left paranthesis is found
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();  // pop the left paranthesis
            break;
        case '&': case '|':  //If ch is an & or | operator
            if (!errTrack) {
                return 1; //Return 1 if invalid infix format
            }
            errTrack = 0; //Reset error tracker
            if (opStack.empty()) {  //If stack is empty, push set topPriority to 
				topPriority = 1;
			}
            else { //If not,
                if (opStack.top() == '!') {  //Check priority of top of stack
                    topPriority = 3;
                }
                else if (opStack.top() == '&') {
                    topPriority = 2;
                }
                else if (opStack.top() == '|') {
                    topPriority = 1;
                }                
                else{
                    topPriority = 1;
                }
                if (ch == '!') {  //Check priority of char
                    charPriority = 3;
                }
                else if (ch == '&') {
                    charPriority = 2;
                }
                else if (ch == '|') {
                    charPriority = 1;
                }
                else {
                    charPriority = 1;
                }
            }
            while (!opStack.empty() && opStack.top() != '(' &&  //Loop while stack is not empty, left paranthesis is not found, and priority of top of stack is greater than or equal to priority of char
                charPriority <= topPriority) {
                postfix += opStack.top();  //Add top of stack to postfix and remove it
                opStack.pop();
            }
            opStack.push(ch);  //Add the char to the stack
            break;
        case '!':  //If the char is the unary operator
            opStack.push(ch);  //Push immediately
            break;
        case ' ':  //Break for blank spaces
            break;
        default:   //return 1 for all other cases
            return 1;
        }
    }
    if (!errTrack || paranthesesTrack) {
        return 1; //Return 1 if error tracker or parantheses tracker are invalid
    }
    while (!opStack.empty()) {  //For entire stack, add it to postfix eqn and remove
        postfix += opStack.top();
        opStack.pop();
    }
    for (char ch : postfix) { //Loop for all chars in postfix
        switch (ch) {  //Switch for each char case
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h':  case 'i':  case 'j':  case 'k':  case 'l':  case 'm':  case 'n':  case 'o':  case 'p':  case 'q':  case 'r':
        case 's': case 't':  case 'u':  case 'v':  case 'w':  case 'x':  case 'y':  case 'z': //If char is a letter
			//Check if char is in both or neither of the sets and return 2 or 3 respectively
            if (!falseValues.contains(ch) && !trueValues.contains((ch))) return 2;
            if (falseValues.contains(ch) && trueValues.contains((ch))) return 3; 
            //Check if set contains true or false values and push to operandStack accordingly
            if (trueValues.contains((ch)))   operandStack.push(true);
            if (falseValues.contains((ch)))  operandStack.push(false);

            break;
            // Case for OR and AND chars
        case '|':
        case '&':
			op1 = operandStack.top(); //Store the next two chars from the stack and remove them
            operandStack.pop();
            op2 = operandStack.top();
            operandStack.pop();
			if (ch == '|') //If it is an OR, push the OR of the two operands to the stack
                operandStack.push(op1 || op2);
            else if (ch == '&') //If it is an AND, push the AND of the two operands to the stack
                operandStack.push(op1 && op2);
            break;
            // Case for NOT char
        case '!':
            op1 = operandStack.top();
            operandStack.pop();
            operandStack.push(!op1);
            break;

        }
    }
	result = operandStack.top();  //Set result to top of stack and return 0
    return 0;
    
}

int main()
{
   
        string trueChars = "tywz";
        string falseChars = "fnx";
        Set trues;
        Set falses;
        for (int k = 0; k < trueChars.size(); k++)
            trues.insert(trueChars[k]);
        for (int k = 0; k < falseChars.size(); k++)
            falses.insert(falseChars[k]);

        string pf;
        bool answer;
        assert(evaluate("w| f", trues, falses, pf, answer) == 0 && pf == "wf|" && answer);
        assert(evaluate("y|", trues, falses, pf, answer) == 1);
        assert(evaluate("n t", trues, falses, pf, answer) == 1);
        assert(evaluate("nt", trues, falses, pf, answer) == 1);
        assert(evaluate("()", trues, falses, pf, answer) == 1);
        assert(evaluate("()z", trues, falses, pf, answer) == 1);
        assert(evaluate("y(n|y)", trues, falses, pf, answer) == 1);
        assert(evaluate("t(&n)", trues, falses, pf, answer) == 1);
        assert(evaluate("(n&(t|y)", trues, falses, pf, answer) == 1);
        assert(evaluate("n+y", trues, falses, pf, answer) == 1);
        assert(evaluate("", trues, falses, pf, answer) == 1);
        assert(evaluate("f  |  !f & (t&n) ", trues, falses, pf, answer) == 0);
        assert(evaluate(" x  ", trues, falses, pf, answer) == 0 && pf == "x" && !answer);
        trues.insert('x');
        assert(evaluate("((x))", trues, falses, pf, answer) == 3);
        falses.erase('x');
        assert(evaluate("((x))", trues, falses, pf, answer) == 0 && pf == "x" && answer);
        trues.erase('w');
        assert(evaluate("w| f", trues, falses, pf, answer) == 2);
        falses.insert('w');
        assert(evaluate("w| f", trues, falses, pf, answer) == 0 && pf == "wf|" && !answer);
        cout << "Passed all tests" << endl;
    
}