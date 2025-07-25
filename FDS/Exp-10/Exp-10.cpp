/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
                    Write C++ program using stack to check whether given expression is well parenthesized or not.
*/


#include <iostream>
using namespace std;

#define SIZE 10

class Stack {
    int top;
    char stk[SIZE];

public:
    Stack() {
        top = -1;
    }

    // Function to push an element into the stack
    void push(char ch) {
        if (isfull()) {
            cout << "Stack Overflow! Cannot push more elements.\n";
            return;
        }
        stk[++top] = ch;
    }

    // Function to pop an element from the stack
    char pop() {
        if (isempty()) {
            cout << "Stack Underflow! Cannot pop element.\n";
            return '\0';
        }
        return stk[top--];
    }

    // Function to check if the stack is full
    bool isfull() {
        return (top == SIZE - 1);
    }

    // Function to check if the stack is empty
    bool isempty() {
        return (top == -1);
    }
};

// Function to check if the given expression is well parenthesized
bool isWellParenthesized(const char *exp) {
    Stack s;
    char ch;

    for (int i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        // Push opening brackets into the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        // Pop corresponding opening brackets for closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isempty()) {
                return false; // No matching opening bracket
            }

            char topChar = s.pop();
            // Check for matching pairs
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return s.isempty(); // If stack is empty, expression is balanced
}

int main() {
    // Student Details
    cout << "\n------------------------------------------------------\n";
    cout << "Name: Bhupen Jitendra Chirmade\n";
    cout << "Class: SE Computer (A)\n";
    cout << "Roll Number: 22\n";
    cout << "------------------------------------------------------\n";

    // Input Expression
    char exp[50];
    cout << "\n\t!! Parenthesis Checker..!!!!\n";
    cout << "\nEnter the expression to check whether it is well parenthesized: ";
    cin >> exp;

    // Check if the expression is well parenthesized
    if (isWellParenthesized(exp)) {
        cout << "\nExpression is well parenthesized.\n";
    } else {
        cout << "\nInvalid Expression! Not well parenthesized.\n";
    }

    return 0;
}
