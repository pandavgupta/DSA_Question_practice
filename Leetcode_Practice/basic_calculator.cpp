#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(string &s, int &i){
        if(i == s.size()) return 0;
        int ans = 0;
        char sign = '+';
        while(i < s.size() && s[i] != ')'){
            if(s[i] == ' ') i++;
            else if(s[i] == '('){
                i++;
                if(sign == '+') ans += solve(s, i);
                else ans -= solve(s, i);
            }
            else if(s[i] == '+' || s[i] =='-') sign = s[i++];
            else{
                int num = 0;
                while(i < s.size() && (s[i] >= '0' && s[i] <= '9')) num = num*10 + (s[i++]-'0');
                if(sign == '+') ans += num;
                else ans -= num;
            }
        }
        i++;
        return ans;
    }
public:
    int calculate(string s) {
        int i = 0;
        return solve(s, i);
    }
};

int main(){
    string s;
    getline(cin, s, '\n');
    s = s.substr(1, s.size()-2);
    Solution obj;
    cout<<obj.calculate(s)<<endl;
    return 0;
}