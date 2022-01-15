#include<iostream>
#include<vector>
using namespace std;


int coin_change_sum(vector<int>&nums,int target){
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1));
        for(int j=0; j<target+1; j++)
         dp[0][j]=INT_MAX-1;
         for(int i=1; i <= nums.size(); i++)
         dp[i][0]=0;
         for (int j = 1; j <=target; j++)
         {
             if(j%nums[0]==0)
               dp[1][j]=j/nums[0];
             else
               dp[1][j]=INT_MAX-1;
         }
        
        for(int i=2; i<=nums.size() ; i++)
            for(int j=1; j<=target; j++){
               
               if(nums[i-1]<=j)
                    dp[i][j]=min(1+dp[i][j-nums[i-1]],dp[i-1][j]);
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
    cout<<"min number of change possible : "<<res;
    
    return 0;
}