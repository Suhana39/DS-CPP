#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

//////////////////// STACK USING LL ////////////////////
class StackLL {
    Node* top;

public:
    StackLL() { top = NULL; }

    void push(int x) {
        Node* n = new Node{x, top};
        top = n;
        cout << "Pushed: " << x << endl;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (!top) {
            cout << "Stack Empty\n";
            return;
        }
        cout << "Top: " << top->data << endl;
    }

    void display() {
        if (!top) {
            cout << "Stack Empty\n";
            return;
        }
        Node* temp = top;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

//////////////////// QUEUE USING LL ////////////////////
class QueueLL {
    Node *front, *rear;

public:
    QueueLL() { front = rear = NULL; }

    void enqueue(int x) {
        Node* n = new Node{x, NULL};
        if (!rear) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;

        if (!front) rear = NULL;
        delete temp;
    }

    void display() {
        if (!front) {
            cout << "Queue Empty\n";
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

//////////////////// MAIN MENU ////////////////////
int main() {
    StackLL s;
    QueueLL q;

    int ch, sub, val;

    do {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Stack (LL)\n";
        cout << "2. Queue (LL)\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch) {

        // STACK MENU
        case 1:
            do {
                cout << "\n--- STACK MENU ---\n";
                cout << "1.Push\n2.Pop\n3.Peek\n4.Display\n0.Back\n";
                cin >> sub;

                switch (sub) {
                    case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
                    case 2: s.pop(); break;
                    case 3: s.peek(); break;
                    case 4: s.display(); break;
                }
            } while (sub != 0);
            break;

        // QUEUE MENU
        case 2:
            do {
                cout << "\n--- QUEUE MENU ---\n";
                cout << "1.Enqueue\n2.Dequeue\n3.Display\n0.Back\n";
                cin >> sub;

                switch (sub) {
                    case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
                    case 2: q.dequeue(); break;
                    case 3: q.display(); break;
                }
            } while (sub != 0);
            break;
        }

    } while (ch != 0);

    return 0;
}
