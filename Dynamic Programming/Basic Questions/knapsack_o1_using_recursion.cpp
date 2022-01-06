#include<iostream>
using namespace std;

int knapsack(int *weight,int *profit, int W, int N){
  if (W== 0 || N==0)
   return 0;
  if(weight[N-1]<=W)
  return max(knapsack(weight,profit,W,N-1), profit[N-1] + knapsack(weight,profit,W-weight[N-1],N-1));
  else
  return knapsack(weight,profit,W,N-1);

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
    cout<<"Maximum profit is: "<<knapsack(weight,profit,W,N);

return 0;
}