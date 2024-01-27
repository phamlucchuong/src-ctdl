#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1000;
int n;
int arr[maxn];
void input(){
    cin >> n;
    for(int i=0; i<n; i++) cin > arr[i];
}

bool find_value(){
    
}

void enter(){

}

void hash_function(){
    int key_value = 9;
    vector<int> hash_arr[10];
    for(int i=0; i<n; i++){
        int r = arr[i] % key_value;
        hash_arr[r].push_back(arr[i]);
    }
}
int main(){
    input();
    hash_function();
    cout << endl;
    system("pause");
    return 0;
}