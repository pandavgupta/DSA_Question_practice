#include<bits/stdc++.h>
using namespace std;

//Method-1 : using vector for sorting 
// class Solution {
//     static bool cmp(const pair<int,char>&a, const pair<int,char>&b){
//       if(a.first == b.first) return a.second < b.second;
//       return a.first > b.first;
//     }
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int>hash;
//         vector<pair<int,char>>vec;
//         string res;
//         for(int i =  0; i < s.size(); i++) hash[s[i]]++;
//         for(auto i:hash) vec.push_back({i.second, i.first});
//         sort(vec.begin(), vec.end(), cmp);
//         for(auto i:vec){
//             while(i.first--) res.push_back(i.second);
//         }
//         return res;
//     }
// };

// Method-2: space optimization
class Solution{
public:
    string frequencySort(string s) {
        unordered_map<char, int>hash;
        for(int i =  0; i < s.size(); i++) hash[s[i]]++;
        sort(s.begin(), s.end(),[&](const char a, const char b){
            return hash[a] > hash[b] || (hash[a] == hash[b] && a < b );
        });
        return s;
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    Solution obj;
    cout<<obj.frequencySort(s);
    return 0;
}