#include<iostream>
#include<iomanip>
using namespace std;

const int maxn = 10;
int arr[maxn];
int head=0, tail=-1;
bool over = false;

bool empty(){
    return (head=tail=0);
}

int length(){
    if(!over) return (tail-head+1);
    else return (maxn-head+tail+1);
}

bool full(){
    return (length()==maxn);
}

void update_queue(){
    if(head <= tail) over = false;
    else over = true;
}

void enqueue(int value){
    if(full()){
        cout << "\nQueue is full";
        return;
    } else{
        if(tail==maxn-1){
            tail = -1;
            arr[++tail] = value;
        } else arr[++tail] = value;
    } 
    update_queue();
}

int peek(){
    return (arr[head]);
}

void dequeue(){
    if(head == maxn-1){
        arr[head] = 0;
        head=0;
    } else{
        arr[head]=0;
        ++head;
    }
    update_queue();
}

void print(){
    if(!over)   for(int i=head; i<tail; i++) cout << arr[i] << ' ';
    else{
        for(int i=head; i<maxn-1; i++) cout << arr[i] << ' ';
        for(int i=0; i<tail; i++) cout << arr[i] << ' ';
    }
}

void queue_by_circle_array(){
    for(int i=1; i<=5; i++) enqueue(i);     // 1 2 3 4 5
    for(int i=1; i<=4; i++) dequeue();      // 5
    for(int i=1; i<=5; i++) enqueue(i);     // 5 1 2 3 4 5
    dequeue();  // 1 2 3 4 5
    for(int i=6; i<=9; i++) enqueue(i); 
    for(int i=1; i<=5; i++) dequeue();
    enqueue(1);
    
    
    cout << "array(front-end): ";
    print();
    
    
    // quan sat index trong mang 1 cach truc quan
    cout << "\n\n" << setw(20) << left << "index: ";
    for(int i=0; i<10; i++) cout << i << ' ';
    // cout toan bo de xem su bien doi
    cout << "\n" << setw(20) << left << "array(back-end): ";
    for(int x: arr) cout << x << ' ';
    // cout do dai
    cout << "\nlength = " << length();
    // kiem tra vi tri cua head va tail
    cout << "\nhead = " << head << "\ntail = " << tail;
    // kiem tra tinh trang mang co bi tran hay khong
    cout << (over?"\nover":"\nnot over");   
    
    
}

int main(){
    queue_by_circle_array();
    cout << endl;
    system("pause");
    return 0;
}