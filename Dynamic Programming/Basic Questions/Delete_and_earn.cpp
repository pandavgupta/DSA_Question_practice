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
// Method-1, time complexity O(N), space complexity O(1) //space complexity is of size 10001
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int>dp(n);
        int take=0, takei=0, skip=0, skipi=0;
        for(auto num:nums) dp[num]+=num;
        for(int i=2; i<n ; i++ ){
            dp[i] = max(dp[i-1], dp[i-2]+dp[i]);
        }
        return dp[n-1];        
      
    }
    // Method-2 self develop, time complexity O(NlogN), space complexity O(N)
    // int deleteAndEarn(vector<int>& nums) {
    //     unordered_map<int,int>hash;
    //     int size = nums.size();
    //     for(int i=0; i<size; i++){
    //         hash[nums[i]]++;
    //     }
    //     vector<int>arr;
    //     for(auto i:hash) arr.push_back(i.first);
    //     sort(arr.begin(), arr.end());
    //     vector<int>dp(arr.size()+1);
    //     int prev;
    //     dp[1] = hash[arr[0]]*arr[0];
    //     for(int i=2; i<=arr.size(); i++){
    //         if(hash[arr[i-1]-1] >0){
    //             dp[i] = max(hash[arr[i-1]]*arr[i-1]+dp[i-2],dp[i-1]);
    //         }
    //         else {
    //             dp[i]=hash[arr[i-1]]*arr[i-1]+dp[i-1];
    //         }
    //     }
    //    return dp[arr.size()];
    // }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.deleteAndEarn(arr);
    return 0;
}