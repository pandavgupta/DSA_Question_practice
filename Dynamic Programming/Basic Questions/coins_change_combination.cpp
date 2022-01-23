#include <iostream>
#include <vector>
using namespace std;
// infinite number of coins
int coinchangecombination(vector<int> coins, int amt, vector<int>&dp) {

// dp solution using 2d array
//  vector<vector<int>>dp2(coins.size() +1,vector<int>(amt+1));
//  for(int i=0; i<=coins.size(); i++)
//  for(int j=0; j<=amt; j++){
//    if(i==0 || j==0){
//      if(i==0)
//       dp2[i][j]=0;
//       if(j==0)
//       dp2[i][j]=1;
//    }
//    else if(coins[i-1]<=j)
//         dp2[i][j]= dp2[i-1][j]+dp2[i][j-coins[i-1]];
//         else
//         dp2[i][j]=dp2[i-1][j];
//  }

//  return dp2[coins.size()][amt];



//dp solution using 1d array 

dp[0]=1;
for(int i=0; i<coins.size(); i++)
for(int j=coins[i]; j<=amt ; j++){
    dp[j]+=dp[j-coins[i]];
}

return dp[amt];
}

int main() {
  int n;
  cout<<"number of element of coins : ";
  cin >> n;
  vector<int> coins(n, 0);
  for (int i = 0; i < coins.size(); i++) {
    cin >> coins[i];
  }
  int amt;
  cin >> amt;
  vector<int> dp(amt + 1, 0);
  cout<<"number of way are: "<<coinchangecombination(coins, amt,dp);

}