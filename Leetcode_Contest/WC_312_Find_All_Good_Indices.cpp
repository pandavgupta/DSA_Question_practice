#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Method -1: sliding window , time complexity O(N) and space complexity O(N)
    // vector<int> goodIndices(vector<int>& nums, int k) {
    //     if(nums.size() <= 2*k) return {};
    //     queue<int>bad_index1, bad_index2;
    //     vector<int>good_index;
    //     if(k == 1){
    //         for(int i = 1; i < nums.size()-1; i++) good_index.push_back(i);
    //         return good_index;
    //     }
    //     int start = 0, end = 0, i = 0, mid = 0;
    //     while(end <= 2*k){
    //         if(end < k){
    //             if(end && nums[end] > nums[end-1]) bad_index1.push(end); 
    //         }
    //         else if(end == k) mid = end;
    //         else if(end < 2*k){
    //             if(end > k+1  && nums[end] < nums[end-1]) bad_index2.push(end);
    //         }
    //         else{
    //             if(end > k+1 &&  nums[end] < nums[end-1]) bad_index2.push(end);
    //             if(bad_index1.empty() && bad_index2.empty()) good_index.push_back(mid);
    //         }
    //         end++;
    //     }
    //     while(end < nums.size()){
    //         if (nums[mid] > nums[mid-1]) bad_index1.push(mid);
    //         mid++;
    //         start++;
    //         if(!bad_index1.empty() && bad_index1.front() <= start) bad_index1.pop();
    //         if( nums[end] < nums[end-1]) bad_index2.push(end);
    //         if(!bad_index2.empty() && bad_index2.front() <= mid+1) bad_index2.pop();
    //         if(bad_index1.empty() && bad_index2.empty()) good_index.push_back(mid);
    //         end++;
    //     }
    //     return good_index;
    // }
// Method-2: using prefix and suffix concept , time complexity O(N) and space complexity O(N)
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>good_index, suffix(nums.size(), 1);
        int prefix = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] <= nums[i+1]) 
                suffix[i] = suffix[i+1]+1;
        }
        for(int i = 1; i < nums.size()-k; i++){
            if(i>=k && prefix >= k && suffix[i+1] >= k)
                good_index.push_back(i);
            if(nums[i] > nums[i-1]) prefix = 1;
            else prefix++;
        }
        return good_index;
    }
};
int main(){
    string s;
    int k;
    cin>>s>>k;
    s = s.substr(1, s.size()-2);
    string tmp;
    stringstream ss(s);
    vector<int>arr;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    Solution obj;
    vector<int>res = obj.goodIndices(arr,k);
    cout<<'[';
    for(int i = 0; i < res.size(); i++){
        cout<<res[i];
        if(i != res.size()-1) cout<<',';
    }
    cout<<"]";
    return 0;
}