#include<iostream>
#include<vector>
using namespace std;
int minOperations(string str1, string str2) 
	{ int n=str1.size(),m=str2.size();
	   vector<vector<int>>dp(n+1,vector<int>(m+1));
	   for(int i=0; i<=n; i++){
	       for(int j=0; j<=m ;j++){
	          if(i==0 || j==0)
	            dp[i][j]=0;
	          else if(str1[i-1]==str2[j-1])
	                   dp[i][j]=1+dp[i-1][j-1];
	               else
	                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
	       }
	         
	       
	   }
	   
	   return n+m-2*dp[n][m];
	    
	} 
int main(){
    string s1,s2;
    cout<<"enter strings :";
    cin>>s1>>s2;
    cout<<minOperations(s1,s2);
    return 0;
}