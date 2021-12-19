#include<iostream>
using namespace std;

void stair_path(int n, string op){
    if (n==0)
    { 
      cout<<op<<" ";
      return;
    }
    for (int i = 1; i <=3 && n-i>=0; i++)
    {
        string op1=op;
        int ip=n;
        char tmp= '0'+i; 
        op1.push_back(tmp);
        ip=ip-i;
        stair_path(ip,op1);
    }
    

    
    
    return;
}


int main(){
    int n;
    cout<<"Enter no.of stair: ";
    cin>>n;
    stair_path(n,"");
    return 0;
}