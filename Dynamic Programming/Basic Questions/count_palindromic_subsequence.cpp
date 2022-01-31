#include<iostream>
#include<vector>

using namespace std;

bool ispalindrome(string s){
    if(s=="")
    return 0;
    int size=s.size();
    char tmp;
    for(int i=0; i<size/2; i++){
       if(s[i]!=s[size-i-1])
        return 0;
    }
    return 1;
}
// applying dp with own method
// int count_palindromic_subsequence(string s){
//     vector<vector<string>>dp(s.size()+1);
//     int count{};
//     dp[0].push_back("");
//     dp[0].push_back(""+s[0]);
//     for(int i=1; i<s.size()+1; i++){
//         for(int j=0; j<dp[i-1].size();j++){
//             dp[i].push_back(dp[i-1][j]+s[i-1]);
//             dp[i].push_back(dp[i-1][j]);
//         }

//     }
//     for(auto it:dp[s.size()]){
//         if(ispalindrome(it))
//          count=count>it.size()?count:it.size();
//     }
//     return count;
// }


// count longest palindromic subsequence using recursion
// int count_palindromic_subsequence(string s, string output){
//     if(s.size()==0){
//         if(ispalindrome( output))
//           return output.size();
//         return 0;

//     }
//   return max(count_palindromic_subsequence(s.substr(1),output+s[0]),count_palindromic_subsequence(s.substr(1),output));

// }


// derive from LCS
int count_palindromic_subsequence(string s){
    string s2=s;
    int size=s2.size();
    for(int i=0; i<s.size()/2; i++){
         char tmp=s2[i];
         s2[i]=s2[size-i-1];
         s2[size-i-1]=tmp;
    }
    cout<<s2<<" " ;
    vector<vector<int>>dp(s.size()+1,vector<int>(s2.size()+1,0));
    for (int i = 0; i <=s.size(); i++)
    {
        for (int j = 0; j <=s.size(); j++)
        {   if(i==0 || j==0)
             dp[i][j]=0;
            else if(s[i-1]==s2[j-1])
              dp[i][j]=1+dp[i-1][j-1];
            else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        
        
    }

    return dp[s.size()][s2.size()];
    
}

int main(){
    string s;
    cout<<"enter string ";
    cin>>s;

    // cout<<count_palindromic_subsequence(s,"");
    cout<<count_palindromic_subsequence(s);

    return 0;
}