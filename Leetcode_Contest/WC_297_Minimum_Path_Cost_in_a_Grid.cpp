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
vector<vector<int>> get_2d_array(string s){
    vector<vector<int>>arr;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i]=='['){
            i++;
            if(s[i] == ',') i++;
            string tmp ;
            while(s[i] != ']') tmp.push_back(s[i++]);
            tmp.push_back(s[i]);
            arr.push_back(getArray(tmp));
            if(s[i+1] == ']') break;
            s[i] = '[';
            i--;
        }
    }
    return arr;
}
// recursion+ memorization;
// vector<vector<int>>dp;
// int helper(vector<vector<int>>&grid, vector<vector<int>>&movecost, int row, int col){
//     if(row == grid.size()-1) return grid[row][col];
//     if(dp[row][col] != -1) return dp[row][col];
//     int ans = 1e9;
//     for(int j = 0; j < grid[row].size(); j++){
//         ans = min(ans,grid[row][col] + movecost[grid[row][col]][j] + helper(grid, movecost, row+1, j));
//     }
//     return dp[row][col] = ans;
// }
// int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//     dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
//     int ans= 1e9;
//     for(int i = 0 ; i < grid[0].size(); i++ )
//        ans = min(ans, helper(grid, moveCost, 0, i));
//     return ans;
// }
//  dp solution, time complexity: O(row * col * col) and space complexity : O(row*col)
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int row = grid.size(), col = grid[0].size();
    int ans = 1e9;
    vector<vector<int>>dp(row, vector<int>(col,ans));
    for(int i = 0; i < col; i++) dp[row-1][i] = grid[row-1][i];
    for(int i = row-2; i >= 0 ; i--){
        for(int j = 0; j < col; j++){
            ans = 1e9;
            for(int k = 0; k < col ; k++)
                ans = min(ans, dp[i+1][k]+moveCost[grid[i][j]][k]);
            dp[i][j] = ans + grid[i][j];
        }
        
    }
    ans = 1e9;
    for(int i = 0; i < col; i++) ans = min(ans,dp[0][i]);
    return ans;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>>grid = get_2d_array(s1);
    vector<vector<int>>cost = get_2d_array(s2);
    cout<<minPathCost(grid, cost);
    return 0;
}