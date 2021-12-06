#include<iostream>
#include<cstring>
using namespace std;
int static mem[102][102];
int knapsack(int wt[], int profit[], int W, int N){
    if(W==0 || N==0)
      return 0;
    if (mem[W][N]!=-1) return mem[W][N];
    
    if ( wt[N]>W)
      return mem[W][N]=knapsack(wt,profit, W, N-1);
    else
      return mem[W][N]=max(knapsack(wt,profit, W, N-1),profit[N]+knapsack(wt,profit, W-wt[N], N-1));  
    
}

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
    memset(mem,-1, sizeof(mem));
    cout<<"Maximum profit is: "<<knapsack(weight,profit,W,N-1);

return 0;
}