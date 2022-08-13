#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int win_size = words.size() * words[0].size();
        int one_word = words[0].size();
        if(s.size() < win_size) return {};
        bool flag = false;
        unordered_map<string,int>hash;
        unordered_map<string,int>check;
        vector<int>res;
        for(int i = 0; i < words.size(); i++){
            hash[words[i]]++;
            check[words[i]] = 0;
        }
        
        for(int i = 0; i <= s.size()- win_size; i++){
            flag = true;
            for(int j = i; j < i+win_size; j +=one_word){
                string word = s.substr(j,one_word);
                if(hash.find(word) != hash.end() && check[word] < hash[word]){
                    check[word]++;
                }
                else{
                    flag = false;
                    break;
                }
            }
            for(auto &it:check) it.second = 0;
            if(flag) res.push_back(i);
        }
        return res;
    }
};
int main(){
    string s1, s2;
    cin>>s1>>s2;
    s1 = s1.substr(1,s1.size()-2);
    s2 = s2.substr(1,s2.size()-2);
    stringstream ss(s2);
    string tmp;
    vector<string>words;
    while(getline(ss,tmp,',')){
        string data = tmp.substr(1, tmp.size()-2);
        words.push_back(data);
    }
    Solution obj;
    vector<int>arr = obj.findSubstring(s1, words);
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
    return 0;
}