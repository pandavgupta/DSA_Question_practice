#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
// Method -1: Recursion + memoization

//   vector<vector<long long>>dp;
//     long long int helper(vector<int> s, int m, int n){
//         if( m == 0 || n == 0){
//             if(n == 0) return 1;
//             return 0;
//         }
//         if(dp[m][n] != -1) return dp[m][n];
//         long long int ans{};
//         if(n - s[m-1] >= 0) ans = helper(s, m, n - s[m-1]);
//         return dp[m][n] = ans + helper(s, m - 1, n);
//     }
//     long long int count(int S[], int m, int n) {
//         dp = vector<vector<long long>>(m+1, vector<long long>(n+1,-1));
//         return helper(S, m, n);
//     }

// Method-2: using tabulation with time complexity : O(M*N) , space O(M*N)
    //   long long int count(vector<int>  s, int m, int n) {
    //       vector<vector<long long>>dp(m+1, vector<long long>(n+1,0));
    //       for(int i = 0; i <= m; i++){
    //           for(int j = 0; j <= n; j++){
    //               if(i == 0 || j == 0){
    //                   if(j == 0) dp[i][j] = 1;
    //                   if(i == 0) dp[i][j] = 0;
    //               }
    //               else if(s[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i][j-s[i-1]];
    //               else dp[i][j] = dp[i-1][j];  
    //           }
    //       }
    //       return dp[m][n];
    //   }
// Method-3: using tabulation with time complexity : O(M*N) , space O(N)
      long long int count(vector<int> s, int m, int n) {
        vector<long long> dp(n+1,0);
          for(int i = 1; i <= m; i++){
              if(s[i-1] <= n)
                 dp[s[i-1]] += 1;
              for(int j = s[i-1]+1; j <= n; j++){
                  dp[j] = dp[j] + dp[j-s[i-1]];
              }
          }
          return dp[n];
      }
    };
int main(){
    int size,price;
    cin>>price>>size;
    vector<int>arr(size);
    for (int i = 0; i < size; i++)
    cin>>arr[i];
     Solution obj;
    int res= obj.count(arr,size, price);
    cout<<"Number of way to make change : "<<res;
    
    return 0;
}