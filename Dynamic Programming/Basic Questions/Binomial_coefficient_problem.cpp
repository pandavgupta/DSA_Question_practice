#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
class Solution{
public:
// using recursion + memoization
    // vector<vector<int>>dp;
    // int helper(int n, int r){
    //   if( r > n) return 0;
    //   if(r == 0 || r == n) return 1;
    //   if(dp[n][r] != -1) return dp[n][r];
    //   return dp[n][r] = (helper(n-1, r-1) + helper(n-1,r))%M;
    // }
    // int nCr(int n, int r){
    //     dp = vector<vector<int>>(n+1, vector<int>(n+1,-1));
    //     return helper(n, r);
    // }
// using tabulation , time complexity : O(N^2) and Space O(N^2)
    // int nCr(int n, int r){
    //     if( r > n ) return 0;
    //     if(r == 0 || r == n) return 1;
    //     vector<vector<int>>dp (n+1, vector<int>(n+1,0));
    //     for(int i = 1; i <= n; i++){
    //         for(int j = 0; j <= i ; j++){
    //             if(j == 0 || j == i) dp[i][j] = 1;
    //             else{
    //                 dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%M;
    //             }
    //         }
    //     }
    //     return dp[n][r];
    // }
    // using tabulation , time complexity : O(N^2) and Space O(N)
    int nCr(int n, int r){
        if( r > n ) return 0;
        if(r == 0 || r == n) return 1;
        vector<int>dp(n+1,0);
        int prev = 1;
        int curr = 1;
        // dp[0] = 1;
        // dp[1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= i; j++){
                if( j == 0 || j == i){
                    prev = 1;
                    dp[j] = 1;
                }
                else{
                    curr = dp[j];
                    dp[j] = (prev + curr)%M;
                    prev = curr;
                }
            }
        }
        return dp[r];
    }
};
int main(){
    int n, r;
    cin>>n>>r;
    Solution obj;
    cout<<obj.nCr(n,r);
    return 0;
}