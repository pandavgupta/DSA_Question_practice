#include<bits/stdc++.h>
using namespace std;
    int findDuplicate(vector<int>& nums) {
        int sum=1, size = nums.size();
        for(int i=2; i<=size-1; i++)
            sum = sum^nums[i];
        for(int i=0; i< size; i++){
            sum= sum^nums[i];
                
        }
        return sum;
    }

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
      cin>>arr[i];
    cout<<findDuplicate(arr);
    return 0;

}