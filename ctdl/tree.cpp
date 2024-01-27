#include<iostream>
using namespace std;

class node {
    private: 
        int data;
        node* left;
        node* right;
        node(int a) : data(a), left(nullptr), right(nullptr) {}
        friend class bst;
};

class bst {
    private:
        node* root;
    public:
        bst() : root(nullptr){}
        node* add(node* Node, int value);
        void add(int value) { root = add(root, value);}
        bool search(node* Node, int value);
        bool search(int value) {return search(root, value);}
        void preOrder(node* Node);
        void preOrder() {preOrder(root);}
        void inOrder(node* Node);
        void inOrder() {inOrder(root);}
        void postOrder(node* Node);
        void postOrder() {postOrder(root);}
        int height();
};
node* bst::add(node* Node, int value) {
    if(Node == nullptr) return new node(value);
    if(value < Node->data) Node->left = add(Node->left, value);
    else if(value > Node->data) Node->right = add(Node->right, value);
    return Node;
}

bool bst::search(node *Node, int value)
{
    if(Node == nullptr)
        return false;
    if(value == Node->data) return true;
    else if(value < Node->data)
        return search(Node->left, value);
    else return search(Node->right, value);
}

void bst::preOrder(node* Node)
{
    if(Node != nullptr) {
        cout << Node->data << ' ';
        preOrder(Node->left);
        preOrder(Node->right);
    }
}
void bst::inOrder(node* Node)
{
    if(Node != nullptr) {
        inOrder(Node->left);
        cout << Node->data << ' ';
        inOrder(Node->right);
    }
}
void bst::postOrder(node* Node)
{
    if(Node != nullptr) {
        postOrder(Node->left);
        postOrder(Node->right);
        cout << Node->data << ' ';
    }
}

int bst::height()
{
    if(root == nullptr)
        return -1;
    node* temp = root;
    int count = 0;
    while(temp->left != nullptr) {
        ++count;
        temp = temp->left;
    }
    return count;
}

int main() {
    bst t;
    t.add(5);
    t.add(2);
    t.add(7);
    t.add(1);
    t.add(4);
    t.add(6);
    t.add(9);
    t.add(0);
    t.add(3);
    t.add(8);
    // t.preOrder();
    // cout << endl;
    // t.inOrder();
    // cout << endl;
    // t.postOrder();
    // cout << endl;
    cout << t.height();
    system("pause");
    return 0;
}