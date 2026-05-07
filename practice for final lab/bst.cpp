#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;

    // Insert recursively
    Node* insertRec(Node* root, int key) {
        if (root == NULL)
            return new Node(key);

        if (key < root->data)
            root->left = insertRec(root->left, key);
        else if (key > root->data)
            root->right = insertRec(root->right, key);

        return root;
    }

    // Inorder traversal
    void inorderRec(Node* root) {
        if (root == NULL) return;
        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }

    void preorderRec(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node* root) {
        if (root == NULL) return;
        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->data << " ";
    }

    // Find minimum node in right subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    // Delete node
    Node* deleteRec(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->data)
            root->left = deleteRec(root->left, key);

        else if (key > root->data)
            root->right = deleteRec(root->right, key);

        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    // LCA function
    Node* LCA(Node* root, int t1, int t2) {
        if (root == NULL) return 0;

        if (t1 < root->data && t2 < root->data)
            return LCA(root->left, t1, t2);

        else if (t1 > root->data && t2 > root->data)
            return LCA(root->right, t1, t2);

        return root;
    }
    int sumNode(Node* root){
    if(root==NULL) return 0;

    return root->data+sumNode(root->left)+sumNode(root->right);
    }
void in_order(Node *root,int &prev,int &mindif){
if(root==NULL) {return;}
in_order(root->left,prev,mindif);
if(prev!=-1) min(mindif , root->data - prev);
    in_order(root->right,prev,mindif);
}
public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    void printLCA(int t1, int t2) {
        Node* lca = LCA(root, t1, t2);
        if (lca)
            cout << "LCA of " << t1 << " and " << t2 << " = " << lca->data << endl;
        else
            cout << "LCA not found\n";
    }
    int sumNode(){
    return sumNode(root);
    cout<<endl;
    }
int mindif(){
int prev=-1;
int mindif=INT_MAX;
prev=root->data;
in_order(root,prev,mindif);
return mindif;
}
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Deleting 20\n";
    bst.deleteNode(20);
    bst.inorder();

    cout << "Deleting 30\n";
    bst.deleteNode(30);
    bst.preorder();

    cout << "Deleting 50\n";
    bst.deleteNode(50);
    bst.postorder();

    cout << "\n";
    bst.printLCA(60, 80);
    cout<<"sum of node:"<<endl;
    int sum=bst.sumNode();
    cout<<sum;
    cout << "Minimum Difference = " << bst.mindif();

    return 0;
}
