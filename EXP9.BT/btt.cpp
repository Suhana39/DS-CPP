#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Create tree level-wise
Node* createTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node{val, NULL, NULL};
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            temp->left = new Node{val, NULL, NULL};
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            temp->right = new Node{val, NULL, NULL};
            q.push(temp->right);
        }
    }
    return root;
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

int main() {
    Node* root = NULL;
    int ch;

    do {
        cout << "\n--- BINARY TREE MENU ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                root = createTree();
                break;
            case 2:
                if (!root) cout << "Tree empty\n";
                else { inorder(root); cout << endl; }
                break;
            case 3:
                if (!root) cout << "Tree empty\n";
                else { preorder(root); cout << endl; }
                break;
            case 4:
                if (!root) cout << "Tree empty\n";
                else { postorder(root); cout << endl; }
                break;
        }
    } while (ch != 0);

    return 0;
}
