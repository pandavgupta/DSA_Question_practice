#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
//   Method-1: using recursion + memoization 
    // vector<vector<int>>dp;
    // int helper(string &word1, string &word2, int i, int j){
    //     if(i == 0 || j == 0){
    //         if(i == j) return 0;
    //         return i != 0 ? i:j;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int ans = 1e9;
    //     if(word1[i-1] != word2[j-1]){
    //         ans = min(ans, 1 + helper(word1, word2, i-1, j-1));
    //         ans = min(ans, 1 + helper(word1, word2, i, j-1));
    //         ans = min(ans, 1 + helper(word1, word2, i-1, j));
    //     }
    //     else ans = helper(word1, word2, i-1, j-1);
    //     return dp[i][j] = ans;
    // }
    // int minDistance(string word1, string word2) {
    //     dp = vector<vector<int>>(word1.size()+1, vector<int>(word2.size()+1,-1));
    //     return helper(word1, word2, word1.size(), word2.size());
    // }

    // Method-2: using tabulation,  time complexity O(M*N) ans space O(M*N)
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1));
        for(int i = 0; i <= word1.size(); i++){
            for(int j = 0; j <= word2.size(); j++){
                if(i == 0 || j == 0){
                    if(i == 0 && j == 0) dp[i][j] = 0;
                    else dp[i][j] = max(i,j);
                }
                else if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution ob;
    int ans = ob.minDistance(s, t);
    cout << ans << "\n";
    return 0;
}
  // } Driver Code Ends