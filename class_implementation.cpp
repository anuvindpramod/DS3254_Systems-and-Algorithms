#include <iostream>
using namespace std;

class Car{
public:
    string brand;
    int range;
    string model;

    void details(){
        cout<<"The "<<model<< " is of the brand "<<brand<<" and it had a range of "<<range<<endl;

    }
    
};


class Carc1{
public:
    string brand;
    string model;
    int range;

    // Parameterised constructor
    Carc1(string a, string b, int c){
        brand=a;
        model=b;
        range=c;
    }

    //capoy constructor
    Carc1(const Carc1 &c){
        brand=c.brand;
        model=c.model;
        range=c.range;
    }

    void details(){
        cout<<"The "<<model<< " is of the brand "<<brand<<" and it had a range of "<<range<<endl;
    }
};

int main(){
    Carc1 car("Toyotta","Corolla",120);
    Carc1 car2=car;
    car.details();
    car2.details();
    return 0;
}