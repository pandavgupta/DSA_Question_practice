#include<bits/stdc++.h>
using namespace std;
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
class Solution {
public:
// Method -1: using memoization with time complexity O(M*N*K) and space O(M*N*K)
    // int M = 1e9+7;
    // vector<vector<vector<int>>>dp;
    // int helper(vector<vector<int>>&grid, int &k, int col, int row, int sum){
    //     if(row == grid.size() || col == grid[0].size()) return 0;
    //     if(row+1 == grid.size() && col+1 == grid[0].size())
    //         return ((sum+grid[row][col])%k)==0;
    //     if(dp[row][col][sum] != -1) return dp[row][col][sum];
    //     int ans = 0;
    //        ans = helper(grid, k, col, row+1, (sum + grid[row][col])%k);
    //      ans += helper(grid, k, col +1, row, (sum + grid[row][col])%k);
    //     return dp[row][col][sum] = ans%M;
    // }
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     dp = vector<vector<vector<int>>>(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, -1)));
    //     return helper(grid, k, 0, 0, 0);
    // }

// Method-2: using tabulation 
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), mod = 1e9+7;
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k)));
        dp[0][0][grid[0][0]%k] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int s = 0; s < k; s++){
                    int modsum = (s+grid[i][j])%k;
                    if(i>0) dp[i][j][modsum] += dp[i-1][j][s];
                    if(j>0) dp[i][j][modsum] += dp[i][j-1][s];
                    dp[i][j][modsum] %= mod;
                }
            }
        }
        return dp[m-1][n-1][0]%mod;
    }
};

int main(){
    int n;
    string s;
    cin>>s>>n;
    vector<vector<int>>arr;
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp,']')){
        if(tmp.size()==1 || tmp.size()==0) continue;
        tmp = tmp.substr(2);
        vector<int>a = getArray(tmp);
        arr.push_back(a);
    }
    Solution obj;
    cout<<obj.numberOfPaths(arr, n);
    return 0;
}