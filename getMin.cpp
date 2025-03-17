#include<iostream>
#include<vector>

using namespace std;

int getMin(int arr[],int n) {
    int minval=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]<minval) {
            minval=arr[i];  
        }

    return minval;
    }
}