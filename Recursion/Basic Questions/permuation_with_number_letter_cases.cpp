#include<iostream>
using namespace std;
void permutation(string s, string op){
    if(s.length()==0){
     cout<<op<<",";
     return;
    }


    if( int(s[0]) >= 48 &&   int(s[0]) <= 57 ){
    op.push_back((s[0]));
    s.erase(s.begin()+0);
    permutation(s,op);
    }
    else{
    string op1=op;
    string op2=op;
    op1.push_back(toupper(s[0]));
    op2.push_back(tolower(s[0]));
    s.erase(s.begin()+0);
    permutation(s,op1);
    permutation(s,op2);
    }
    
    
    
    return;
    
}
int main(){
    string s1,op="";
    cout<<"Enter the string:";
    cin>>s1;
    permutation(s1,op);

    return 0;
}