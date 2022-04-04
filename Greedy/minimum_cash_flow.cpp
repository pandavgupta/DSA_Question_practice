// C++ program to find maximum cash flow among a set of persons
#include<bits/stdc++.h>
using namespace std;
/*
pair<int,int> getMin(vector<int>arr){
    int i=0, mi{0}, ma{0};
    for(int i=1; i<arr.size(); i++){
    if(arr[mi] > arr[i]) mi =i;
     if(arr[ma] < arr[i]) ma= i;
    }
    return {mi,ma};
}

void settle_cash(vector<int>&arr, int &minv){
    pair<int,int>value = getMin(arr);
    if(arr[value.first]==0 && arr[value.second]==0) return;
    int cash = min(-arr[value.first],arr[value.second]);
    minv += cash;
    arr[value.first]+=cash;
    arr[value.second]-=cash;
    settle_cash(arr,minv);
    
}
*/
int minCashFlow(vector<vector<int>>& money, int n)
{
   vector<int>arr(n,0);
    int minv{0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                arr[i]-=money[i][j];
                arr[j]+=money[i][j];
            }
        }
    }

//    settle_cash(arr, minv); // for knowning the flow of cash
    for(int i=0; i<n; i++){
        if(arr[i]>0) minv+=arr[i];
    }
   return minv;
}

int main()
{
    int n;
    cin>>n;
	vector<vector<int>>graph(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0;  j<n; j++)
         cin>>graph[i][j];
    }

	// Print the solution
	cout<<minCashFlow(graph,n);
	return 0;
}
