
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// using recursion
//  int longestCommonSubsequence(string text1, string text2,vector<vector<int>> &dp)  {
//         if(dp[text1.size()][text1.size()]!=-1)
//          return dp[text1.size()][text1.size()];

//         if(text1.size()==0|| text2.size()==0)
//              return 0;
          
//         int count{};
        
//         if(text1[text1.size()-1]==text2[text2.size()-1]){
//             count=1+longestCommonSubsequence(text1.substr(0,text1.size()-1),text2.substr(0,text2.size()-1),dp);
//         }
//         else if(text1.size()!=text2.size()){
               
//             count=max(longestCommonSubsequence(text1.substr(0,text1.size()),text2.substr(0,text2.size()-1),dp),
//             longestCommonSubsequence(text1.substr(0,text1.size()-1),text2.substr(0,text2.size()),dp));

//             count=max(  count  ,  longestCommonSubsequence(text1.substr(0,text1.size()-1),text2.substr(0,text2.size()-1),dp));
            
//         }  
        
        
//         return dp[text1.size()][text1.size()]=count;
//     }
      int longestCommonSubsequence(string text1, string text2){
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
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
            
   return dp[text1.size()][text2.size()];
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
