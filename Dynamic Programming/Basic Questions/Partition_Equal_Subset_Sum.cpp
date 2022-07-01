#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
// Method -1: using recursion + memoozation;
    // vector<vector<int>>dp;
    // int helper(int n, int arr[], int sum){
    //     if(n == 0 || sum == 0){
    //         if(sum == 0) return 1;
    //         return 0;
    //     }
    //     if(dp[n][sum] != -1) return dp[n][sum];
    //     int ans{};
    //     if(arr[n-1] <= sum)
    //         ans = helper(n-1, arr, sum-arr[n-1]);
    //     return dp[n][sum] = max(ans, helper(n-1, arr, sum));
    // }
    // int equalPartition(int N, int arr[])
    // {
    //     int total{};
    //     int limit{};
    //     for(int i = 0; i < N; i++){
    //         total += arr[i];
    //     }
    //     if(total % 2 != 0) return 0;
    //     dp = vector<vector<int>>(N+1, vector<int>(total/2+1, -1));
    //     return helper(N, arr, total/2);
       
    // }

//  Method-2: using tabulation; time complexity O(N*sum of element) and space O(N*sum of element)  
    int equalPartition(int N, int arr[])
    {
        int total{};
        int sum{};
        for(int i = 0; i < N; i++){
            total += arr[i];
        }
        if(total % 2 != 0) return 0;
        sum = total/2;
        vector<vector<int>>dp(N+1, vector<int>(sum+1, 0));
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0 || j == 0){
                    if(j == 0) dp[i][j] = 1;
                }
                else if(arr[i-1] <= j)
                  dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i-1]]);
                  else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][sum];
       
    }
};


int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0;i < N;i++)
        cin>>arr[i];
    
    Solution ob;
    if(ob.equalPartition(N, arr))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
} 