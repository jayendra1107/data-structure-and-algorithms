#include <iostream>
using namespace std;

void insert_in_sorted(int arr[], int n, int num) {
    n=n-1;
    while(n>=0 && arr[n]>num) {
        arr[n+1] = arr[n];
        n--;
    }
    arr[n+1] = num;
}

void insertion_sort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        if(arr[i]<arr[i-1]) {
            insert_in_sorted(arr, i, arr[i]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>> arr[i];
    }
    insertion_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}