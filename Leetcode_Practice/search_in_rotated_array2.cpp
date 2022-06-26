#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]) return true;
            if(nums[mid] == nums[start] && nums[end] == nums[mid]) {
                start++; end--;
            }
            else if(nums[start] <= nums[mid]){
                 if(nums[start] <=target && target <=nums[mid] ) end = mid-1;
                else start = mid+1;
            }
            else{
               if(nums[mid] <=target && target <=nums[end] ) start = mid+1;
                else end = mid-1;
            }
        }
        return false;
    }
int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0; i<size; i++)
       cin>>arr[i];
    int target;
    cin>>target;
    if(search(arr,target)) cout<<"true";
    else cout<<"false";
    return 0;
}