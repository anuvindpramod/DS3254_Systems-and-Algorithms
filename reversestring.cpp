#include <iostream>
#include <string>
using namespace std;

string reversestring(const string &str){
    string reverse;
    for (int i=str.length()-1;i>=0; i--){
    reverse+=str[i];
    }
    return reverse;

}

int main(){
    cout<<"Give the input string "<<endl;
    string input;
    getline(cin,input);
    cout<<"reversed string "<<reversestring(input)<<endl;
    return 0;
}