#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (top == -1) {
            cout << "Empty Stack\n";
            return;
        }
        cout << "Top: " << arr[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Empty Stack\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int ch, val;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1.Push\n2.Pop\n3.Peek\n4.Display\n0.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
        }
    } while (ch != 0);
}
