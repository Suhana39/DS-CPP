#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX], front, rear;

public:
    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Overflow\n"; return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Underflow\n"; return;
        }
        cout << "Removed: " << arr[front++] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Empty Queue\n"; return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int ch, val;

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
        }
    } while (ch != 0);
}
