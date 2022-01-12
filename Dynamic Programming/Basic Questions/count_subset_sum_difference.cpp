#include<iostream>
#include<vector>
using namespace std;

int min_subset_sum_diff(vector<int>&arr,int diff){
    int sum=0,subset1;
    for (int i = 0; i < arr.size(); i++)
       sum+=arr[i];
    subset1=(diff+sum)/2;
    vector<vector<int>> dp(arr.size()+1,vector<int>(subset1+1));
    for (int i = 0; i <= arr.size(); i++)
      for (int j = 0; j <= subset1; j++)
      {
          if(i==0 || j==0){
              if(i==0)
                dp[i][j]=0; 
              if ( j==0)
                 dp[i][j]=1;
         }
         else if ( arr[i-1]<=j)
             dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
             else
              dp[i][j]=dp[i-1][j];
         
      }
      
    
    
  return dp[arr.size()][subset1];
}
int main(){
    int size,diff;
    cout<<"enter size of array: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];
    cout<<"Enter difference: ";
    cin>>diff;
    cout<<"number of subset sum difference is : "<<min_subset_sum_diff(arr,diff);
    
    return 0;
}