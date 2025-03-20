#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void selectionsort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int minindx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindx]){
                minindx=j;
            }
        }
        swap(arr[i],arr[minindx]);
    }
}

void insertionsort(vector<int>& arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Step 1.3: Merge Sort Function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    cout<<"Enter the number elemenst";
    cin>>n;
    vector<int>arr(n);
    cout << "Enter " << n << " integers:" << endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionsort(arr);
    cout<<"sorted array ";
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}