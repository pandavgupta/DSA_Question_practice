#include<iostream>
#include<vector>
using namespace std;
int longestCommonSubstr(string text1, string text2){
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        dp[0][0]=0;
        int count{};
         for(int i=0; i<=text1.size(); i++){
             for(int j=0; j<=text2.size();j++){
                 if(i==0 || j==0){
                     dp[i][j]=0;
                 }
                 else if(text1[i-1]==text2[j-1]   ){
                     dp[i][j]=dp[i-1][j-1]+1;
                     count=max(count,dp[i][j]);
                 }
                 
             }
             
         }
            
   return count;
    }

int main()
{
   string text1,text2;
   cout<<"enter string: ";
   cin>>text1>>text2; 
   cout<<longestCommonSubstr(text1,text2);
    return 0;
}
