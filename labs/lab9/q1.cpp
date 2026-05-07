#include <iostream>
#include <stack>
using namespace std;
#include <iostream>
#include <stack>
using namespace std;
class TreeNode{
public:
int val;
TreeNode *left, *right;
TreeNode(int value) {
val = value;
left = right = NULL;
}
};
class BinarySearchTree{
public:
TreeNode* root;
BinarySearchTree(){
root=NULL;
}
void insert(int key){
root=insertRec(root, key);
}
void deleteNode(int key){
root=deleteRec(root, key);
}
void inorder(){
inorderRec(root);
cout<<endl;
}
void preorderTraversal(){
if(root == NULL)
return;
stack<TreeNode*>st;
st.push(root);
while(!st.empty()){
TreeNode* curr = st.top();
st.pop();
cout<< curr->val<<" ";
if (curr->right != NULL)
st.push(curr->right);
if (curr->left != NULL)
st.push(curr->left);
}
cout << endl;
}
void postorderTraversal(){
if(root == NULL)
return;
stack<TreeNode*> a1, a2;
a1.push(root);
while(!a1.empty()){
TreeNode* curr=a1.top();
a1.pop();
a2.push(curr);
if (curr->left!=NULL)
a1.push(curr->left);
if(curr->right!=NULL)
a1.push(curr->right);
}
while(a2.empty()){
cout<<a2.top()->val << " ";
a2.pop();
}
cout<<endl;
}

private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == NULL)
            return new TreeNode(key);

        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);

        return node;
    }

    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == NULL)
            return node;

        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else {
            // One or no child
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Two children: find inorder successor
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void inorderRec(TreeNode* node) {
        if (node != NULL) {
            inorderRec(node->left);
            cout << node->val << " ";
            inorderRec(node->right);
        }
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

    cout << "Preorder traversal (using stack): ";
    bst.preorderTraversal();

    cout << "Postorder traversal (using stack): ";
    bst.postorderTraversal();

    cout << "Deleting 20..." << endl;
    bst.deleteNode(20);

    cout << "Inorder after deleting 20: ";
    bst.inorder();

    return 0;
}


class BinarySearchTree {
public:
    TreeNode* root;

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

    // Preorder traversal using stack
    void preorderTraversal() {
        if (root == NULL)
            return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            cout << curr->val << " ";

            // Push right first so that left is processed first
            if (curr->right != NULL)
                st.push(curr->right);
            if (curr->left != NULL)
                st.push(curr->left);
        }
        cout << endl;
    }

    // Postorder traversal using stack
    void postorderTraversal() {
        if (root == NULL)
            return;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if (curr->left != NULL)
                s1.push(curr->left);
            if (curr->right != NULL)
                s1.push(curr->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
        cout << endl;
    }

private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == NULL)
            return new TreeNode(key);

        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);

        return node;
    }

    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == NULL)
            return node;

        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else {
            // One or no child
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Two children: find inorder successor
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void inorderRec(TreeNode* node) {
        if (node != NULL) {
            inorderRec(node->left);
            cout << node->val << " ";
            inorderRec(node->right);
        }
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

    cout << "Preorder traversal (using stack): ";
    bst.preorderTraversal();

    cout << "Postorder traversal (using stack): ";
    bst.postorderTraversal();

    cout << "Deleting 20..." << endl;
    bst.deleteNode(20);

    cout << "Inorder after deleting 20: ";
    bst.inorder();

    return 0;
}
