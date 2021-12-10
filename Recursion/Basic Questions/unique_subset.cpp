#include<iostream>
#include<unordered_set>
using namespace std;
void subset(string s1, string s2,unordered_set<string>&myset){
    if(s1.length()==0){
        if(myset.find(s2) == myset.end()){
            myset.insert(s2);
            cout<<"["<<s2<<"]"<<",";
        }
     return;
    }
    string op1=s2;
    string op2=s2;
    op2.push_back(s1[0]);
    s1.erase(s1.begin()+0);
    subset(s1,op2,myset);
    subset(s1,op1,myset);
    
    return;
    
}
int main(){
    string s1;
    unordered_set<string> myset;
    cout<<"Enter the string:";
    cin>>s1;
    subset(s1,"",myset);

    return 0;
}