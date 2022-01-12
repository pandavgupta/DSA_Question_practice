#include<iostream>
#include<vector>
using namespace std;

int min_subset_sum_diff(vector<int>&arr){
    int sum=0;
    for (int i = 0; i < arr.size(); i++)
       sum+=arr[i];
    vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum/2+1));
    for (int i = 0; i <=arr.size(); i++)
       for (int j = 0; j <=sum/2; j++)
       {
           if(i==0 || j==0){
               if(i==0)
                 dp[i][j]=false;
               if ( j==0)
                 dp[i][j]=true;

               
           }
           else if(arr[i-1]<=j)
               dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
               dp[i][j]=dp[i-1][j];
       }
       
       
    for (int i = sum/2; i >=0; i--)
    {
        if(dp[arr.size()][i])
          return sum-2*i;
    }
    
  return 0;
}


int main(){
    int size;
    cout<<"enter size of array: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];
    cout<<"minimum subet sum difference is : "<<min_subset_sum_diff(arr);
    
    return 0;
}