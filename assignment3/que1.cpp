#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // (i) PUSH operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }

    // (ii) POP operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    // (iii) Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // (iv) Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // (v) Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // (vi) Peek at the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Operations Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Is Empty?\n";
        cout << "4. Is Full?\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is NOT empty.\n";
            break;
        case 4:
            if (s.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is NOT full.\n";
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
