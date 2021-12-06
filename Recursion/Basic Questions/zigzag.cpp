#include<iostream>
using namespace std;
//Power-logarithmic
int zigzag(int n1){
    if ( n1==0){
        return 0;;
    }
    cout<<n1<<" ";
    zigzag(n1-1);
    cout<<n1<<" ";
    zigzag(n1-1);
    cout<<n1<<" ";
     return 0;
}
int main(){
    int n1,n2;
    cout<<"Enter the number:";
    cin>>n1;
    zigzag(n1);

    return 0;
}