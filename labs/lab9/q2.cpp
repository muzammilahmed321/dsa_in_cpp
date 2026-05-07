 #include <iostream>
 #include <string>
 using namespace std;
class EmployeeNode {
 public:
    int id;
    string name;
    string department;
    EmployeeNode* left;
    EmployeeNode* right;
    EmployeeNode(int i, string n, string d) : id(i), name(n), department(d), left(NULL), right(NULL) {}
 };
 class EmployeeBST {
 public:
    EmployeeNode* root;
    EmployeeBST() : root(NULL) {}
    void insert(int id, string name, string department) {
        if (isIDPresent(root, id)) {
            cout << "Duplicate ID " << id << " skipped." << endl;
            return;
        }
        root = insertRec(root, id, name, department);
    }
    bool search(int id) {
        EmployeeNode* found = searchRec(root, id);
        if (found) {
            cout << "Found: ID=" << found->id << ", Name=" << found->name << ", Dept=" << found->department << endl;
            return true;
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
            return false;
        }
    }
    void deleteNode(int id) {
        if (!isIDPresent(root, id)) {
            cout << "Employee with ID " << id << " not found. Deletion skipped." << endl;
            return;
        }
        root = deleteRec(root, id);
        cout << "Deleted employee with ID " << id << "." << endl;
    }
    void inOrderTraversal() {
        cout << "Employees (sorted by ID):" << endl;
        inOrderRec(root);
        cout << endl;
    }
    void findMin() {
        EmployeeNode* minNode = minValueNode(root);
        if (minNode) {
            cout << "Min ID Employee: ID=" << minNode->id << ", Name=" << minNode->name << ", Dept=" <<
minNode->department << endl;
        } else {
            cout << "Tree is empty." << endl;
        }
    }
    void findMax() {
        EmployeeNode* maxNode = maxValueNode(root);
        if (maxNode) {
            cout << "Max ID Employee: ID=" << maxNode->id << ", Name=" << maxNode->name << ", Dept=" <<
maxNode->department << endl;
        } else {
            cout << "Tree is empty." << endl;
        }
    }
 private:
    bool isIDPresent(EmployeeNode* node, int id) {
        if (node == NULL) return false;
        if (id == node->id) return true;
        if (id < node->id) return isIDPresent(node->left, id);
        return isIDPresent(node->right, id);
    }
    EmployeeNode* insertRec(EmployeeNode* node, int id, string name, string department) {
        if (node == NULL) {
            return new EmployeeNode(id, name, department);
        }
        if (id < node->id) {
            node->left = insertRec(node->left, id, name, department);
        } else if (id > node->id) {
            node->right = insertRec(node->right, id, name, department);
        }
        return node;
    }
    EmployeeNode* searchRec(EmployeeNode* node, int id) {
        if (node == NULL || node->id == id) return node;
        if (id < node->id) return searchRec(node->left, id);
        return searchRec(node->right, id);
    }
    EmployeeNode* deleteRec(EmployeeNode* node, int id) {
        if (node == NULL) return node;
        if (id < node->id) {
            node->left = deleteRec(node->left, id);
        } else if (id > node->id) {
            node->right = deleteRec(node->right, id);
        } else {
            if (node->left == NULL) {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }
            EmployeeNode* temp = minValueNode(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->department = temp->department;
            node->right = deleteRec(node->right, temp->id);
        }
        return node;
    }
    EmployeeNode* minValueNode(EmployeeNode* node) {
        while (node && node->left != NULL) node = node->left;
        return node;
    }
    EmployeeNode* maxValueNode(EmployeeNode* node) {
        while (node && node->right != NULL) node = node->right;
        return node;
    }
    void inOrderRec(EmployeeNode* node) {
        if (node != NULL) {
            inOrderRec(node->left);
            cout << "ID=" << node->id << ", Name=" << node->name << ", Dept=" << node->department << endl;
            inOrderRec(node->right);
        }
    }
 };
 int main() {
    EmployeeBST empBST;
    empBST.insert(101, "Muzammil", "HR");
    empBST.insert(102, "Shazeeb", "IT");
    empBST.insert(100, "Rehan ", "Finance");
    empBST.insert(103, "Saqib", "HR");
    empBST.insert(102, "Duplicate", "Test");
    empBST.inOrderTraversal();
    empBST.search(102);
    empBST.search(999);
    empBST.findMin();
    empBST.findMax();
    cout << "\n--- Deleting Employee 102 ---\n";
    empBST.deleteNode(102);
    cout << "\n--- After Deletion ---\n";
    empBST.inOrderTraversal();
    return 0;
 }
