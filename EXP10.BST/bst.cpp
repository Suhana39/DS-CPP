#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Insert
Node* insert(Node* root, int x) {
    if (!root) return new Node{x, NULL, NULL};
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

// Find minimum (used in deletion)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete
Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // node found
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search
void search(Node* root, int key) {
    if (!root) {
        cout << "Not Found\n";
        return;
    }
    if (root->data == key) {
        cout << "Found\n";
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Height
int height(Node* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    Node* root = NULL;
    int ch, val;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1.Insert\n";
        cout << "2.Delete\n";
        cout << "3.Search\n";
        cout << "4.Inorder\n";
        cout << "5.Preorder\n";
        cout << "6.Postorder\n";
        cout << "7.Height\n";
        cout << "0.Exit\n";

        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                search(root, val);
                break;

            case 4:
                inorder(root); cout << endl;
                break;

            case 5:
                preorder(root); cout << endl;
                break;

            case 6:
                postorder(root); cout << endl;
                break;

            case 7:
                cout << "Height: " << height(root) << endl;
                break;
        }

    } while (ch != 0);

    return 0;
}
