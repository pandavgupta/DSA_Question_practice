#include<iostream>
#include<vector>
using namespace std;
bool isSubsetAvailable(vector<int>& arr,int sum){
    vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1));
    
    for (int i = 0; i <=arr.size(); i++)
    for (int j = 0; j <=sum; j++)
    {
        if(i==0 | j==0){
             if(i==0 )
               dp[i][j]=false;
             if(j==0)
              dp[i][j]=true;
        }
        
        else if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
        else
           dp[i][j]=dp[i-1][j];
        
    }

    return dp[arr.size()][sum];
}

bool isEqualSubsetSum(vector<int>& arr){
    int sum=0;
    for (int i = 0; i < arr.size(); i++)
       sum=sum+arr[i];
    
    if( sum%2!=0)
       return false;
    
    return isSubsetAvailable(arr, sum/2); 
    

}

int main(){
    int  size,tmp;
    vector<int>arr;
    cout<<"Enter the size of array :";
    cin>>size;
    cout<<"Enter the element of array :";
    for (int i = 0; i < size; i++){
    cin>>tmp;
    arr.push_back(tmp);
    }
    cout<<isEqualSubsetSum(arr);
  return 0;
}