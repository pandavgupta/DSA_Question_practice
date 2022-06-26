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
//     bruteforce solution: 
    // long long distinctNames(vector<string>& ideas) {
    //     int count{};
    //     unordered_map<string,unordered_map<string,bool>>hash;
    //     for(int i = 0; i < ideas.size(); i++){
    //         hash[ideas[i]][ideas[i]] = true;
    //     }
    //     for(int i = 0 ; i < ideas.size()-1; i++){
    //         string tmp1 = ideas[i];
    //         for(int j = i+1; j < ideas.size(); j++){
    //                 if(hash[ideas[i]].find(ideas[j]) != hash[ideas[i]].end()) continue;
    //                 string tmp2 = ideas[j];
    //                 char ch = tmp2[0];
    //                 tmp2[0] = tmp1[0];
    //                 tmp1[0] = ch;
    //                 if(hash.find(tmp1) == hash.end() && hash.find(tmp2) == hash.end() ){
    //                     count += 2;
    //                 }
    //                 hash[ideas[i]][ideas[j]] = true;
    //                 hash[ideas[j]][ideas[i]] = true;
    //                 tmp1[0] = ideas[i][0];
    //         }
    //     }
    //     return count;
    
    // dp solution: time complexity O(N)
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>hash[26];
        long long int count{};
        for(int i = 0;  i < ideas.size(); i++){
            hash[ideas[i][0]-'a'].insert(ideas[i].substr(1));
        }
        for(int i = 0; i < 25; i++){
            char ch = char(i+'a');
            for(int j = i+1; j < 26; j++){
                if(i == j) continue;
                int common {};
                for(auto element:hash[i]) common += hash[j].count(element);
                count += 2*((hash[i].size()-common)*(hash[j].size()-common));
            }
        }
        
        return count;
    }
};
int main(){
    string s;
    cin>>s;
    vector<string>arr = getArrayOfString(s);
    Solution obj;
    cout<<obj.distinctNames(arr)<<'\n';
    return 0;
}