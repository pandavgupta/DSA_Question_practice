#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
    // method-1: memoization technique , time complexity O(N*W) and space O(N*W)
	// vector<vector<int>>dp;
	// int helper(int cost[], int N, int w, int i){
	//     if(w == 0 || i == N){
	//         if(w == 0) return 0;
	//         return 1e9;
	//     }
	//     if(dp[i][w] != -1) return dp[i][w];
	//     int ans = 1e9;
	//     if(i+1 <= w && cost[i] != -1)
	//       ans = min(ans,cost[i] + helper(cost, N, w-i-1, i));
	//     ans = min(ans, helper(cost, N, w, i+1));
	//     return dp[i][w] = ans;
	// }
	// int minimumCost(int cost[], int N, int W) 
	// { 
	//    dp = vector<vector<int>>(N, vector<int>(W+1, -1));
    //    int ans = helper(cost, N, W, 0);
    //    if(ans == 1e9) return -1;
    //    return ans;
	// } 

// method-2: using tabulation technique, time complexity O(N*W) and space O(W)
    int minimumCost(int cost[], int N, int W) 
	{ 
        //  vector<vector<int>>dp(N+1, vector<int>(W+1, 1e9));
         vector<int>dp(W+1,1e9);
         dp[0] = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= W; j++){
               if(cost[i-1] != -1 && j >= i){
                    dp[j] = min(dp[j], cost[i-1] + dp[j-i]);
                }
            }
        }
        if(dp[W] == 1e9) return -1;
        return dp[W];
	} 
};
int main(){
    int size, bag;
    cin>>size>>bag;
    int cost[size];
    for(int i = 0; i < size; i++) cin>>cost[i];
    Solution obj;
    cout<<obj.minimumCost(cost, size, bag)<<endl;
    return 0;
}