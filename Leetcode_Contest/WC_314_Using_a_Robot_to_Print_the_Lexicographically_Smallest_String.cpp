#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        vector<int>hash(26);
        stack<char>t;
        string paper;
        char first = 'z';
        for(int i = s.size()-1; i >= 0; i--) hash[s[i]-'a']++;
        for(int i = 0; i < 26; i++) if(hash[i]){
            first = i+'a';
            break;
        }
        int i = 0;
        while(i < s.size()){
            while(i < s.size() && (t.empty() || t.top() > first)){
                t.push(s[i]);
                hash[s[i++]-'a']--;
            }
            if(i < s.size() ) while(hash[first-'a'] == 0) first++;
            paper.push_back(t.top());
            t.pop();
        }
        while(t.size()){
           paper.push_back(t.top());
            t.pop();
        }
        return paper;
    }
};
int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.robotWithString(s);
    return 0;
}