#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
class list{
    private:
        node* head;
        node* tail;
        int size;
    public:
        list();
        bool isEmpty();
        int length();//so luong phan tu
		node* createNode(int x);
		void insertAfter(int val, int x); // them x sau gia tri val
		void insertFirst(int x);// chen dau
		void insertLast(int x);// chen dau
		void remove_Val(int val);   // xoa ptu sau val
		void removeFirst();
		void removeLast();
		void print();
};
list::list(){
    head=tail=NULL;
    size=0;
}

bool list::isEmpty(){
    return (head==NULL);
}

int list::length(){
    return size;
}

node* list::createNode(int x){
    node* newNode=new node;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void list::insertAfter(int val, int x){// moi lam them
    node* temp=head;
    int i=0;
    while(i!=size){
        ++i;
        if(temp->data==val){
            if(i==size){
                this->insertLast(x);
                return;
            }
            else{
                node* newNode=createNode(x);
                newNode->next=temp->next;
                temp->next->prev=newNode;
                temp->next=newNode;
                newNode->prev=temp;
            }
            ++size;
            return;
        }
        temp=temp->next;
    }
    cout << val << " can't be found in list!" << endl;
}

void list::insertFirst(int x){
    node* newNode=createNode(x);
    if(head==NULL) head=tail=newNode;
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        tail->next=head;
        head->prev=tail;
    }
    ++size;
}

void list::insertLast(int x){
    node* newNode=createNode(x);
    if(head==NULL) head=tail=newNode;
    else {
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        tail->next=head;
        head->prev=tail;
    }
    ++size;
}

void list::remove_Val(int val){ // moi lam them
    int i=0;
    node* temp=head;
    while(i!=size){
        ++i;
        if(temp->data==val){
            if(i==1) this->removeFirst();
            else if(i==size) this->removeLast();
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                 delete temp;
                --size;
            }
            return;
        }
        temp=temp->next;
    }
    cout << val << " can't be found in list!" << endl;
}

void list::removeFirst(){ // moi lam them
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
    node* temp=head;
	head=temp->next;
    tail->next=head;
    head->prev=tail;
    delete temp;
	--size;
}

void list::removeLast(){ // moi sua lai
	if(head==NULL){
		cout<<"List is empty";
		return;
    }
    node* temp=tail;
    tail=temp->prev;
    tail->next=head;
    head->prev=tail;
    delete temp;
    --size;
}

void list::print(){
    int i=0;
    node* temp=head;
    while(i!=size){
        cout << temp->data << " ";
        temp=temp->next;
        ++i;
    }
    cout << endl;
}
int main(){
    list l;
    l.insertFirst(1); // 1
    l.insertLast(3); // 1 3
    l.insertAfter(1,2); // 1 2 3
    l.insertAfter(3,4); // 1 2 3 4
    l.insertFirst(0); // 0 1 2 3 4
    l.removeLast(); // 0 1 2 3
    l.remove_Val(3); // 0 1 2
    l.removeFirst(); // 1 2
    l.print(); // 1 2
    cout << l.length() << endl; // 2
    l.remove_Val(5); // not found
    system("pause");
    return 0;
}