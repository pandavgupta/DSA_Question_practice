#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Method-1: memoization method 
        // vector<int>dp;
        // int helper(vector<int>&a, int i){
        //     if(i >= a.size()) return 0;
        //     if(i+1 == a.size()) return a[i];
        //     if(i+2 == a.size()) return a[i+1]+a[i];
        //     if(dp[i] != -1) return dp[i];
        //     return dp[i] = max(helper(a, i+1), max(a[i] + helper(a, i+2),a[i] + a[i+1] + helper(a, i+3)));
        // }
        // int maxSum(vector<int> &a, int n) 
        // {
        //     dp = vector<int>(n+1,-1);
        // 	return helper(a, 0);
        // }
    
    //Method-2: using tabulation , time complexity O(N), space O(N) 
        int maxSum(vector<int> &a, int n) 
        {
            vector<int>dp(n,0);
            if(n>=1) dp[0] = a[0];
            if(n>=2) dp[1] = a[0]+a[1];
            if(n>=3) dp[2] = max(dp[1], max(a[0]+a[2], a[1]+a[2]));
            for(int i = 3; i < n; i++){
                dp[i] = max(dp[i-1], max(dp[i-2]+a[i], dp[i-3] + a[i-1] + a[i]));
            }
            return dp[n-1];
        }

};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    Solution obj;
    cout<<obj.maxSum(arr, arr.size())<<endl;
    return 0;
}