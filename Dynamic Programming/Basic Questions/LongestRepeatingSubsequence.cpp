#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
    // method-1: using memoization;
// 	    vector<vector<int>>dp;
// 	    int helper(string &str1, string &str2, int i, int j ){
// 	        if(i == 0 || j == 0) return 0;
// 	        if(dp[i][j] != -1) return dp[i][j];
// 	        int ans{};
// 	        if(i != j && str1[i-1] == str2[j-1]) ans = 1 + helper(str1, str2, i-1, j-1);
// 	        else ans = max(helper(str1, str2, i-1, j), helper(str1, str2, i, j-1));
// 	        return dp[i][j] = ans;
// 	    }
// 		int LongestRepeatingSubsequence(string str){
// 		    string str2 = str;
// 		    dp = vector<vector<int>>(str.size()+1, vector<int>(str.size()+1, -1));
// 		    return helper(str, str2, str.size(), str.size());
// 		}
// Mtehod-2: using tabulation, time complexity O(N*N) and space O(N*N)
    // int LongestRepeatingSubsequence(string text1){
    //     vector<vector<int>>dp(text1.size()+1, vector<int>(text1.size()+1));
    //     for(int i = 1; i <= text1.size(); i++){
    //         for(int j = 1; j <= text1.size(); j++){
    //             if(i != j && text1[i-1] == text1[j-1]) dp[i][j] = 1+dp[i-1][j-1];
    //             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //         }
    //     }
    //     return dp[text1.size()][text1.size()];
    // }
// Mtehod-3: using tabulation with space optimization, time complexity O(N*N) and space O(N)
    int LongestRepeatingSubsequence(string text1){
        vector<int>dp(text1.size()+1);
        int prev{}, tmp{};
        for(int i = 1; i <= text1.size(); i++){
            prev = dp[0];
            for(int j = 1; j <= text1.size(); j++){
                tmp = dp[j];
                if(i != j && text1[i-1] == text1[j-1]) dp[j] = 1+prev;
                else dp[j] = max(dp[j], dp[j-1]);
                prev = tmp;
            }
        }
        return dp[text1.size()];
    }

};

int main(){
    string str;
    cin >> str;
    Solution obj;
    int ans = obj.LongestRepeatingSubsequence(str);
    cout << ans << "\n";
	return 0;
}