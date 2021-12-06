#include<iostream>
using namespace std;
//Power-logarithmic
void tower_hanoi(int n1, int n2, int n3, int n4){
    
     if(n1==2){
         cout<<n2<<"-->"<<n4<<endl;
         cout<<n2<<"-->"<<n4<<endl;
     }
     tower_hanoi(n1-1,n2,n3,n4);
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