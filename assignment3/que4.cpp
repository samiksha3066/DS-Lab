#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to check if operator is right associative
bool isRightAssociative(char op) {
    return op == '^';
}

// Function to check if character is operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> opStack;
    string postfix;

    for (char ch : infix) {
        if (isspace(ch)) {
            continue; // Ignore whitespace
        }

        // If operand, add to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            opStack.push(ch);
        }
        // If ')', pop until '(' is found
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty())
                opStack.pop(); // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (!opStack.empty() && opStack.top() != '(' &&
                   (precedence(ch) < precedence(opStack.top()) ||
                    (precedence(ch) == precedence(opStack.top()) && !isRightAssociative(ch)))) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    // Pop remaining operators
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
