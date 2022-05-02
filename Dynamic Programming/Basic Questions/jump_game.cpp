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
bool canJump(vector<int>& nums){
        int max_reach{}, size = nums.size();
        for( int i=0; i<size; i++){
            if(max_reach < i) return false;
            max_reach = max(max_reach,i+nums[i]);
        }
        return true;
    }
//  dynamic approach:
    //     bool canJump(vector<int>& nums){
    //     // vector<vector<bool>> dp(nums.size()+1, vector<bool>(nums.size()+1, false));
    //     vector<bool>dp(nums.size());
    //     int size = nums.size();
    //     dp[0]=true;
    //     for(int i=0; i<size; i++){
    //         if(dp[i]==false) return false;
    //         for(int j=1; j<=nums[i]; j++){
    //             if(i+j >=size) break;
    //             dp[i+j] = true;
    //         }
    //         if(dp[size-1]) return true;
    //     }
    //     return false;
    // }
// recursive approach
//     bool jump(vector<int>& nums, int i=0){
//         if(i>=nums.size()-1){ return true;
//         }
//         if(nums[i]==0) return false;
//         bool res = false;
//         int val = nums[i];
//         for(int j=1; j<=val; j++){
//             if(res) return true;
//             res = res || canJump(nums, i+j); 
//         }
//         return res;
//     }
//     bool canJump(vector<int>& nums) {
//         if(nums.size()==1) return true;
//         vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1));
        
//     }
    
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.canJump(arr)<<endl;
    return 0;
}