#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Method-1 recursive+ memoization approach: time complexity  O(2^(m+n)) and Space complexity O(M*N)
    // vector<vector<int>>dp;
    // bool helper(string &s1, string &s2, string &s3, int i, int j, int k ){
    //     if(k == s3.size()) return true;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     bool ans = false;
    //     if(s1[i] == s3[k])
    //         ans = helper(s1, s2,s3, i+1, j, k+1);
    //     if(s2[j] == s3[k])
    //         ans = ans || helper(s1, s2, s3, i, j+1, k+1);
    //     return dp[i][j] = ans;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     if(s3.size() != s1.size()+s2.size()) return false;
    //     dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1));
    //     return helper(s1, s2 , s3, 0 , 0, 0 );
    // }

// Method-2: using tabulation method : time complexity O(M*N) and O(N*M)
//  bool isInterleave(string s1, string s2, string s3){
//         if(s3.size() != s1.size()+ s2.size()) return false;
//         vector<vector<bool>>dp(s1.size()+1, vector<bool>(s2.size()+1));
//         for(int i = 0; i <= s1.size(); i++){
//             for(int j = 0; j <= s2.size(); j++){
//                if(i == 0 &&  j == 0) dp[i][j] = true;
//                 else if(i == 0){
//                     dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[j-1]);
//                 }
//                 else if(j == 0) dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i-1]);
//                 else{
//                     dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] &&(s2[j-1] == s3[i+j-1]));
//                 }
//             }
//         }
//         return dp[s1.size()][s2.size()];
//     }
// Method-3: using tabulation : time complexity O(M*N) space O(N);
bool isInterleave(string s1, string s2, string s3){
        if(s3.size() != s1.size()+ s2.size()) return false;
        vector<bool>dp(s2.size()+1);
        for(int i = 0; i <= s1.size(); i++){
            for(int j = 0; j <= s2.size(); j++){
               if(i == 0 &&  j == 0) dp[j] = true;
                else if(i == 0){
                    dp[j] = dp[j-1] && (s2[j-1] == s3[j-1]);
                }
                else if(j == 0) dp[j] = dp[j] && (s1[i-1] == s3[i-1]);
                else{
                    dp[j] = (dp[j] && (s1[i-1] == s3[i+j-1])) || (dp[j-1] &&(s2[j-1] == s3[i+j-1]));
                }
            }
        }
        return dp[s2.size()];
    }
};



int main(){
    string a,b,c;
    cout<<"enter strings: ";
    cin>>a>>b>>c;
    // leetcode type input where string in extra "".
    a = a.substr(1,a.size()-2);
    b = b.substr(1,b.size()-2);
    c = c.substr(1,c.size()-2);
    Solution obj;
    if(obj.isInterleave(a,b,c))
      cout<<"true";
      else
      cout<<"false";


    return 0;
}