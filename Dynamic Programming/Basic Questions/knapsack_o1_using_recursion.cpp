#include<iostream>
using namespace std;

int knapsack(int wt[], int profit[], int W, int N){
    if(W==0 || N==0)
      return 0;
    if ( wt[N]>W)
      return knapsack(wt,profit, W, N-1);
    else
      return max(knapsack(wt,profit, W, N-1),profit[N]+knapsack(wt,profit, W-wt[N], N-1));  
    
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
    cout<<"Maximum profit is: "<<knapsack(weight,profit,W,N-1);

return 0;
}