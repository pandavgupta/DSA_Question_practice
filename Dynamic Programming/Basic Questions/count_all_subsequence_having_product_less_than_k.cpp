#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  // Method-2: giving TLE on GFG , time complexity : O(N*K), space complexity : O(N*K)
    // int countSubsequences(vector < int > & a, int n, int p) {
    //     vector<vector<int>>dp(p+1, vector<int>(n+1));
    //     int ans{};
    //     for(int i = 1; i <= p; i++){
    //         for(int j = 1; j <= n; j++){
    //             dp[i][j] = dp[i][j-1];
    //             if(a[j-1] <=i ){
    //                 dp[i][j] += dp[i/a[j-1]][j-1]+1;
    //             }
    //         }
    //     }
    //     return dp[p][n];
    // }
//   Method-1: memoization techinque
    vector<vector<int>>dp;
    int helper(vector<int>& arr, int N, int k, int i, int prod){
        if(i == N) return 0;
        if(dp[i][prod] !=-1) return dp[i][prod];
        int ans = 0;
        if(arr[i]*prod <= k){
            ans = 1+helper(arr, N, k, i+1, prod*arr[i]);
        }
        ans += helper(arr, N, k, i+1, prod);
        return dp[i][prod]=ans;
    }
    int countSubsequences(vector<int>&arr, int N, int k) {
        dp = vector<vector<int>>(N+1, vector<int>(k+1,-1));
        return helper(arr, N, k, 0, 1);
    }



};


int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i =0; i < n; i++) cin>>arr[i];
    Solution obj;
    cout<<obj.countSubsequences(arr, n, k)<<endl;

    return 0;
}