#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int coin_change_sum(vector<int>&nums,int target){
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1));
        
        for(int i=0; i<=nums.size() ; i++)
            for(int j=0; j<=target; j++){
                if ( i==0 || j==0)
                {
                  if ( i==0)
                    dp[i][j]=0;
                  if ( j==0)
                    dp[i][j]=1;
                  
                }
                
               else if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        return dp[nums.size()][target];
}
int main(){
    int size,price;
    cout<<"enter size of array: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];
    cout<<"Enter total money: ";
    cin>>price;
    int res=coin_change_sum(arr,price);
    cout<<"max number of change possible : "<<res;
    
    return 0;
}