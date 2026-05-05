#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    void insertBegin(int x) {
        Node* n = new Node{x, head};
        head = n;
    }

    void deleteBegin() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }
};

int main() {
    LinkedList l;
    int ch, val;

    do {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1.Insert\n2.Delete\n3.Display\n4.Search\n0.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> val; l.insertBegin(val); break;
            case 2: l.deleteBegin(); break;
            case 3: l.display(); break;
            case 4: cin >> val; l.search(val); break;
        }
    } while (ch != 0);
}
