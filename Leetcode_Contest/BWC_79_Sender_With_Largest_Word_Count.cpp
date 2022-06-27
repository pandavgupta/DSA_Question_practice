#include<bits/stdc++.h>
using namespace std;
vector<string> getArrayOfString(string s){
    vector<string> arr;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='"'){
            i++;
            string tmp;
            while(s[i] != '"') tmp.push_back(s[i++]);
            arr.push_back(tmp);
        }
    }
    return arr;
}
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int count{};
        unordered_map<string,int>hash;
        string ans;
        int j{};
        for(int i = 0; i < messages.size(); i++){
            j = 0;
            while(j <= messages[i].size()){
                if(messages[i][j++] == ' ') hash[senders[i]] += 1;
            }
            if(messages[i].size()) hash[senders[i]] += 1;
            if(hash[senders[i]] > count){
                count = hash[senders[i]];
                ans = senders[i];
            }
            else if(hash[senders[i]] == count){
                ans = max(senders[i],ans);
            }
        }
        return ans;
    }
};
int main(){
    string s1,s2;
    getline(cin,s1,']');
    getline(cin,s2,']');
    vector<string> arr1 = getArrayOfString(s1);
    vector<string> arr2 = getArrayOfString(s2);
    Solution obj;
    cout<<obj.largestWordCount(arr1,arr2);
    return 0;
}