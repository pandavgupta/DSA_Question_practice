#include<bits/stdc++.h>
using namespace std;
 int search(vector<int>& nums, int target) {
        int size = nums.size();
        int start{};
        int end = size-1;
        int mid{};
        while(start <= end){
            mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            if(nums[start] <= nums[mid]){
                if( target >= nums[start] && target <= nums[mid]) end = mid-1;
                else start = mid+1;
            }
            else{
                if( target > nums[mid] && target<=nums[end]) start = mid+1;
                else end = mid-1;
            }
            
        }
        return -1;
    }
int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0; i<size; i++)
       cin>>arr[i];
    int target;
    cin>>target;
    cout<<search(arr,target);
   
    return 0;
}