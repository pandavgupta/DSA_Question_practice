#include<bits/stdc++.h>
using namespace std;
int maxAbsSum(vector<int> &arr, int n) 
{
	sort(arr.begin(), arr.end());
	int sum=0;
    int i=0, j=n-1, flag=1;
	while(i<j){
		sum+=abs(arr[i]-arr[j]);
		if(flag){
			i++;
			flag=0;
		}
		else{
			j--;
			flag=1;
		}
	}
	if(i>0){
		sum+=abs(arr[0]-arr[i]);
	}
	return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<maxAbsSum(arr,n)<<endl;
    }
    return 0;
}