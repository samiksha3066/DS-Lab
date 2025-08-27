#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverse(const string& str) {
    stack<char> charStack;

    // Push all characters onto the stack
    for (char ch : str) {
        charStack.push(ch);
    }

    string reversedStr;

    // Pop characters from the stack and append to reversedStr
    while (!charStack.empty()) {
        reversedStr += charStack.top();
        charStack.pop();
    }

    return reversedStr;
}

int main() {
    string input ="hello";
    cout <<"Original string: " <<input<<endl;
    cout <<"Reversed string: " <<reverse(input)<<endl;

    return 0;
}
