#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
class stack{
    private:
		node *top;
		int size;
	public:
		stack();// khoi tao
		bool isEmpty();// kiem tra danh sach rong
        void push(int x);  // them ptu
        int pop();  // xoa ptu
        int peek(); // xem gia tri ptu dau tien cua dinh stack
		void print();   // duyet stack
};

stack::stack(){
    top=NULL;
    size=0;
}

bool stack::isEmpty(){
    return (top==NULL);
}

void stack::push(int x){
    node* newNode = new node;
    newNode->data=x;
    newNode->next=NULL;
    if(newNode==NULL){
        cout << "Not enough memory!";
        return;
    }
    newNode->next=top;
    top=newNode;
    ++size;
}

int stack::pop(){
    if(size==0){
        cout << "Stack has no element!";
        return '\0';
    }
    node* temp=top;
    int res=temp->data;
    top=temp->next;
    delete temp;
    return res;
}

int stack::peek(){
    if(top!=NULL) return top->data;
}

void stack::print(){
    for(node* temp=top; temp!=NULL; temp=temp->next) cout << temp->data;
}

void toBinary(int n){
    stack s;
    while(n > 0){
        s.push(n%2);
        n /= 2;
    }
    s.print();
}

int main(){
    int n; cin >> n;
    toBinary(n);
    cout << endl;
    system("pause");
    return 0;
}
