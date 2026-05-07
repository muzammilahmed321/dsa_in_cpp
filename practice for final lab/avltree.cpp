#include <iostream>
using namespace std;

class avl {
private:

    struct node {
        int data;
        node* left;
        node* right;
        int height;
        node(int data) {
            this->data = data;
            left = right = NULL;
            height = 1;
        }
    };

    node* root;

    int height(node* n) {
        return n ? n->height : 0;
    }

    void updateHeight(node* n) {
        n->height = 1 + max(height(n->left), height(n->right));
    }

    int getBalance(node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    // RIGHT ROTATION
    node* rotateRight(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;  // new root
    }

    // LEFT ROTATION
    node* rotateLeft(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y; // new root
    }

    // BALANCE NODE
    node* balance(node* n) {
        updateHeight(n);
        int bf = getBalance(n);

        // LEFT HEAVY
        if (bf > 1) {
            if (getBalance(n->left) < 0)       // Left-Right
                n->left = rotateLeft(n->left);
            return rotateRight(n);             // Left-Left
        }

        // RIGHT HEAVY
        if (bf < -1) {
            if (getBalance(n->right) > 0)      // Right-Left
                n->right = rotateRight(n->right);
            return rotateLeft(n);              // Right-Right
        }

        return n; // Already balanced
    }

    // INSERT NODE
    node* insertNode(node* n, int key) {
        if (!n)
            return new node(key);

        if (key < n->data)
            n->left = insertNode(n->left, key);
        else if (key > n->data)
            n->right = insertNode(n->right, key);
        else {
            cout << "Duplicate key " << key << " not inserted.\n";
            return n;
        }

        return balance(n);
    }

    // FIND MIN VALUE NODE
    node* minValueNode(node* n) {
        while (n->left)
            n = n->left;
        return n;
    }

    // DELETE NODE
    node* deleteNode(node* n, int key) {
        if (!n) return n;

        if (key < n->data)
            n->left = deleteNode(n->left, key);

        else if (key > n->data)
            n->right = deleteNode(n->right, key);

        else {
            if (!n->left || !n->right) {
                node* temp = n->left ? n->left : n->right;

                if (!temp) {
                    temp = n;
                    n = NULL;
                } else {
                    *n = *temp;
                }
                delete temp;
            } else {
                node* temp = minValueNode(n->right);
                n->data = temp->data;
                n->right = deleteNode(n->right, temp->data);
            }
        }

        if (!n) return NULL;

        return balance(n);
    }

    void inorderTraversal(node* n) {
        if (!n) return;
        inorderTraversal(n->left);
        cout << n->data << " ";
        inorderTraversal(n->right);
    }

public:
    avl() {
        root = NULL;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    avl tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(20); // Duplicate
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In-order before deletion: ";
    tree.inorder();

    tree.deleteKey(20);

    cout << "In-order after deleting 20: ";
    tree.inorder();

    return 0;
}
