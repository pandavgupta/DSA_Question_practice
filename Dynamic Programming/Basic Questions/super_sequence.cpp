#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//printing supersubsequence using recursion
// void supersubsequence(string s1,string s2,int n, int m, string output){
//     if(n<=0 || m<=0){
//         if(n==0 && m==0)
//           cout<<output<<endl;
//         else{
//             if(n==0){
//                 output=s2.substr(0,m)+output;
//                 cout<<output<<endl;
                
//             }
//             else{
//                 output=s1.substr(0,n)+output;
//                 cout<<output<<endl;
//             }
//         }
//         return ;
//     }
//     if(s1[n-1]==s2[m-1]){
//          supersubsequence(s1,s2,n-1,m-1,s1[n-1]+output);
//     }
//    else
//     {supersubsequence(s1,s2,n-1,m,s1[n-1]+output),supersubsequence(s1,s2,n,m-1,s2[m-1]+output);}
 
//     return ;
// }


//recursive approach to count number of super subsequence
// int shortestsupersubsequence(string s1,string s2,int n, int m, string output){
//     if(n==0 || m==0){
//         if(n==0 && m==0)
//              return output.size();
//         //   cout<<output<<endl;
//         else{
//             if(n==0){
//                 output=s2.substr(0,m)+output;
//                 // cout<<output<<endl;
//                 return output.size();
                
//             }
//             else{
//                 output=s1.substr(0,n)+output;
//                 // cout<<output<<endl;
//                 return output.size();
//             }
//         }
//         return 0;
//     }
    
//     if(s1[n-1]==s2[m-1]){
//         return shortestsupersubsequence(s1,s2,n-1,m-1,s1[n-1]+output);
//     }
//    else
//     { 
//         return min(shortestsupersubsequence(s1,s2,n-1,m,s1[n-1]+output),shortestsupersubsequence(s1,s2,n,m-1,s2[m-1]+output));
//         }
//     return 0;
// }

// int shortestsupersubsequence(string s1,string s2,int n, int m){
//     vector<vector<pair<int,string>>dp()
//     return;
// }


// recursive without using extra variable
// int shortestsupersubsequence(string s1,string s2,int n, int m){
//     if(n<=0 || m<=0){
//         if(n==0 && m==0)
//              return 0;
//         //   cout<<output<<endl;
//         else{
//             if(n==0){
//                 // output=s2.substr(0,m)+output;
//                 // cout<<output<<endl;
//                 return (s2.substr(0,m)).size();
                
//             }
//             else{
//                 // output=s1.substr(0,n)+output;
//                 // cout<<output<<endl;
//                 return (s1.substr(0,n)).size();
//             }
//         }
//         return 0;
//     }
    
//     if(s1[n-1]==s2[m-1]){
//         return 1+shortestsupersubsequence(s1,s2,n-1,m-1);
//     }
//    else
//     { 
        
//         return min(1+shortestsupersubsequence(s1,s2,n-1,m),1+shortestsupersubsequence(s1,s2,n,m-1));
//         }
   
// }



// count using dp
// int shortestCommonSupersequence(string s1, string s2, int n, int m){
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
//       for(int i=0; i<=n; i++)
//       for(int j=0; j<=m; j++){
//           if(i==0 || j==0)
//            dp[i][j]=0;
//           else if(s1[i-1]==s2[j-1]){
//               dp[i][j]=1+dp[i-1][j-1];
//           }
//           else
//           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//       }
       
       
//       return n+m-dp[n][m];
//     }




void shortestCommonSupersequence(string text1, string text2){
    int n=text1.size();
    int m=text2.size();
    string output="";
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for(int i=0; i<=n; i++)
   for(int j=0; j<=m; j++){
       if(i==0 || j==0) dp[i][j]=0;
       else if(text1[i-1]==text2[j-1]){
       dp[i][j]=1+dp[i-1][j-1];
       }
       else
       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
         
   }
   for (int i = 0; i <=n; i++)
   {
       for (int j = 0; j <=m; j++)
       {
           cout<<dp[i][j]<<" ";

       }
       cout<<"\n";
       
   }
   
   int i=n,j=m;
   while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
         output=text1[i-1]+output;
         j--;i--;
        }
          
        else{
            if(dp[i-1][j]>dp[i][j-1]){
              i--;
              output=text1[i]+output;
            }
             
             else{
                j--;
                output=text2[j]+output;
             }
            
        }
   }
   if(i!=0 || j!=0){
       if(j){
           while(j>0){
               output=text2[j-1]+output;
               j--;
           }
       }
       else{
           while(i>0){
               output=text1[i-1]+output;
               i--;
           }

       }
   }


   cout<<output;     
   return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
   string s1,s2;
   cin>>s1>>s2;
//    supersubsequence(s1,s2,s1.size(),s2.size(),"");
  
//  cout<<shortestsupersubsequence(s1,s2,s1.size(),s2.size());
// cout<<shortestCommonSupersequence(s1,s2,s1.size(),s2.size());
shortestCommonSupersequence(s1,s2);
    return 0;
}
