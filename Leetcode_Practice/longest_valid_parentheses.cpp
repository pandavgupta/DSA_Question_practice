#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
int longestValidParentheses(string s) {
       int maxv{}, count{}, last=s.size();
        stack<int> parentheses;
        vector<bool>invalid_index(s.size());
        for(int i = 0; i < s.size(); i++){
             if(s[i]=='('){
                parentheses.push(i);
            }
            else {
                if(!parentheses.empty() && s[parentheses.top()]=='('){
                    parentheses.pop();
                }
                else{
                     invalid_index[i]=true;
                     count++;
                     if(!parentheses.empty()) parentheses.pop();
                }
               
            }
        }
        while(!parentheses.empty()){
            invalid_index[parentheses.top()]=true;
            parentheses.pop();
            count++;
        }
        if(count==0) return s.size();
        last =  -1;
        for(int i = 0; i < s.size(); i++){
            if(invalid_index[i]){
                if(i-last-1 > maxv) maxv = i-last-1;
                last = i;
            }
        }
        if(s.size() - last > maxv) maxv = s.size()-last-1;
       
        return maxv;
    }
int main(){
    string s;
    cin>>s;
    cout<<longestValidParentheses(s);
    return 0;
}