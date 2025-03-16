#include <iostream>
using namespace std;

void findminmax(int arr[],int n, int &min, int &max){
    min=max=arr[0];
    for (int i=1;i<n;i++){
        if (arr[i]<min){
            min=arr[i];
        }
        if (arr[i]>max){
            max=arr[i];
        }
    }

}

int main(){
    int arr[]={6,7,8,45,63,4,1,3,4,89};
    int n= sizeof(arr)/sizeof(arr[0]);
    int min,max;
    findminmax(arr,n,min,max);
    cout<<"the min value is "<<min<<endl;
    cout<<"the max value is "<<max<<endl;
    return 0;
}



