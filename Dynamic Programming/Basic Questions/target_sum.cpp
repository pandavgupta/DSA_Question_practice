#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// int power(int n1, int n2){
//     if ( n2==1)
//         return n1;
//     int k=power(n1,n2/2);
//     k= k*k;
//     if(n2%2!=0)
//     return k*n1;
//     return k;
// }

int target_sum(vector<int>&nums,int target){
    int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(target>sum)
            return 0;
        else if(target ==0){
            if(sum%2!=0)
                 return 0;
        }
        int subset1=(target+sum)/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(subset1+1));
        dp[0][0]=1;
        for (int  i = 1; i <=nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[j]==0)
                   dp[i][0]++;
            }
          dp[i][0]=pow(2,dp[i][0]);
            
        }
        
        for(int i=1; i<=nums.size() ; i++)
            for(int j=1; j<=subset1; j++){
               if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        
        for(int i=1; i<=nums.size() ; i++)
            for(int j=1; j<=subset1; j++){
               if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }

            for(int i=0; i<=nums.size() ; i++){
                for(int j=0; j<=subset1; j++){
                cout<<dp[i][j]<<" ";
              }
              cout<<endl;
            }
            

            
        return dp[nums.size()][subset1];
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
    int res=target_sum(arr,diff);
    cout<<"number of subset sum difference is : "<<res;
    
    return 0;
}