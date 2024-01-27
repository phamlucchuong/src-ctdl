#include<iostream>
using namespace std;
bool linear_Search(int arr[], int num, int value){
    for(int i=0; i<num; i++){
        if(arr[i] == value) return true;
    }
    return false;
}
bool binary_search(int arr[], int num, int value){
    int left=0, right=num-1;
    int mid=(left+right)/2;
    while(left <= right){
        if(value == arr[mid]) return true;
        else {
            if(value < arr[mid]) right = mid-1;
            else left = mid+1;
            mid=(left+right)/2;
        }
    }
    return false;
}
/*
    hàm băm
        1. phương pháp chia: lấy số phần tử chia lấy dư cho key (thường là số nguyên tố) dư r thì 
        phần tử được thêm vào mảng có chỉ số r
        *trường hợp bị trùng r thì sử dụng phương pháp
            1. phương pháp kết nối: dùng dslk tạo mảng để lưu trữ
            2. phương pháp đo tuyến tính: kiểm tra ô nhớ tiếp theo có trống hay không,
            nếu có thì thêm phần tử vào,không thì kiểm tra tiếp các ô nhớ tiếp theo
*/
int main(){
    // int arr[5];
    // for(int i=1; i<=10; i++) arr[i] = i;
    // if(binary_search(arr,10,1)) cout << "Found!";
    // else cout << "Not found!";
    int a[9] = {0, 56, 56, 21, 84, 22, 6, 34, 8};
    for(int x:a) cout << x%9 << " ";
    cout << endl;
    system("pause");
    return 0;
}