#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        string ans = "";
        long long unit{}, sum{};
        int i = s.size()-1;
        while( i >= 0 && unit <= 31 && (1LL<<unit)+sum <= k){
            if(s[i] == '1')
               sum += (1LL<<unit);
            unit++;
            i--;
        }
        for(i; i>=0; i--){
            if(s[i]=='0') unit++;
        }
        return unit;
    }
};
int main(){
    string s;
    int n;
    cin>>s>>n;
    string ss;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <='9') ss.push_back(s[i]);
    }
    Solution obj;
    cout<<obj.longestSubsequence(ss,n);
    return 0;
}