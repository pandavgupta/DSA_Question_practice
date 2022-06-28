#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//   Method-1: using unordered_set, time complexity O(N), space complexity O(N) 
    int minDeletions(string s) {
        unordered_set<int>myset;
        vector<int>hash(26);
        int count{};
        for(int i = 0; i < s.size(); i++) hash[s[i]-'a'] += 1;
        for(int i = 0; i < 26; i++){
            while(hash[i] && myset.count(hash[i])){
                count++;
                hash[i] -=1;
            }
            if(hash[i]) myset.insert(hash[i]) ;
        }
        return count;
    }
//     Method-2; using sorting , time complexity O(nlongn), space O(1)
//     int minDeletions(string s) {
//         unordered_set<int>myset;
//         vector<int>hash(26);
//         int count{};
//          sort(hash.begin(), hash.end(), greater<int>());
//         int j =0;
//         for(int i = 1; i < 26; i++){
//             if(hash[i] && hash[i] >= hash[i-1]){
//                 j = i;
//                 while (j >0 && hash[i] && hash[j-1] <= hash[i] ) j--;
//                 while( j < i && hash[i] && hash[i] == hash[j]){
//                    hash[i]--;
//                    count++;
//                    j++;
//                 }
//             }
        
//         }
//         return count;
//     }
};
int main(){
    string tmp;
    cin>>tmp;
    string s;
    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i] == '"'){
            i++;
            while(tmp[i] != '"') s.push_back(tmp[i++]);
        }
    }
    Solution obj;
    cout<<obj.minDeletions(s);
    return 0;
}