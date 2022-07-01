#include <bits/stdc++.h> 
using namespace std; 

#define M 1000000007
class Solution
{
public:
// time complexity : O(2^N), Space : O(N)
// vector<long long>dp;
//     long long  helper(int n){
//         if( n <= 1) return 1;
//         if(dp[n] != -1) return dp[n];
//         return dp[n] = (helper(n-1) + (n-1)*helper(n-2))%M;
//     }
//     int countFriendsPairings(int n) 
//     { 
//         dp = vector<long long>(n+1,-1);
//       return helper(n)%M;
//     }
    
    // time complexity : O(N), Space : O(1)
    // int countFriendsPairings(int n) 
    // { 
    //     vector<long long>dp(n+1);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for(int i = 2; i <=n ; i++){
    //         dp[i] = (dp[i-1] + (i-1)*dp[i-2])%M;
    //     }
    //     return dp[n]%M;
    // }

    // time complexity : O(N), Space : O(1)
    int countFriendsPairings(int n) 
    { 
        long long curr = 1, prev = 1, tmp{};
        for(int i = 2; i <= n; i++){
            tmp = curr;
            curr = (curr + (i-1)*prev)%M;
            prev = tmp;
        }
        return curr%M;
    }
};    
 

int main() 
{
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
} 
