#include <iostream>

using namespace std;

int cs(int n){
    // recursive code
    // if(n<=2)
    //   return n;
    // if(n==3)
    //    return 4;
    
    // return cs(n-1)+cs(n-2)+cs(n-3);
    int dp[n+1]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"total stairs:";
    cin>>n;
    cout<<cs(n)<<endl;
}