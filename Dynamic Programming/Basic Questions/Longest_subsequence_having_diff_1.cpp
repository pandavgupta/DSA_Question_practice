#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
// method-1: using memoization , time complexity O(N^2) and space O(N)
    // vector<int>dp;
    // int helper(int A[], int n, int i, int last){
    //     if(i == n) return 0;
    //     if(dp[1+last] != -1) return dp[1+last];
    //     int ans{};
    //     if(last == -1 || abs(A[i]-A[last]) == 1){
    //         ans = 1 + helper(A, n, i+1, i); 
    //     }
    //     return dp[1+last] = max(ans,helper(A, n, i+1, last));
    // }
    // int longestSubsequence(int N, int A[])
    // {
        
    //     dp = vector<int>(N+1, -1);
    //     return helper(A, N, 0, -1);
    // }
// Method-2: tabulation, time complexity O(N^2) and space complexity O(N)
    int longestSubsequence(int N, int A[])
    {
       vector<int>dp(N, 1);
       int ans = 1;
       for(int i = 1; i < N; i++){
           for(int j = 0; j < i; j++){
               if(abs(A[i]-A[j]) == 1){
                   dp[i] = max(dp[i], dp[j]+1);
                   ans = max(ans, dp[i]);
               }
           }
       }
       return ans;
    }
};

int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i = 0;i < N;i++)
        cin>>A[i];
    
    Solution ob;
    cout<<ob.longestSubsequence(N, A)<<endl;
    return 0;
}