#include <iostream>
#include <string>
using namespace std;

int factorialcalculation(double a){
   if (a<=1){return 1;
   }
   int fout=a*factorialcalculation(a-1);
   return fout;
    
}

int main(){
    double num;
    cout<<"input the numbe please"<<endl;
    cin>>num;
    cout<<factorialcalculation(num)<<endl;
    return 0;
}

 