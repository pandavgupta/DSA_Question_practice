#include<iostream>
using namespace std;
void decreasing(int n){
    if ( n==0)
        return;
    cout<<n<<endl;
    decreasing(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    decreasing(n);

    return 0;
}