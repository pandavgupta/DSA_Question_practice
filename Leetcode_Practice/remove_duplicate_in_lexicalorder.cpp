#include<bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s) {
        vector<int>hash(26,0);
        vector<int>check(26,0);
        int size = s.size();
        int diff {};
        for(int i=0; i<size;  i++){
            hash[s[i]-97]++;
        }
        string res ="";
        int j{};
        for(int i=0; i<size ; i++){
            hash[s[i]-97]--;
            if(check[s[i]-97]) continue;
            while(!res.empty() && res[res.size()-1] > s[i] && hash[res[res.size()-1]-97]>0 ){
                check[res[res.size()-1]-97]=0;
                res.pop_back();
            }
            res.push_back(s[i]);
            check[s[i]-97]=1;
        }
        return res;
    }
int main(){
    string s;
    cin>>s;
    cout<<removeDuplicateLetters(s);
    return 0;
}