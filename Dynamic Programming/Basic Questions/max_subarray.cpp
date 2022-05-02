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
// greedy approach:
int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        int maxv = nums[0];
        int sum {};
        for(auto i:nums){
            sum+=i;
            if(sum>maxv) maxv = sum;
            if(sum<0) sum =0;
        }
        return maxv;
    }
// dp approach:
    // int maxSubArray(vector<int>& nums) {
    //     int size = nums.size();
    //     if(size == 1) return nums[0];
    //     vector<int>dp(nums.size()+1);
    //     int maxv = nums[0];
    //     dp[0] =  nums[0];
    //     for(int i=1; i<size; i++){
    //         if(dp[i-1]+nums[i] < 0)
    //             dp[i] = nums[i];
    //         else 
    //             dp[i] = dp[i-1]+nums[i];
    //         maxv = max( maxv, dp[i]);
    //     }
    //     return maxv;
    // }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.maxSubArray(arr)<<endl;
    return 0;
}