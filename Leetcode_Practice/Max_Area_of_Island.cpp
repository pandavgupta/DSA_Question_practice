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
    vector<vector<bool>>dp;
    int helper(vector<vector<int>>&grid, int i , int j){
        if(grid[i][j] == 0 || dp[i][j] ) return 0;
        dp[i][j] = true;
        int ans = 1;
        if(i-1 >= 0) ans += helper(grid, i-1,j);
        if(j-1 >= 0) ans += helper(grid, i, j-1);
        if(j+1 < grid[0].size()) ans += helper(grid, i, j+1);
        if(i+1 < grid.size()) ans += helper(grid, i+1, j);
        
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>&grid){
        int maxv = 0;
        int row = grid.size();
        int col = grid[0].size();
        dp = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    maxv =  max(maxv,helper(grid, i, j));
                }
            }
        }
        return maxv;
    }
};
int main(){
    string s;
    // int n;
    cin>>s;
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
    cout<<obj.maxAreaOfIsland(arr);
    return 0;
}