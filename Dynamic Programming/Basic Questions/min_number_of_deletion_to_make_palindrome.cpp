#include<iostream>
#include<vector>
using namespace std;

int min_of_deletion_to_make_palindrome(string str1,int n){
    string str2= str1;
    for(int i=0; i<n/2; i++){
      char tmp=str1[i];
      str2[i]=str2[n-i-1];
      str2[n-i-1]=tmp;
      
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++){
          if(str1[i-1]==str2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
          else
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
      return n-dp[n][n];
}


int main()
{
   string text1;
   cout<<"enter string: ";
   cin>>text1;
   cout<<min_of_deletion_to_make_palindrome(text1,text1.size());
    return 0;
}
