#include<iostream>
using namespace std;
void decreasing_increasing(int n){
    if ( n==0)
        return;
    cout<<n<<endl;
    decreasing_increasing(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    decreasing_increasing(n);

    return 0;
}