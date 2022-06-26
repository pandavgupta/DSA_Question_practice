#include<bits/stdc++.h>
using namespace std;
int scoreOfParentheses(string s) {
    int size = s.size();
    stack<char>mystack;
    int i{};
    int count{};
    int tmp;
    while(i<size){
        if(s[i]=='(') mystack.push('(');
        else if(s[i]==')' && mystack.top()=='(' ){
            count++;
            if(mystack.size()>1 && s[i+1]=='('){
                mystack.pop();
                mystack.push('0'+count);
                count = 0;
            } 
            
            else{
                if(mystack.size()>1 && s[i+1]==')') {
                i++;
                count=2*count;
                mystack.pop();                       
                }
                mystack.pop();
            }            
        }
        else {
            count=2*(count+ int(mystack.top()-'0'));
            mystack.pop();
        }
        i++;
    }
    return count;
}
int main(){
    string s;
    cin>>s;
    cout<<scoreOfParentheses(s);
    return 0;
}