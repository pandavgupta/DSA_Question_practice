#include <iostream>
using namespace std;
// int count=0;
int cs(int arr[], int n){
 // recurcive code 
//   ,int idx=0
//   if(idx>=n){
//      if(idx==n)
//       return 1;
//     return 0;
//   }
  
//  int count=0;
//  for(int i=1; i<=arr[idx]; i++){
//     count+=cs(arr,n,idx+i);
//   }

// return count;

int dp[n+1]={0};
dp[n]=1;
for(int i=n-1; i>=0; i--){
  for(int j=1;j<=arr[i] && i+j<=n; j++){
      
       dp[i]+=dp[i+j];
  }
}
 
 return dp[0];

}

int main(){
    int n;
    cout<<"enter number of stairs:";
    cin>>n;
    int arr[n];
    cout<<"enter number of jump:";
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}