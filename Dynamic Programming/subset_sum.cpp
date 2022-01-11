#include<iostream>
#include<vector>
using namespace std;
// checking whether subset sum is available in array or not.
bool isSubsetAvailable(int arr[],int size,int sum){
    vector<vector<bool>> dp(size+1,vector<bool>(sum+1));
    
    for (int i = 0; i <=size; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
          if(i==0 || j==0){
             if(i==0)
               dp[i][j]=false;
             if(j==0)
              dp[i][j]=true;
           
            }
            
           else {
               if(arr[i-1]<=j)
                   dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else 
                   dp[i][j]=dp[i-1][j];
           }
           
           
        }
        
    }
    return dp[size][sum];
}

int main(){
    int *arr, size, sum;
    cout<<"Enter the size of array :";
    cin>>size;
    cout<<"Enter the sum of subset :";
    cin>>sum;
    arr=new int(size);
    cout<<"Enter the element of array :";
    for (int i = 0; i < size; i++)
    cin>>arr[i];
    cout<<isSubsetAvailable(arr,size,sum);
    


}