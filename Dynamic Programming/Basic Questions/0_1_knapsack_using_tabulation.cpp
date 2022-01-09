#include<iostream>
using namespace std;
int static dp[51][21];

int main(){
    int *weight, *profit, W,N;
    cout<<"Enter the size of bag: ";
    cin>>W;
    cout<<"Enter the number of item available: ";
    cin>>N;
    weight= new int(N);
    profit= new int(N);
    cout<<" Enter the weight :";
    for (int i = 0; i < N; i++)
    cin>>weight[i];
    cout<<" Enter the profit :";
    for (int i = 0; i < N; i++)
    cin>>profit[i];
    for (int i = 0; i <=N; i++)
    {
        for (int j = 0; j <=W; j++)
        {
            if ( i==0 || j==0)
                dp[i][j]=0;

            else if(weight[i-1]<=j)
                 dp[i][j]= max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            else 
               dp[i][j]=dp[i-1][j];
            
        }
        
    }
    
    cout<<"Maximum profit is: "<<dp[N][W];

return 0;
}