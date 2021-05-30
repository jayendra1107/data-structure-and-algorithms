#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int i=0, j=0, k=start;
    int n1 = mid-start;
    int n2  = end-mid;
    int a1[n1], a2[n2];

    for(int it=0; it<n1; it++) {
        a1[it] = arr[start+it];
    }
    for(int it=0; it<n2; it++) {
        a2[it] = arr[mid+it];
    }

    while(i<n1 && j<n2) {
        if(a1[i]>a2[j]) {
            arr[k] = a2[j];
            j++;
        }
        else {
            arr[k] = a1[i];
            i++;
        }
        k++;
    }

    while (j<n2) {
        arr[k] = a2[j];
        j++; k++;
    }

    while(i<n1) {
        arr[k] = a1[i];
        i++; k++;
    }
}

void merge_sort(int arr[], int end, int start=0) {
    if(start < end-1) {
        int mid = (start+end)/2;

        merge_sort(arr, mid, start);
        merge_sort(arr, end, mid);

        merge(arr, start, mid, end);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>> arr[i];
    }
    merge_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}