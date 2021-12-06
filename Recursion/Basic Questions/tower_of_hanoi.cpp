#include<iostream>
using namespace std;
//Tower of hanoi
void tower_hanoi(int n, int A, int B, int C){
    
     if(n==0)
        return;
    tower_hanoi(n-1,A,C,B);
    cout<<n<<" disk "<<A<<" --> "<<B<<endl;
    tower_hanoi(n-1,C,B,A);
}

int main(){
    int n1,n2,n3,n4;
    cout<<"Enter number of disk:";
    cin>>n1;
    cout<<"Enter tower number where disk are present :";
    cin>>n2;
    cout<<"Enter tower number where to move:";
    cin>>n3;
    cout<<"Enter helper tower number  :";
    cin>>n4;
    tower_hanoi(n1,n2,n3,n4);

    return 0;
}