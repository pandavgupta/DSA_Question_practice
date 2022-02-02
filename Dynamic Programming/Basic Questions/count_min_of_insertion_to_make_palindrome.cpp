#include<iostream>
#include<vector>
using namespace std;
int countMin(string str){
     string str2=str;
     int n=str.size();
     for(int i=0; i<n/2; i++){
         char tmp =str2[i];
         str2[i]= str2[n-i-1];
         str2[n-i-1]= tmp;
     }
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
         for(int i=1; i<=n; i++){
             for(int j=1; j<=n;j++){
                  if(str[i-1]==str2[j-1]){
                     dp[i][j]=dp[i-1][j-1]+1;
                 }
                      
                 else {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 
                 }
             }
             
         }
         return n-dp[n][n];
    }
int main()
{
   string text1;
   cout<<"enter string: ";
   cin>>text1;
   cout<<countMin(text1);
    return 0;
}