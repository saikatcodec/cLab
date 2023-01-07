#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

bool checkIsEqual(BinaryTreeNode<int> *root) {
    return root->data == (root->left->data + root->right->data);
}

int main() {
    int rootData, leftData, rightData;
    cout << "Enter root data: ";
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    cout << "Enter left children: ";
    cin >> leftData;
    BinaryTreeNode<int> *leftChildren = new BinaryTreeNode<int>(leftData);

    cout << "Enter right children: ";
    cin >> rightData;
    BinaryTreeNode<int> *rightChildren = new BinaryTreeNode<int>(rightData);

    root->left = leftChildren;
    root->right = rightChildren;

    if (checkIsEqual(root)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    delete root;

    return 0;
}