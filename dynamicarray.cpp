#include <iostream>
using namespace std;

class myArray{
private:
    int* data;
    int capacity;
    int size;

    void resize(){
    int newcapacity=capacity*2;
    int* newdata=new int[newcapacity];
    for(int i=0;i<size;i++){ //copy old data to new array
        newdata[i]=data[i];
    }
    delete[] data;//delete oold array
    data=newdata;
    capacity=newcapacity;
}

public:
    myArray(int cap=10){
        capacity=cap;
        size=0;
        data=new int[capacity];
    }
    ~myArray(){
        delete[] data;
    }

    void insert(int idx, int val){
        if (idx<0 || idx>size){
            cerr<<"error"<<endl;
            return;
        }
        if(size==capacity){
            resize();
        }
        for(int i=size-1;i>=idx;i--){ //shifyed one position to the right
            data[i+1]=data[i];
        }
    }

    void remove(int idx){
        if (idx<0||idx>=size){
            cout<<"invalid"<<endl;
            return;
        }
        for(int i=idx;i<size-1;i++){
            data[i] = data[i + 1];
        }
        size--;
    }
    void print(){
        for (int i=0;i<size;i++){
            cout<<data[i]<<"";
        }
        cout<<endl;
    }
};
int main(){
    myArray arr;
    arr.insert(0,10);
    arr.insert(1, 20);  // Array becomes: 10, 20
    arr.insert(1, 15);  // Array becomes: 10, 15, 20
    
    cout << "After insertions: ";
    arr.print();
    
    // Removing element at index 1 (removes 15)
    arr.remove(1);     // Array becomes: 10, 20
    
    cout << "After removal: ";
    arr.print();
    
    return 0;
}

