#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = 0;
    }

    void push(char x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        char x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    bool isEmpty() {
        return top == 0;
    }
};


string OddorEven(int num) {
    if (num % 2 == 0) {
        return "even";
    }
    else {
        return "odd";
    }
} 

string Binary(int n) {
    if (n == 0) return "0";
    Stack stack;
    while (n > 0) {
        stack.push('0' + n % 2);
        n /= 2;
    }
    string binary;
    while (!stack.isEmpty()) {
        binary += stack.pop();
    }
    return binary;
}

string Hexadecimal(int n) {
    if (n == 0) return "0";
    Stack stack;
    while (n > 0) {
        int rem = n % 16;
        if (rem < 10) {
            stack.push('0' + rem);
        }
        else {
            stack.push('A' + rem - 10);
        }
        n /= 16;
    }
    string hexa;
    while (!stack.isEmpty()) {
        hexa += stack.pop();
    }
    return hexa;
}

string Octal(int n) {
    if (n == 0) return "0";
    Stack stack;
    while (n > 0) {
        stack.push('0' + n % 8);
        n /= 8;
    }
    string octal;
    while (!stack.isEmpty()) {
        octal += stack.pop();
    }
    return octal;
}

int main() {
    int num;
    while (true) {
        cout << "Enter a positive number : ";
        cin >> num;
        if (num > 0)
            break;
        else
            cout << "Invalid input please enter a positive number " << endl;
    }

    string number = OddorEven(num);
    cout << "the number is :" << number << endl;

    int choice;
    cout << "Choose the numbering system you want : " << endl;
    cout << "1. Binary" << endl;
    cout << "2. Hexadecimal" << endl;
    cout << "3. Octal" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Binary : " << Binary(num) << endl;
        break;
    case 2:
        cout << "Hexadecimal : " << Hexadecimal(num) << endl;
        break;
    case 3:
        cout << "Octal : " << Octal(num) << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        return 1;
    }

    return 0;
}