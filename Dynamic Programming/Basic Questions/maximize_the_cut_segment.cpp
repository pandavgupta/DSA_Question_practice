#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    // Method -1: using memoization
    //  vector<int>dp;
    // int helper(int n,int x, int y, int z){
    //     if(n == 0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int ans = -1e9;
    //     if(n-x >=0 )
    //       ans = max(ans, 1+helper(n-x, x, y, z));
    //     if(n-y >= 0)
    //      ans = max(ans , 1 + helper(n-y, x, y, z) );
    //     if(n-z >= 0)
    //      ans = max(ans , 1 + helper(n-z, x, y, z) );
    //     return dp [n] = ans;
        
    // }
    // int maximizeTheCuts(int n, int x, int y, int z)
    // {
    //     dp = vector<int>(n+1,-1);
    //     int ans = helper(n, x, y, z);
    //     if(ans < 0) return 0;
    //     return ans;
    // }

    // method-2: using tabulation: time complexity O(N), space O(N)
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,0);
        
        int i = min(x,min(y,z)) + 1;
        if(x <= n) dp[x] = 1;
        if(y <= n) dp[y] = 1;
        if(z <= n) dp[z] = 1;
        for(i ; i <= n; i++){
            if( i-x >= 0 && dp[i-x])
             dp[i] = max(dp[i],1+dp[i-x]);
            if(i-y >= 0 && dp[i-y])
             dp[i] = max(dp[i],1+dp[i-y]);
            if(i-z >= 0 && dp[i-z])
             dp[i] = max(dp[i],1+dp[i-z]);
        }
        return dp[n];
    }
};

int main() {
        int n;
        cin >> n;
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;


	return 0;
}  