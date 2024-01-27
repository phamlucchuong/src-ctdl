#include<iostream>
#include<stack>
using namespace std;
void toBinary(int n){
    stack<int> s;
    while(n > 0){
        s.push(n%2);
        n /= 2;
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
int main(){
    int n; cin >> n;
    toBinary(n);
    cout << endl;
    system("pause");
    return 0;
}