#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    // using memoization, time O(N^2) and space O(N*max(arr[i])) , my own solution 
    // vector<vector<int>>dp;
    // int helper(int a[], int n, int last){
    //     if(n == 0) return 0;
    //     if(dp[n][last] != -1) return dp[n][last];
    //     int ans{};
    //     if(a[n-1] < last)
    //        ans = 1 + helper(a, n-1, a[n-1]);
    //     ans = max(ans, helper(a, n-1, last));
    //     return dp[n][last] = ans;
    // }
    // int longestSubsequence(int n, int a[])
    // {
    //     int maxv{};
    //     for(int i = 0; i < n; i++) maxv = max(a[i], maxv);
    //     dp = vector<vector<int>>(n+1,vector<int>(maxv+1, -1));
    //   return helper(a, n, maxv);
    // }
    // method -2: optimised memoization: O(N^2) and space O(N)
    // vector<int>dp;
    // int helper(int a[], int n, int last, int size){
    //     if(n == size) return 0;
    //     if(dp[last+1] != -1e9) return dp[last+1];
    //     int ans{};
    //     if(last == -1 || a[n] > a[last])
    //        ans = 1 + helper(a, n+1, n, size);
    //     ans = max(ans, helper(a, n+1, last, size));
    //     return dp[last+1] = ans;
    // }
    // int longestSubsequence(int n, int a[])
    // {
    //   dp = vector<int>(n+1, -1e9);
    //   return helper(a, 0, -1, n);
    // }
// method-3 using tabulation: O(N^2) and space O(N);
    // int longestSubsequence(int n, int a[])
    // {
    //   vector<int>dp(n, 1);
    //   int maxv = 1;
    //   int count = 0;
    //   for(int i = 1; i < n; i++){
    //       count = 0;
    //       for(int j = 0; j < i; j ++){
    //           if(a[j] < a[i]) count = max(count,dp[j]);
    //       }
    //       dp[i] += count;
    //       maxv = max(maxv, dp[i]);
    //   }
    //   return maxv;
    // }

// Method-4: using Binary search : time complexity O(NlogN) and space O(N)
       int least_bound(vector<int>&sub, int val){
        int start = 0, end = sub.size()-1, mid{};
        while(start < end){
            mid = (start + end)/2;
            if(sub[mid] == val) return mid;
            if(sub[mid] > val) end = mid;
            else start = mid +1;
        }
        return start;
    }
    int longestSubsequence(int n, int nums[]) {
        vector<int>sub;
        sub.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > sub.back()) sub.push_back(nums[i]);
            else{
                int val = least_bound(sub,nums[i]);
                sub[val] = nums[i];
            }
        }
        return sub.size();
    }
};

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    Solution ob;
    cout << ob.longestSubsequence(n, a) << endl;
    return 0;
}