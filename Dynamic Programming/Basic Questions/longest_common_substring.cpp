#include<iostream>
#include<vector>
using namespace std;
// Method -1: time complexity O(M*N) and space complexity O(M*N)
// int longestCommonSubstr(string text1, string text2){
//     vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
//     dp[0][0]=0;
//     int count{};
//         for(int i=0; i<=text1.size(); i++){
//             for(int j=0; j<=text2.size();j++){
//                 if(i==0 || j==0){
//                     dp[i][j]=0;
//                 }
//                 else if(text1[i-1]==text2[j-1]   ){
//                     dp[i][j]=dp[i-1][j-1]+1;
//                     count=max(count,dp[i][j]);
//                 }
                
//             }
            
//         }
//    return count;
// }

// Method -2: time complexity O(M*N) and space complexity O(M)
int longestCommonSubstr(string S1, string S2){
    int n = S1.size(), m = S2.size();
    vector<vector<int>>dp(2, vector<int>(m+1));
    // vector<int>dp(m+1),prev(m+1);
    int result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(S1[i-1] == S2[j-1]){
                dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
                result = max(result , dp[i%2][j]);
            }
            else dp[i%2][j] = 0;
        }
    }
    return result;
}

int main()
{
   string text1,text2;
   cin>>text1>>text2; 
   cout<<longestCommonSubstr(text1,text2);
    return 0;
}
