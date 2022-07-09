#include<bits/stdc++.h>
using namespace std;
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
class Solution {
public:
    // vector<int>dp;
    // int helper(vector<int>&nums, int k , int n){
    //     if(n <= 1){
    //         if(n == 1) return nums[0];
    //         return -1e7;
    //     }
    //     if(dp[n] != -1e9) return dp[n];
    //     int ans = -1e9;
    //     for(int i = 1; i <= k; i++){
    //        dp[n] = max(dp[n], nums[n-1] + helper(nums, k, n-i));
    //     }
    //     return dp[n] ;
    // }
    // int maxResult(vector<int>& nums, int k) {
    //     dp = vector<int>(nums.size()+1, -1e9);
    //  int ans = helper(nums, k, nums.size());
    //     return ans;
    // }
    // Method-2: using tabulation : time Complexity O(N*K) and space O(n)
    // int maxResult(vector<int>& nums, int k) {
    //     vector<int>dp(nums.size()+1, -1e9);
    //     dp[0] = nums[0];
    //     for(int i = 1; i  < nums.size(); i++){
    //         for(int j = 1; i-j>=0 && j <=k; j++){
    //             dp[i] = max(dp[i] , dp[i-j] + nums[i]);
    //         }
    //     }
    //     return dp[nums.size()-1];
    // }
// Method -3: using multiset for maintaining previous k last element; time complexity O(N*Log(K)) and space O(N); 
    // int maxResult(vector<int>& nums, int k) {
    //     vector<int>dp(nums.size(), 0);
    //     multiset<int, greater<int>>mset;
    //     mset.insert(nums[0]);
    //     dp[0] = nums[0];
    //     int maxv{};
    //     for(int i = 1; i  < nums.size(); i++){
    //         maxv = *(mset.begin());
    //         dp[i] = maxv + nums[i];
    //         mset.insert(dp[i]);
    //         if(mset.size() > k) mset.erase(mset.find(dp[i-k]));
    //     }
    //     return dp[nums.size()-1];
    // }
// Method -4: using deque for maintaining k max element; time complexity O(N) and space O(N)  
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size(), 0);
        deque<int>dq{0};
        dp[0] = nums[0];
        for(int i = 1; i  < nums.size(); i++){
            if(dq.front() < i-k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[nums.size()-1];
    }
};
int main(){
    string s;
    int n;
    cin>>s>>n;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.maxResult(arr, n);
    return  0;
}