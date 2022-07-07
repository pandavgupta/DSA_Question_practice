#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
// Method-1: using recursion + memoization
    // vector<vector<int>>dp;
    // int helper(vector<vector<int>>&M, int n, int m, int i, int j){
    //     if( j == m) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int ans = 0;
    //     if(j+1 <= m){
    //         ans = helper(M, n, m, i, j+1);
    //         if(i-1 >= 0)
    //           ans = max(ans, helper(M, n, m, i-1,j+1 ));
    //         if(i+1 < n)
    //           ans = max(ans, helper(M, n, m, i+1, j+1));
    //     }
    //     return dp[i][j] = ans+M[i][j];
    // }
    // int maxGold(int n, int m, vector<vector<int>> M)
    // {
    //     dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
    //     int maxv{};
    //     for(int i = 0; i < n; i++){
    //         maxv = max(maxv, helper(M, n, m, i,0));
    //     }
    //     return maxv;
    // }
// using tabulation : time complexity O(M*N) and Space O(M*N)
int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n+2, vector<int>(m+1));
        for(int j = 0; j < m; j++){
            for(int i = 1; i <= n; i++){
                if(j == 0) {
                    if(i > 0) dp[i][j] = M[i-1][j];
                }
                else{
                    dp[i][j] = M[i-1][j] + max(dp[i][j-1], max(dp[i-1][j-1], dp[i+1][j-1]));
                }
            }
        }
        int maxv{};
        for(int i = 1; i <=n ; i++) maxv = max(maxv, dp[i][m-1]);
        return maxv;
    }
};


int main(){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    return 0;
} 