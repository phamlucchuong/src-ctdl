#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
class List{
	private:
		Node *head;
		Node *tail;
		int size;
	public:
		List();// khoi tao
		bool isEmpty();// kiem tra danh sach rong
		int length();//so luong phan tu
		Node* createNode(int x);
		void insert(int pos, int x);
		void insertFirst(int x);// chen dau
		void insertLast(int x);//chen cuoi
		void remove(int pos);
		void removeFirst();
		void removeLast();//xoa cuoi
		void print();
};
List::List(){
	head=tail=NULL;
	size=0;
}
bool List::isEmpty(){
	if(head==NULL)
		return true;
	else
		return false;
}

int List::length(){
	return this->size; 
}

Node* List::createNode(int x){
	Node *p=new Node();// cap phat vung nho cho node p
	p->data=x;
	p->next=NULL;
	return p;
}

void List::insert(int pos, int x){// moi lam them
	if(pos==1) this->insertFirst(x);
	else if(pos==this->size+1) this->insertLast(x);
	else {
		Node *newNode = createNode(x);
		Node* temp=this->head;
		int i=0;
		Node* prev=NULL;
		while(temp!=NULL){
			i++;
			if(i == pos) {
				prev->next = newNode;
				newNode->next = temp;
			}
			prev = temp;
			temp = temp->next;
		}
		this->size++;
	}
}

void List::insertFirst(int x){
	Node *p=createNode(x);
	if(head==NULL){
		head=tail=p;
	}
	else{
		p->next=head;
		head=p;
	}
	size++;
}

void List::insertLast(int x){  // moi lam them
	Node* newNode=createNode(x);
	if(this->size==0) this->head=newNode;
	else {
		Node* temp=this->tail;
		temp->next = newNode;
		this->tail=newNode;
	}
	this->size++;
}

void List::remove(int pos){ // moi lam them
    if(pos>this->size){
        cout << "This list has only " << this->size << " elements TvT ";
        return;
    }
	if(pos==1) this->removeFirst();
	else if(pos==this->size) this->removeLast();
	else{
		int i=0;
		Node* temp = this->head;
		Node* prev = NULL;
		while(temp!=NULL){
			i++;
			if(i == pos) {
				prev->next = temp->next;
				delete temp;
				this->size--;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
}

void List::removeFirst(){ // moi lam them
	if(this->size==0){
		cout<<"List is empty";
		return;
	}
    Node* temp=this->head;
	this->head=temp->next;
	this->size--;
}

void List::removeLast(){ // moi sua lai
	if(this->size==0){
		cout<<"List is empty";
		return;
	} else{
		Node *temp=this->head;
		Node *prev=NULL;
		while(temp->next!=NULL){
			prev=temp;
			temp=temp->next;
		}
		this->tail=prev;
		prev->next=NULL;
		delete temp;
		this->size--;
	}
}
void List::print(){
	for(Node *i=head;i!=NULL;i=i->next){
		cout<<i->data<<"  ";
	}
}


int main(){
	List a;
	a.insertFirst(10); // 10
	a.insertFirst(5); // 5 10
	a.insertLast(20); // 5 10 20
	a.insert(4, 15);// 5 10 20 15
	a.removeFirst();// 10 20 15
	a.removeLast(); // 10 20
	a.remove(2);// 10
	a.print();
	cout << endl << a.length() << endl;
    system("pause");
}