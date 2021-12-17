#include<iostream>
using namespace std;
/*
void permutation(string ip, string op=""){
    if(ip.size()==0){
        cout<<op<<",";
        return ;
    }
    for (int i = 0; i < ip.size(); i++)
    {
        string op1=op;
        string ip1=ip;
        op1.push_back(ip[i]);
        ip1.erase(ip1.begin()+i);
        permutation(ip1,op1);
    }
    
}
*/
void permutation(string ip, int pos=0){
    if(ip.size()==0 || pos == ip.size()-1){
        cout<<ip<<",";
        return ;
    }
    for (int i = pos; i < ip.size(); i++)
    {
        swap(ip[i],ip[pos]);
        permutation(ip,pos+1);
        swap(ip[i],ip[pos]);
    }
    
}


int main(){
    int size;
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    permutation(s);
    
    return 0;
}