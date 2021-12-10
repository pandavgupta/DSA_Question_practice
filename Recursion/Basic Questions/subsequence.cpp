#include<iostream>
using namespace std;
void subsequence(string s1, string s2){
    if(s1.length()==0){
     cout<<"["<<s2<<"]"<<",";
     return;
    }
    string op1=s2;
    string op2=s2;
    op2.push_back(s1[0]);
    s1.erase(s1.begin()+0);
    subsequence(s1,op2);
    subsequence(s1,op1);
    
    return;
    
}
int main(){
    string s1;
    cout<<"Enter the string:";
    cin>>s1;
    subsequence(s1,"");

    return 0;
}