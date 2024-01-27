#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};

class dll{
    private:
        node* head;
        node* tail;
        int size;
    public:
        dll();
        bool isEmpty();// kiem tra danh sach rong
		int length();//so luong phan tu
		node* createNode(int x);
		void insert(int pos, int x);
		void insertFirst(int x);// chen dau
		void insertLast(int x);//chen cuoi
		void remove(int pos);
		void removeFirst();
		void removeLast();//xoa cuoi
		void print();
};
dll::dll(){
    head=tail=NULL;
    size=0;
}

bool dll::isEmpty(){
    return (head==NULL);
}

int dll::length(){
    return size;
}

node* dll::createNode(int x){
    node* newNode=new node;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void dll::insert(int pos, int x){// moi lam them
	if(pos==1) this->insertFirst(x);
	else if(pos==this->size+1) this->insertLast(x);
	else {
		node *newNode = createNode(x);
		node* temp=this->head;
		int i=0;
		while(temp!=NULL){
			++i;
			if(i == pos) {
                temp->prev->next=newNode;
                newNode->prev=temp->prev;
				temp->prev = newNode;
				newNode->next = temp;
			}
			temp = temp->next;
		}
		this->size++;
	}
}

void dll::insertFirst(int x){
    node* newNode=createNode(x);
    if(head==NULL) head=tail=newNode;
    else {
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
    ++size;
}

void dll::insertLast(int x){
    node* newNode=createNode(x);
    if(head==NULL) head=tail=newNode;
    else {
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
    ++size;
}

void dll::remove(int pos){ // moi lam them
    if(pos>this->size){
        cout << "This dll has only " << this->size << " elements TvT ";
        return;
    }
	if(pos==1) this->removeFirst();
	else if(pos==this->size) this->removeLast();
	else{
		int i=0;
		node* temp = head;
		while(temp!=NULL){
			i++;
			if(i == pos) {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
				delete temp;
				this->size--;
				return;
			}
			temp = temp->next;
		}
	}
}

void dll::removeFirst(){ // moi lam them
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
    node* temp=this->head;
	head=temp->next;
    head->prev=NULL;
    delete temp;
	this->size--;
}

void dll::removeLast(){ // moi sua lai
	if(head==NULL){
		cout<<"List is empty";
		return;
	} else{
        node* temp=tail;
		tail=tail->prev;
        tail->next=NULL;
		delete temp;
		this->size--;
	}
}

void dll::print(){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main(){
    dll s;
    s.insertFirst(3); // 3
    s.insertFirst(2); // 2 3
    s.insertFirst(1); // 1 2 3
    s.insertLast(4); // 1 2 3 4
    s.insertLast(5); // 1 2 3 4 5
    s.insert(1,0); // 0 1 2 3 4 5
    s.insert(5,6); // 0 1 2 3 6 4 5
    s.insert(8,7); // 0 1 2 3 6 4 5 7
    s.removeLast(); // 0 1 2 3 6 4 5
    s.removeFirst(); // 1 2 3 6 4 5
    s.remove(4); // 1 2 3 4 5
    s.print();
    cout << endl;
    system("pause");
    return 0;
}