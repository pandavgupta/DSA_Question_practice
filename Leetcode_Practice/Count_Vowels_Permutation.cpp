#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countVowelPermutation(int n) {
        int M = 1e9+7;
        vector<vector<long>>dp(n, vector<long >(5));
        for(int i = 0; i < 5; i++) dp[0][i] = 1;
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%M;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]+ dp[i-1][3] + dp[i-1][4])%M;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%M;
            dp[i][4] = dp[i-1][0];
        }
        long sum{};
        for(int i = 0; i < 5; i++) sum +=dp[n-1][i];
        return sum%M;
    }
};
int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.countVowelPermutation(n)<<endl;
    return 0;
}