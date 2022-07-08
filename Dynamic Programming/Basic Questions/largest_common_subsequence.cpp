#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// method-1: using memoization;
    // vector<vector<int>>dp;
    // int helper(string &text1, string &text2, int i, int j){
    //     if(i == 0 || j == 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int ans{};
    //     if(text1[i-1] == text2[j-1]){
    //         ans = 1+ helper(text1, text2, i-1, j-1);
    //     }
    //     else{
    //         ans = max(ans, helper(text1, text2, i-1, j));
    //         ans = max(ans, helper(text1, text2, i, j-1));
            
    //     }
    //     return dp[i][j] = ans;
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     dp = vector<vector<int>>(text1.size()+1, vector<int>(text2.size()+1, -1));
    //     return helper(text1, text2, text1.size(), text2.size());
    // }
// Mtehod-2: using tabulation, time complexity O(M*N) and space O(M*N)
// int longestCommonSubsequence(string text1, string text2) {
//     vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1));
//     for(int i = 1; i <= text1.size(); i++){
//         for(int j = 1; j <= text2.size(); j++){
//             if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     return dp[text1.size()][text2.size()];
// }

// Mtehod-3: using tabulation with space optimization, time complexity O(M*N) and space O(min(M,N))
int longestCommonSubsequence(string text1, string text2) {
    if(text2.size() > text1.size()) return longestCommonSubsequence(text2, text1);
    vector<int>dp(text2.size()+1);
    int prev{}, tmp{};
    for(int i = 1; i <= text1.size(); i++){
        prev = dp[0];
        for(int j = 1; j <= text2.size(); j++){
            tmp = dp[j];
            if(text1[i-1] == text2[j-1]) dp[j] = 1+prev;
            else dp[j] = max(dp[j], dp[j-1]);
            prev = tmp;
        }
    }
    return dp[text2.size()];
}
};
int main()
{
   string text1,text2;
//    input is in the leetcode format.
   cout<<"enter string: ";
   cin>>text1>>text2; 
   text1 = text1.substr(1,text1.size()-2);
   text2 = text2.substr(1,text2.size()-2);
   Solution obj;
   cout<<obj.longestCommonSubsequence(text1, text2);
    return 0;
}
