#include<iostream>
using namespace std;
int power(int n1, int n2){
    if ( n2==1)
        return n1;
    return n1*power(n1,n2-1);
}
int main(){
    int n1,n2;
    cout<<"Enter the number:";
    cin>>n1;
    cout<<"Enter the power:";
    cin>>n2;
    cout<<"result :"<<power(n1,n2);

    return 0;
}