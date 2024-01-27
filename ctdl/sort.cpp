#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]) min = j;
        }
        if(i!=min) swap(arr[i],arr[min]);
    }
}

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
            else break;
        }
    }
}

void merge(int a[], int l, int m, int r){
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i=0, j=0;
    while(i<x.size() && j<y.size()){
        if(x[i] <= y[j]) a[l++] = x[i++];
        else a[l++] = y[j++];
    }
    while(i<x.size()){
        a[l] = x[i];
        ++l;
        ++i;
    }
    while(j<y.size()){
        a[l] = y[j];
        ++l;
        ++j;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


// phan hoach lomuto
int lomuto_partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            ++i;
            if(i!=j) swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i],arr[right]);
    return i;
}


//  phan hoach hoare
int hoare_partition(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left - 1;
    int j = right + 1;
    while(true){
        do{
            ++i;
        } while(arr[i] < pivot);

        do{
            --j;
        } while(arr[j] > pivot);

        if(i < j){
            swap(arr[i],arr[j]);
        } else return j;
    }
}

void quickSort(int arr[], int left, int right){
    if(left >= right) return;
    int pivot = lomuto_partition(arr, left, right);
    // int pivot = hoare_partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}


int main(){
    int arr[7] = {3,6,2,1,4,5,0};
    // mergeSort(arr,0,2);
    quickSort(arr,0,7-1);
    for(int x: arr) cout << x << ' ';
    cout << endl;
    system("pause");
    return 0;
}