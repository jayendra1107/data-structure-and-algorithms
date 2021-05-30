#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int lomuto_partition(int arr[], int start, int end) {
    int pivot = arr[end-1];
    int i = start-1;
    for(int j=start; j<end-1; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[end-1]);
    return i+1; 
}

void quick_sort(int arr[], int end, int start=0) {
    if(start<end) {
        int pi = lomuto_partition(arr, start, end);

        quick_sort(arr, pi, start);
        quick_sort(arr, end, pi+1);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>> arr[i];
    }
    quick_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
