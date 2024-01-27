#include<iostream>
#include<cstring>
using namespace std;
struct node{
    char data;
    node* next;
};
class stack{
    private:
		node *top;
		int size;
	public:
		stack();// khoi tao
		bool isEmpty();// kiem tra danh sach rong
        void push(char x);  // them ptu
        char pop();  // xoa ptu
        char peek(); // xem gia tri ptu dau tien cua dinh stack
		void print();   // duyet stack
};

stack::stack(){
    top=NULL;
    size=0;
}

bool stack::isEmpty(){
    return (top==NULL);
}

void stack::push(char x){
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

char stack::pop(){
    if(size==0){
        cout << "Stack has no element!";
        return '\0';
    }
    node* temp=top;
    char res=temp->data;
    top=temp->next;
    delete temp;
    return res;
}

char stack::peek(){
    if(top!=NULL) return top->data;
}

void stack::print(){
    for(node* temp=top; temp!=NULL; temp=temp->next) cout << temp->data << " ";
}

int prior(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}

int infix_to_postfix(char infix[], char postfix[]){
    stack s;
    int i=0,j=0;
    while(infix[i]!='\0'){
        // neu la toan hang (chu so hoac chu cai), thi them vao hau to
        if(isalpha(infix[i]) || isdigit(infix[i])){
            postfix[j++] = infix[i];
        } else if(infix[i] == '(') s.push(infix[i]);    // neu la dau '(' thi them vao stack
        else if(infix[i] == ')'){       // neu la dau ')' thi dua cac toan tu trong stack vao hau to cho den khi gap dau '('
            while( s.peek()!='(' ) postfix[j++] = s.pop();
            s.pop();        // xoa dau '('
        } else if( infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){  // neu la toan tu
            // so sanh do uu tien cua thuat toan va dua vao stack
            while( !s.isEmpty() && prior(infix[i]) <= prior(s.peek()) ) postfix[j++] = s.pop();
            // dua toan tu vao stack
            s.push(infix[i]);
        }
        i++;
    }

    // dua cac toan tu con lai trong stack vao hau to
    while(!s.isEmpty()) postfix[j++] = s.pop();
    // them phan tu cuoi cung bang '\0' (mang char)
    postfix[j] = '\0';
    return ++j;
}

int main(){
    char infix[100];
    char postfix[100];
    cin >> infix;
    int size=infix_to_postfix(infix, postfix);
    for(int i=0; i<=size; i++) cout << postfix[i];
    cout << endl;
    system("pause");
    return 0;
}
