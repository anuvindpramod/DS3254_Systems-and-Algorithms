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

int main(int argumentcounts, char* arguvector[]){
    if(argumentcounts<2){
        cerr<<"usage"<<arguvector[0]<<"<input file>"<<endl; //cerr is the error showing
        return 1;
    }
    ifstream inputFile(arguvector[1]);
    if (!inputFile){
        cerr<<"Erro opening"<<arguvector[1]<<endl;
        return 1;

    }
    int n;
    inputFile>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        inputFile>>arr[i];
    }
    inputFile.close();
    selectionsort(arr);
    cout<<"sorted arra: ";
    for(int val: arr){
        cout<<val<<"";
    }
    cout<<endl;
    return 0;
}