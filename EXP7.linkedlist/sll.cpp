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

    // Insert at beginning
    void insertBegin(int x) {
        Node* n = new Node{x, head};
        head = n;
    }

    // Insert at end
    void insertEnd(int x) {
        Node* n = new Node{x, NULL};
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }

    // Delete from beginning
    void deleteBegin() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // Search
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not Found\n";
    }

    // Display
    void display() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList l;
    int ch, val;

    do {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1.Insert at Beginning\n";
        cout << "2.Insert at End\n";
        cout << "3.Delete from Beginning\n";
        cout << "4.Delete from End\n";
        cout << "5.Search\n";
        cout << "6.Display\n";
        cout << "0.Exit\n";

        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                l.insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                l.insertEnd(val);
                break;

            case 3:
                l.deleteBegin();
                break;

            case 4:
                l.deleteEnd();
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                l.search(val);
                break;

            case 6:
                l.display();
                break;
        }

    } while (ch != 0);

    return 0;
}
