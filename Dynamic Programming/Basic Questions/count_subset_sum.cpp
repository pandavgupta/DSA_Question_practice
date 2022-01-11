#include<iostream>
#include<vector>
using namespace std;
// checking whether subset sum is available in array or not.
int countSubsetAvailable(vector<int>&arr,int sum){
    vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1));
   
    for (int i = 0; i <=arr.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
          
             if(i==0 || j==0)
              { if(i==0 )
                 dp[i][j]=0;
               if(j==0){
                 dp[i][j]=1;
                 
               }
             }
           else {
               if(arr[i-1]<=j)
                   dp[i][j]= dp[i-1][j-arr[i-1]]+ dp[i-1][j];
                else 
                   dp[i][j]=dp[i-1][j];
           }
           
           
        }
        
    }
    return dp[arr.size()][sum];
}

int main(){
    int size, sum,tmp;
    vector<int>arr;
    cout<<"Enter the size of array :";
    cin>>size;
    cout<<"Enter the sum of subset :";
    cin>>sum;
    cout<<"Enter the element of array :";
    for (int i = 0; i < size; i++){
    cin>>tmp;
    arr.push_back(tmp);
    }
    cout<<countSubsetAvailable(arr,sum);
    


}