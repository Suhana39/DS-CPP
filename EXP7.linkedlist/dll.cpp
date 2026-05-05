#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    // Insert at beginning
    void insertBegin(int x) {
        Node* n = new Node{x, NULL, head};
        if (head) head->prev = n;
        head = n;
    }

    // Insert at end
    void insertEnd(int x) {
        Node* n = new Node{x, NULL, NULL};
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    // Delete from beginning
    void deleteBegin() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
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
        while (temp->next)
            temp = temp->next;
        temp->prev->next = NULL;
        delete temp;
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

    // Display forward
    void displayForward() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList d;
    int ch, val;

    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1.Insert at Beginning\n";
        cout << "2.Insert at End\n";
        cout << "3.Delete from Beginning\n";
        cout << "4.Delete from End\n";
        cout << "5.Search\n";
        cout << "6.Display Forward\n";
        cout << "7.Display Backward\n";
        cout << "0.Exit\n";

        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                d.insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                d.insertEnd(val);
                break;

            case 3:
                d.deleteBegin();
                break;

            case 4:
                d.deleteEnd();
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                d.search(val);
                break;

            case 6:
                d.displayForward();
                break;

            case 7:
                d.displayBackward();
                break;
        }

    } while (ch != 0);

    return 0;
}
