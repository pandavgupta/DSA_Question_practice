#include<bits/stdc++.h>
using namespace std;
# define M 1000000007
long long int maxProductSubset(vector<int> &arr, int n)
{
    if(n == 0) return 0;
	if(n==1) return arr[0];
	long long int product{1};
	int minv{-1}, negative{0}, positive{0} ,zero{0}, flag=0;
	// first finding count of positive and negative element 
	for(int i=0; i<n; i++){
		if(arr[i] < 0 ){
			negative++;
			if(minv == -1) minv = i;
			else{
			  if(arr[i] > arr[minv]) minv = i;	
			}
		}
		else if(arr[i] >0) positive++;
	}
	for(int i=0; i<n; i++){
		
		if(arr[i]==0) zero=1;
		else if(i == minv && negative&1) continue;
		else product = (product*arr[i])%M;
	}
	if(zero && !positive && negative==1) return 0;
	if(zero && !negative && !positive) return 0;
	return product;
} 
// generating all possible subset Time complexity O(2^N)
// void Find_max(vector<int>&set, long long int & maxv){
// 	if(set.size()==0) return ;
// 	long long int product =1;
// 	for(auto i:set){
// 		product=(product*i)%M;
// 	}
// 	maxv = max(maxv, product);
// 	return ;
	
// }
// void max_product(vector<int>& nums , int i,long long int &maxv,vector<int>&set){
//     	if(i==nums.size()){
//     		Find_max(set,maxv);
//     		return ;
//     	}
//     	set.push_back(nums[i]);
//     	max_product(nums, i+1, maxv, set);
// 	    set.pop_back();
//     	max_product(nums, i+1, maxv, set);
//     	return ;
    	
//     }
// 	long long int maxProductSubset(vector<int>&nums, int n)
// 	{
// 		if(nums.size()==0) return 0;
// 		if(nums.size()==1) return nums[0];
// 	    long long int maxv = nums[0];
// 		vector<int>set;
// 	    max_product(nums, 0, maxv, set);
// 	    return maxv;
// 	}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<maxProductSubset(arr, arr.size())<<endl;
        
    }
    return 0;
}