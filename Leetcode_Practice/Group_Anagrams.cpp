#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;
        vector<vector<string>>res;
        string tmp;
        for(int i = 0; i < strs.size(); i++){
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(strs[i]);
        }
        for(auto [key,value]:hash) res.push_back(value);
        
        return res;
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<string>str;
    while(getline(ss, tmp, ',')) str.push_back(tmp.substr(1,tmp.size()-2));
    Solution obj;
    vector<vector<string>>res = obj.groupAnagrams(str);
    cout<<"[";
    for(int i = 0; i < res.size(); i++){
        cout<<"[";
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j];
            if(j != res[i].size()-1) cout<<",";
        }
        cout<<"]";
        if(i != res.size()-1) cout<<",";
    }
    cout<<"] ";
    return 0;
}