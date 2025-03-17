#include <iostream>
using namespace std;

int Linearsearch(int arr[], int n , int target){
    for (int i=0; i<n ;i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={4,5,6,45,6,7,89,1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"which number do you wanna check is there or not? "<<endl;
    cin>>target;
    int result=Linearsearch(arr,n,target);
    if (result==-1){
        cout<<"the number is not found"<<endl;
    }else{
        cout<<"The target number is found at index "<<result<<endl;
    }
    return 0;
}