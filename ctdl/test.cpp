#include <iostream>

// Định nghĩa lớp Node để biểu diễn mỗi nút trong cây
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Định nghĩa lớp BinarySearchTree để biểu diễn cây nhị phân tìm kiếm
class BinarySearchTree {
private:
    Node* root;

    // Hàm đệ quy để thêm một giá trị vào cây
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Hàm đệ quy để tìm kiếm một giá trị trong cây
    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Phương thức để thêm một giá trị vào cây
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Phương thức để tìm kiếm một giá trị trong cây
    bool search(int value) {
        return searchRecursive(root, value);
    }
};

int main() {
    BinarySearchTree bst;

    // Thêm các giá trị vào cây
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Tìm kiếm giá trị trong cây
    std::cout << "Tim kiem 40: " << (bst.search(40) ? "Co" : "Khong") << std::endl;
    std::cout << "Tim kiem 90: " << (bst.search(90) ? "Co" : "Khong") << std::endl;

    return 0;
}
