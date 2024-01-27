#include <iostream>

using namespace std;

class node{
private:
    int data;
    node* left;
    node* right;

    node(int value = 0) : data(value), left(nullptr), right(nullptr){}

    friend class binarySearchTree;
};

class binarySearchTree{
private:
    node* root;

    // private function
    node* insertRecursive(node* Node, int value){
        if(Node == nullptr) {
            return new node(value);
        }
        if(value < Node->data)
            Node->left = insertRecursive(Node->left, value);
        else if(value > Node->data)
            Node->right = insertRecursive(Node->right, value);

        return Node;
    }

    bool searchRecursive(node* Node, int value){
        if(Node == nullptr) return false;

        if(value == Node->data) return true;
        else if(value < Node->left->data)
            return searchRecursive(Node->left, value);
        else if(value > Node->right->data)
            return searchRecursive(Node->right, value);

    }

    void preOrderRecursive(node* temp){
        if (temp != nullptr) {
            std::cout << temp->data << " ";
            preOrderRecursive(temp->left);
            preOrderRecursive(temp->right);
        }
    }

    void inOrderRecursive(node* temp){
        if (temp != nullptr) {
            inOrderRecursive(temp->left);
            std::cout << temp->data << " ";
            inOrderRecursive(temp->right);
        }
    }

    void postOrderRecursive(node* temp){
        if (temp != nullptr) {
            postOrderRecursive(temp->left);
            postOrderRecursive(temp->right);
            std::cout << temp->data << " ";
        }
    }

    int negative_sum_Recursive(node* temp){
        if (temp == nullptr) {
            return 0;
        }

        int sum = 0;
        if (temp->data < 0) {
            sum += temp->data;
        }

        sum += negative_sum_Recursive(temp->left);
        sum += negative_sum_Recursive(temp->right);

        return sum;
    }

    int positive_sum_Recursive(node* temp){
        if (temp == nullptr) {
            return 0;
        }

        int sum = 0;
        if (temp->data > 0) {
            sum += temp->data;
        }

        sum += positive_sum_Recursive(temp->left);
        sum += positive_sum_Recursive(temp->right);

        return sum;
    }

    void biggerRecursive(node* temp, int x){
        if (temp != nullptr) {
            biggerRecursive(temp->left, x);
            if (temp->data > x) {
                cout << temp->data << " ";
            }
            biggerRecursive(temp->right, x);
        }
    }

    void smallerRecursive(node* temp, int x){
        if (temp != nullptr) {
            smallerRecursive(temp->left, x);
            if (temp->data < x) {
                cout << temp->data << " ";
            }
            smallerRecursive(temp->right, x);
        }
    }

    void printRangeRecursive(node* temp, int a, int b){
        if (temp != nullptr) {
            if (temp->data >= a && temp->data <= b) {
                cout << temp->data << " ";
            }
            if (temp->data > a) {
                printRangeRecursive(temp->left, a, b);
            }
            if (temp->data < b) {
                printRangeRecursive(temp->right, a, b);
            }
        }
    }

public:
    binarySearchTree() : root(nullptr){}
    void insert(int value){
        root = insertRecursive(root, value);
    }
    bool search(int value){
        return searchRecursive(root, value);
    }
    bool contain_0val(){
        return searchRecursive(root, 0);
    }
    int max_val();
    int min_val();
    int height();
    int negative_sum();
    int positive_sum();
    void preOrder();
    void inOrder();
    void postOrder();
    void biggerX(int x);
    void smallerX(int x);
    void val_in_range(int x, int y);
};

int binarySearchTree::max_val(){
    if(root == nullptr) return -1;
    node* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->data;
}

int binarySearchTree::min_val(){
    if(root == nullptr) return -1;
    node* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->data;
}

int binarySearchTree::height(){
    if(root == nullptr) return -1;
    node* temp = root;
    int count = 0;
    while (temp->left != nullptr) {
        ++count;
        temp = temp->left;
    }
    return count;
}

int binarySearchTree::negative_sum(){
    this->negative_sum_Recursive(root);
}

int binarySearchTree::positive_sum(){
    this->positive_sum_Recursive(root);
}

void binarySearchTree::preOrder(){
    this->preOrderRecursive(root);
}

void binarySearchTree::inOrder(){
    this->inOrderRecursive(root);
}

void binarySearchTree::postOrder(){
    this->postOrderRecursive(root);
}

void binarySearchTree::biggerX(int x){
    this->biggerRecursive(root, x);
}

void binarySearchTree::smallerX(int x){
    this->smallerRecursive(root, x);
}

void binarySearchTree::val_in_range(int x, int y){
    this->printRangeRecursive(root, x, y);
}


int main(){
    binarySearchTree bst;
    bst.insert(5);
    bst.insert(2);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);
    bst.insert(0);
    bst.insert(3);
    bst.insert(8);
    bst.preOrder();
    cout << endl;
    bst.inOrder();
    cout << endl;
    bst.postOrder();
    cout << endl;
    system("pause");
    return 0;
}