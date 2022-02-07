#include<iostream>
#include<vector>
using namespace std;
// matrix chain multiplication using dp
int matrix_chain_multiplication(vector<int>arr, int size){
    vector<vector<int>>dp(size,vector<int>(size+1,INT_MAX));
    int current_cost,total_cost,right_pointer;
    for (int i = 1; i < size; i++)
    {
        dp[i][i]=0;
    }
    for (int  win = 2; win <=size-1; win++)
    {
        for (int left_pointer = 1; left_pointer<=size-win; left_pointer++)
        {
            right_pointer= left_pointer+win-1;
           for (int partition = left_pointer; partition< right_pointer; partition++)
           {   current_cost = arr[left_pointer-1]*arr[partition]*arr[right_pointer];
               total_cost= dp[left_pointer][partition] +dp[partition+1][right_pointer] +current_cost;
               dp[left_pointer][right_pointer]=min(dp[left_pointer][right_pointer],total_cost);
           }
           

        }
        
    }
    
    
    return dp[1][size-1];
}

// solution using recursive and memoization
// int matrix_chain_multiplication(vector<int>arr,int i,int j,vector<vector<int>>&dp){
//    if(dp[i][j]!=0)
//      return dp[i][j];
//     if(i>=j)
//       return 0;
//     int minV=1e9,tmp;
//     for (int k = i; k < j; k++)
//     {
//         tmp =matrix_chain_multiplication(arr,i,k,dp)+matrix_chain_multiplication(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
//         minV=min(minV,tmp);
//     }
    
//     return dp[i][j]=minV;
// }

int main(){
    int size;
    cout<<"enter size of array: ";
    cin>>size;
    vector<int>arr(size);
    for (int i = 0; i < size; i++)
       cin>>arr[i];
    // vector<vector<int>>dp(size+1,vector<int>(size+1));
    // cout<<matrix_chain_multiplication(arr,1,size-1,dp);
    cout<<matrix_chain_multiplication(arr,size);
    return 0;  
} 