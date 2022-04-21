#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp(size+1,0);
        dp[1]=nums[0];
        if(size == 1) return nums[0];
        vector<int>dp2(size+1,0);
        dp2[2]= nums[1];
        for(int i=1; i<=size;  i++){
            if(i>=2 && i!=size) dp[i] = max(dp[i-1],nums[i-1]+dp[i-2]);
            if(i>=3)  dp2[i] = max(dp2[i-1],nums[i-1]+dp2[i-2]);
        }
       
        return max(dp[size-1],dp2[size]);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n ; i++) cin>>arr[i];
    Solution obj;
    cout<<obj.rob(arr)<<endl;
    return 0;
}