#include <math.h>
#include <stdio.h>

//insertion sort
void insertionsort(int arr[], int N) {
    int i,key,j;
    for (int i=1; i<N; i++){
        key=arr[i];
        j=i-1;
        while (j>=0&& arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    }
}

int main(){
    int arr[]={12,11,3,6,7,8,9,23,4};
    int N=sizeof(arr)/sizeof(arr)[0];

    printf("Unsorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calling insertion sort on array arr
    insertionsort(arr, N);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0; 


}