#include<iostream>
#include<vector>
using namespace std;

int rod_cutting(vector<int>&price,vector<int>&length){
    vector<vector<int>>dp(length.size()+1,vector<int>(price.size()+1));
    for (int i = 0; i <= length.size(); i++)
      for (int j = 0; j <= price.size(); j++)
      {
           if(i==0 || j==0)
               dp[i][j]=0;

            else if ( length[i-1]<=j)
                  dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];

      }
    
    return dp[length.size()][price.size()];
}

int main(){
    int size_of_rod,size_of_pieces;
    cout<<"enter size of rod: ";
    cin>>size_of_rod;
    vector<int>arr1(size_of_rod);
    cout<<"enter price of rod (in increasing order of it's pieces): ";
    for (int i = 0; i < size_of_rod; i++)
    cin>>arr1[i];
    cout<<"enter number of cut: ";
    cin>>size_of_pieces;
    vector<int>arr2(size_of_pieces);
    cout<<"enter the pieces: ";
    for (int i = 0; i < size_of_pieces; i++)
    cin>>arr2[i];
    int res=rod_cutting(arr1,arr2);
    cout<<"max profit : "<<res;
    
    return 0;
}