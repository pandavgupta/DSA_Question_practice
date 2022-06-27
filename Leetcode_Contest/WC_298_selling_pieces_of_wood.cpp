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
// Method -1: Brute force(using recursion)
    // vector<vector<long long>>dp;
    // long long helper( int m, int n, vector<vector<long long>>&prices){
    //     if(m == 1 && n == 1) prices[m][n];
    //     if(dp[m][n] != -1) return dp[m][n];
    //     long long int ans = 1LL*prices[m][n];
        
    //     for(int i = 1; i <= m/2; i++){
    //           long long  horizontal_cut = helper(i, n , prices) + helper(m-i,n, prices);
    //           if(ans < horizontal_cut) ans = horizontal_cut;
    //     }
    //     for(int i = 1; i <= n/2; i++){
    //           long long vertical_cut =  helper(m, i, prices) + helper(m,n - i, prices);
    //           if(ans < vertical_cut) ans = vertical_cut;
    //           // ans = max(ans, vertical_cut);
    //     }
        
    //     return dp[m][n] = ans;
    // }
    // long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    //    dp = vector<vector<long long>>(m+1, vector<long long>(n+1,-1));
    //     vector<vector<long long>>price(m+1, vector<long long>(n+1,0));
    //     for(int i = 0; i < prices.size(); i++){
    //         price[prices[i][0]][prices[i][1]] = prices[i][2];
    //     }
    //     return helper(m,n,price);
    // }
    
    // DP solution
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1, vector<long long>(n+1));
        for(int i = 0; i < prices.size(); i++) dp[prices[i][0]][prices[i][1]] = prices[i][2];
        for(int row = 1; row <= m; row++){
            for(int col = 1; col <= n; col++){
                for(int h = 1; h <= row/2; h++){
                    long long earned = dp[h][col] + dp[row-h][col];
                    if(earned > dp[row][col]) dp[row][col] = earned;
                }
                for(int v = 1; v <= col/2; v++){
                    long long earned = dp[row][v] + dp[row][col-v];
                    if(earned > dp[row][col]) dp[row][col] = earned;
                }
            }
        }
        
        return dp[m][n];
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    string s;
    cin>>s;
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
    Solution obj;
    cout<<obj.sellingWood(m,n,arr);
    return 0;

}