/*
    chuong trinh mo phong lop vector trong c++,
    cac ham da duoc em ding nghia va co the su dung: 
        declaration:
            vector();
            vector(size);
            vector(size, value);
            ~vector();
        modifier:
            assign(size, value);
            pop_back();
            insert(position, value);
            erase(position);
            erase(start-position, end-position);
            emplace(position);
            emplace(position, value);
            emplace_back();
            emplace_back(value);
            push_back(value);
            swap(vector);
            clear();
        iterator:
            begin();
            end();
            rbegin();
        capacity:
            size();
            max_size();
            capacity();
            resize(new_size);
            resize(new_size, value);
            empty();
        element access:
            at(position);
            data();
            front();
            back();
*/
#include<iostream>
#include<unistd.h>
using namespace std;
template <typename T>
struct node{
    T data;
    node *next, *prev;
};

template <typename T>
class vector{
    private:
        node<T> *head, *tail;
        int Size=0;
        const int max_Size=1000;
    public:
        // declaration
        vector(){
            head=tail=nullptr;
            Size=0;
        }
        vector(int n){
            while(Size<n){
                this->push_back(0);
            }
        }
        vector(int n, T value){
            this->assign(n,value);
        }
        ~vector(){
            while(head!=nullptr){
                node<T> *temp=head;
                head=head->next;
                delete temp;
            }
            Size=0;
        }

        // modifiers
        void assign(int n, int value){
            while(n--){
                this->push_back(value);
            }
        }
        void pop_back(){
            if(head==nullptr) return;
            node<T> *temp=tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
            --Size;
        }
        void insert(node<T> *Node, T value){
            if(Node==this->end()){
                this->push_back(value);
                return;
            }
            node<T> *newNode = new node<T>();
            newNode->data = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            if(Node==this->begin()){
                head->prev=newNode;
                newNode->next=head;
                head=newNode;
            } else {
                Node->prev->next=newNode;
                newNode->prev=Node->prev;
                newNode->next=Node;
                Node->prev=newNode;
            }
            ++Size;
        }
        void erase(node<T> *Node){
            if(Node==head) head=head->next;
            else if(Node==this->end()){
                this->pop_back();
                delete Node;
                return;
            } else{
                Node->prev->next=Node->next;
                Node->next->prev=Node->prev;
                delete Node;
                --Size;
            }
            delete Node;
            --Size;
        }

        void emplace(node<T> *Node){
            if(Node==this->end()){
                this->push_back(0);
                return;
            }
            node<T> *newNode = new node<T>();
            newNode->data = 0;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            if(Node==this->begin()){
                head->prev=newNode;
                newNode->next=head;
                head=newNode;
            } else {
                Node->prev->next=newNode;
                newNode->prev=Node->prev;
                newNode->next=Node;
                Node->prev=newNode;
            }
            ++Size;
        }
        void emplace(node<T> *Node, T data){
            if(Node==this->end()){
                this->push_back(data);
                return;
            }
            node<T> *newNode = new node<T>();
            newNode->data = data;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            if(Node==this->begin()){
                head->prev=newNode;
                newNode->next=head;
                head=newNode;
            } else {
                Node->prev->next=newNode;
                newNode->prev=Node->prev;
                newNode->next=Node;
                Node->prev=newNode;
            }
            ++Size;
        }
        void emplace_back(){
            this->push_back(0);
        }
        void emplace_back(T value){
            this->push_back(value);
        }
        void push_back(T data){
            node<T> *newNode = new node<T>;
            newNode->data = data;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            if(head==nullptr) head=tail=newNode;
            else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
            ++Size;
        }
       
        void clear(){
            this->~vector();
        }


        // iterator
        node<T> *begin(){
            return head;
        }
        node<T> *end(){
            if(head!=nullptr) return tail->next;
        }
        T *rbegin(){
            T *ptr=new T;
            ptr=&tail->data;
            return ptr;
        }

        // capacity
        int size(){
            return Size;
        }
        int max_size(){
            return max_Size;
        }
        int capacity(){
            return Size*2;
        }
        void resize(int newsize){
            node<T> *temp=head;
            if(newsize<Size){
                int i=Size;
                while(i>newsize && temp!=nullptr){
                    node<T> *del=temp;
                    temp=temp->next;
                    this->pop_back();
                    --i;
                }
            } else if(newsize>Size){
                int i=newsize-Size;
                while(i--){
                    this->push_back(0);
                }
            }
        }
        void resize(int newsize, int value){
            node<T> *temp=head;
            if(newsize<Size){
                int i=Size;
                while(i>newsize && temp!=nullptr){
                    node<T> *del=temp;
                    temp=temp->next;
                    this->pop_back();
                    --i;
                }
            } else if(newsize>Size){
                int i=newsize-Size;
                while(i--){
                    this->push_back(value);
                }
            }
        } 
        bool empty(){
            return (head==nullptr);
        }

        // element access
        T at(int pos){
            if(pos>Size) {
                cout << "Wrong position in std::vector<T>::at() function!";
                sleep(3);
                exit(0);
            }
            int i=0;
            node<T> *temp=head;
            while(temp!=nullptr){
                if(i==pos) return temp->data;
                temp=temp->next;
                ++i;
            }
        }
        T* data(){
            if(head!=nullptr){
                T *ptr=new T;
                ptr=&head->data;
                return ptr;
            }
        }
        T front(){
            return head->data;
        }
        T back(){
            return tail->data;
        }
};

int main(){
    vector<int> v;
    v.push_back(1); // 1
    v.push_back(2); // 1 2
    v.push_back(3); // 1 2 3
    v.push_back(4); // 1 2 3 4
    v.push_back(5); // 1 2 3 4 5
    v.emplace_back(); // 1 2 3 4 5 0
    v.emplace_back(6); // 1 2 3 4 5 0 6
    v.erase(v.begin()); // 2 3 4 5 0 6
    v.pop_back(); // 2 3 4 5 0
    for(node<int> *temp=v.begin(); temp!=v.end(); temp=temp->next){
        cout << temp->data << " ";
    }
    cout << endl;
    cout << v.size() << endl;   // 5
    system("pause");
    return 0;
}