#include <bits/stdc++.h>

using namespace std;


int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
 
  
//recursive approach
  // if( m==0)
  //   return arr[n-1][0];


  //   int max_value1=0;
  //   for(int i=n; i>0;i--){
  //     int max_value=0;
  //     if(i>0 && i<n-1)
  //      max_value=max(max( collectGold(i, m-1, arr, dp),collectGold(i-1, m-1, arr, dp)),collectGold(i+1, m-1, arr, dp));
  //      else if(i==0)
  //      max_value=max(collectGold(i, m-1, arr, dp),collectGold(i+1, m-1, arr, dp));
  //      else
  //       max_value=max(collectGold(i, m-1, arr, dp),collectGold(i-1, m-1, arr, dp));
          
  //         max_value1=max(max_value,max_value1);
  //   }
  
  // return arr[n-1][m-1]+max_value1;

  for(int i=0; i<n; i++){
    dp[i][m-1]=arr[i][m-1];
  }
 int max_value=-1;
  for(int j=m-2; j>=0; j--)
  for(int i=0; i<n; i++){
    if(i!=0 && i!=n-1)
       dp[i][j]=arr[i][j]+max(max(dp[i-1][j+1],dp[i][j+1]),dp[i+1][j+1]);
    else if(i==0)
         dp[i][j]=arr[i][j]+max(dp[i+1][j+1],dp[i][j+1]);
         else
          dp[i][j]=arr[i][j]+max(dp[i-1][j+1],dp[i][j+1]);
    
    if(j==0)
    max_value=max(max_value,dp[i][j]);

  }
  return max_value;
}



int main() {
  int n, m;
  cout<<"enter number of row and column :";
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));

  cout << collectGold(n, m, arr, dp);

}