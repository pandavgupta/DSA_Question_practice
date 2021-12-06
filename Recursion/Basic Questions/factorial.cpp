#include<iostream>
using namespace std;
int factorial(int n){
    if ( n==1)
        return 1;
    return n*factorial(n-1);
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    cout<<"factorial is :"<<factorial(n);

    return 0;
}