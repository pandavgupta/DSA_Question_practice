/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include<climits>
using namespace std;



//recursive solution

// int cs2(int arr[], int n, vector<int>&dp,int move,int idx) {
//   if(idx>=n){
//     if(n==idx){
//       dp.push_back(move);
//      return 1;
//     }
     
//     return 0;
//   }
//   int count=0;
//   for(int i=1; i<=arr[idx] && i+idx<=n ; i++){
//     count+=cs2(arr,n,dp,move+1,idx+i);
//   }
//   return count;

// }



// int cs(int arr[],int n, vector<int>&dp ){
//   int count=0;
//   vector<int>dp2;
//   count=cs2(arr, n, dp2,0,0);
//   int min_value=INT_MAX;
  
//   for(auto it:dp2){
//     min_value=min(min_value,it);  
//   }
   

//    return min_value;
// }


//dynamic solution
int cs(int arr[], int n, vector<int>& dp) {
 dp[n]=0;
 for(int i=n-1; i>=0; i--){
   if(arr[i]>0){
     int my_min=0;
     int flag=0;
     for(int j=1; j<=arr[i] && i+j<=n ; j++){
       if(dp[i+j]>0 || i+j==n){
         if(!my_min)
          my_min=dp[i+j];
        else
        my_min=min(my_min,dp[i+j]);
        flag=1;
       }
         
     }
     if(flag)
     dp[i]=1+my_min;
   }

 }
 return dp[0];
 

}

int main() {
  int n;
  cout<<"total number of steps:";
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n + 1);

  int res= cs(arr, n, dp) ;
  cout <<"ans :"<<res;
  return 0;
}