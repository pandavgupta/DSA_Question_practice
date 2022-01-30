#include<iostream>
#include<vector>
using namespace std;

// string longestCommonSubsequence(string text1, string text2){
//         vector<vector<string>>dp(text1.size()+1,vector<string>(text2.size()+1,""));
//         dp[0][0]="";
//          for(int i=0; i<=text1.size(); i++){
//              for(int j=0; j<=text2.size();j++){
//                  if(i==0 || j==0){
//                      dp[i][j]="";
//                  }
//                  else if(text1[i-1]==text2[j-1]   ){
//                      dp[i][j]=dp[i-1][j-1]+text2[j-1];
//                  }
                      
//                  else {
//                      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 
//                  }
//              }
             
//          }
            
//    return dp[text1.size()][text2.size()];
//     }

string longestCommonSubsequence(string text1, string text2){
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        dp[0][0]=0;
         for(int i=0; i<=text1.size(); i++){
             for(int j=0; j<=text2.size();j++){
                 if(i==0 || j==0){
                     dp[i][j]=0;
                 }
                 else if(text1[i-1]==text2[j-1]   ){
                     dp[i][j]=dp[i-1][j-1]+1;
                 }
                      
                 else {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 
                 }
             }
             
         }
     int i=text1.size(),j=text2.size() ;
     int lcs=dp[text1.size()][text2.size()];
     string output="";
     while (i>0 && j>0)
     {
        if(text1[i-1]==text2[j-1]){
            output=text1[i-1]+output;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
     }
     return output;
     
    }
int main()
{
   string text1,text2;
   cout<<"enter string: ";
   cin>>text1>>text2; 
//    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
//    dp[0][0]=0;
   cout<<longestCommonSubsequence(text1,text2);
    return 0;
}
