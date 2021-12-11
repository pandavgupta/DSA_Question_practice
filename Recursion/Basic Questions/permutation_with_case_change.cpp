#include<iostream>
using namespace std;
void permutation_with_spaces(string s, string op){
    if(s.length()==0){
     cout<<op<<",";
     return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(toupper(s[0]));
    op2.push_back(tolower(s[0]));
    s.erase(s.begin()+0);
    permutation_with_spaces(s,op1);
    permutation_with_spaces(s,op2);
    
    return;
    
}
int main(){
    string s1,op="";
    cout<<"Enter the string:";
    cin>>s1;
    permutation_with_spaces(s1,op);

    return 0;
}