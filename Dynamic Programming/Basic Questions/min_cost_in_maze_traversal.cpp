#include <iostream>
#include <vector>
using namespace std;

int minCost(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp  ){
  // memoization approach 
  //  if(dp[n-1][m-1]!=0)
  //    return dp[n-1][m-1];



  //      if(n-1==0 && m-1==0)
  //     return arr[0][0];
      
   
  //     int cost1=10e5,cost2=10e5;
  //     if(n-1>0){
  //       cost1=minCost(n-1,m,arr,dp);
  //     }
  //     if(m-1>0){
  //       cost2=minCost(n,m-1,arr,dp);
  //     }
    
  //         return dp[n-1][m-1]=arr[n-1][m-1]+min(cost1,cost2);
      
      for(int i=0; i<=n-1; i++)
      for( int j=0; j<=m-1; j++){
        if(i==0 && j==0)
          dp[i][j]=arr[0][0];
        else if(i==0)
             dp[i][j]=arr[i][j]+dp[i][j-1];
             else if(j==0)
             dp[i][j]=arr[i][j]+dp[i-1][j];
             else
              dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i][j-1]);
             
      }      

    return  dp[n-1][m-1]   ;   
               

}

int main()  {

  int n;
  int m;
 cout<<"enter number of row and column: ";
  cin >> n >> m;
  
  vector<vector<int>> arr(n, vector<int>(m));		

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  
  vector<vector<int>> dp(n, vector<int>(m));		

  cout << minCost(n, m, arr, dp);
}
