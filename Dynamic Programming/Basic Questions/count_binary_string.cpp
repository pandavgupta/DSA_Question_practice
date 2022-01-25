#include<iostream>
#include<vector>

using  namespace std;
// recursive way
// int count_binary_string(int n, string output){
 
//   if(output.size()==n)
//    return 1;

//    if(output.size() !=0 && output[output.size()-1] =='0')
//      return count_binary_string(n,output+"1");
//      else
//      return count_binary_string(n,output+"1")+count_binary_string(n,output+"0");

// }

// tabulation approach
// int count_binary_string(int n){
//   vector<vector<char>>dp(n);
//   dp[0].push_back("1");
//   dp[0].push_back("0");
//   for(int i=1; i<n; i++)
//    for(char x:dp[i-1]){
//      if(x=='1'){
//        dp[i].push_back('1');
//       dp[i].push_back('0');
//      }
//      else
//      dp[i].push_back('1');
//    }
//  return dp[n-1].size();
// }

// it's result  is  in fibonacci series
int count_binary_string(int n){
  if(n==0)
   return 0;
  int sum{};
  int a=1,b=1;
  for(int i=1; i<=n; i++){
    sum=a+b;
    b=a;
    a=sum;
   }
 return a;
}

int main(){
    int n{};
    cin>>n;
    // vector<int>dp(n+1);
    // cout<<count_binary_string(n,"");
cout<<count_binary_string(n);
    return 0;
}
