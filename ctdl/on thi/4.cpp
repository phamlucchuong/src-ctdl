#include<iostream>
#include<vector>
using namespace std;
int i = 0;
void recurs(vector<int>& v, vector<int>& u, int sum) {
    if(v.empty()) return;
    if(v[0] + u[i] == sum) cout << v[0] << ',' << u[i] << endl;
    ++i;
    if(i == u.size()) {
        i = 0;
        v.erase(v.begin());
    }
    recurs(v,u,sum);
}
int main() {
    vector<int> v;
    int num; cin >> num;
    while(num--) {
        int x; cin >> x;
        v.push_back(x);
    }
    int sum; cin >> sum;
    recurs(v, v, sum);
    system("pause");
    return 0;
}