#include<iostream>
using namespace std;
//Power-logarithmic
int power(int n1, int n2){
    if ( n2==1)
        return n1;
    int k=power(n1,n2/2);
    k= k*k;
    if(n2%2!=0)
    return k*n1;
    return k;
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