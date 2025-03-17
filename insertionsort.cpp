#include <iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    
    }

}
int main(){
    int arr[]={4,7,2,4,6,8,9,0,8,19};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);

    cout<<"The sorted will be";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}