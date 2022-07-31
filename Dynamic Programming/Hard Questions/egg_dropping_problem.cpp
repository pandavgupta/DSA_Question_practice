#include<bits/stdc++.h>
using namespace std;

class Solution
{ 
    public:
    // Method-1: memoization , time complexity O(no_egg*no_floor*no_floor) and space O(no_egg*no_floor)
    // vector<vector<int>>dp;
    // int helper(int no_egg, int no_floor) 
    // {
    //    if(no_floor <= 1 || no_egg == 1) return no_floor;
    //    if(dp[no_egg][no_floor] != -1) return dp[no_egg][no_floor];
    //    int ans = 1e9;
    //    for(int i = 1; i <= no_floor; i++){
    //        ans = min(ans, max(helper(no_egg, no_floor-i), helper(no_egg-1, i-1)));
    //    }
    //    return dp[no_egg][no_floor] = ans+1;
    // }
    // int eggDrop(int no_egg, int no_floor) 
    // {
    //    dp = vector<vector<int>>(no_egg+1, vector<int>(no_floor+1, -1));
    //    return helper(no_egg, no_floor);
    // }

    // method-2: using tabulation, time complexity O(no_egg*no_floor*no_floor) and space O(no_egg*no_floor)
    // int eggDrop(int no_egg, int no_floor){
    //     if(no_egg == 1 || no_floor <= 1) return no_floor;
    //     vector<vector<int>>dp(no_egg+1, vector<int>(no_floor+1));
    //     for(int i = 1; i <= no_egg; i++){
    //         for(int j = 1; j <= no_floor; j++){
    //             if(i == 1 || j == 1) dp[i][j] = j;
    //             else{
    //                 dp[i][j] = 1e9;
    //                 for(int k = 1; k <=j; k++){
    //                     dp[i][j] = min(dp[i][j], max(dp[i][j-k], dp[i-1][k-1]));
    //                 }
    //                 dp[i][j]++;
    //             }
    //         }
    //     }
    //     return dp[no_egg][no_floor];
    // }

    // Method-3: using Dynamic programming with binary search: time complexity(N*K*log(K)) and space O(N*K)
    vector<vector<int>>dp;
    int helper(int n, int k){
        if(n == 1 || k <=1) return k;
        if(dp[n][k] != -1) return dp[n][k];
        int low = 1, high = k, mid{}, t1{}, t2{};
        while(low+1 < high){
            mid = (low+high)/2;
            t1 = helper(n-1,mid-1);
            t2 = helper(n, k-mid);
            if(t1 < t2) low = mid;
            else if( t1 > t2) high = mid;
            else low = high = mid;
        }
         int ans = min(max(helper(n-1, low-1), helper(n,k-low)), max(helper(n-1, high-1), helper(n, k - high)) );
         return dp[n][k] = ans +1;
        
    }
    int eggDrop(int n, int k) 
    {
       dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
       return helper(n, k);
    }
};

int main()
{
    int n, k;
    cin>>n>>k;
    Solution ob;
    // n is no of egg and k is no of floor
    cout<<ob.eggDrop(n, k)<<endl;
    return 0;
}
