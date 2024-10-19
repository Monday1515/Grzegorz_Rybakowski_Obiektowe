#include <iostream>
using namespace std;

class BSTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int value) {
        if (!node) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        }
    }

    bool contains(Node* node, int value) const {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) return contains(node->left, value);
        return contains(node->right, value);
    }

    void clear(Node*& node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }

    void printInOrder(Node* node) const {
        if (node) {
            printInOrder(node->left);
            cout << node->data << " ";
            printInOrder(node->right);
        }
    }

public:
    BSTree() : root(nullptr) {}

    ~BSTree() {
        clear();
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void insert(int value) {
        insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    void clear() {
        clear(root);
    }

    void printInOrder() const {
        printInOrder(root);
    }
};

int main() {
    BSTree bst;
    cout << (bst.isEmpty() ? "Tree is empty" : " Tree is not empty ") << endl;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);
    cout << (bst.isEmpty() ? " Tree is empty " : " Tree is not empty ") << endl;
    cout << "Tree contains element with the value of 3: " << bst.contains(3) << endl;
    cout << "Tree contains element with the value of 9: " << bst.contains(9) << endl;
    bst.printInOrder();
    cout << endl;
    bst.clear();
    cout << (bst.isEmpty() ? " Tree is empty " : " Tree is not empty ") << endl;

    return 0;
}
