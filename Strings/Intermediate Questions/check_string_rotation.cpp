// A Program to check if strings are rotations of each other or not.
#include<iostream>
using namespace std;

bool isrotation(string s1, string s2){

    if(s1.size() != s2.size())
       return false;

    s1=s1+s1;

    return (s1.find(s2) != string::npos );

}

int main(){
    string s1,s2;
    cout<<"Enter string to check string rotation "<<endl;
    cout<<"Enter first string :";
    getline(cin,s1);
    cout<<"Enter second string :";
    getline(cin,s2);
    if(isrotation(s1,s2))
        cout<<"Result : True";
    else
    cout<<"Result : False";
    return 0;
}