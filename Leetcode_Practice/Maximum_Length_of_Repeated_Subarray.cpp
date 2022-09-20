#include<bits/stdc++.h>
using namespace std;
vector<int> getArray(string s){
    s = s.substr(1,s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<int>arr;
    while (getline(ss, tmp, ',')) arr.push_back(stoi(tmp));
    return arr;
}
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      vector<vector<int>>dp(2, vector<int>(nums2.size()+1));
        int result{};
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i%2][j] = dp[(i-1)%2][j-1]+1;
                    result = max(result, dp[i%2][j]);
                }
                else dp[i%2][j] = 0;
            }
        }
        return result;
    }
};
int main(){
    string s1, s2;
    cin>>s1>>s2;
    vector<int>arr1,arr2;
    Solution obj;
    arr1 = getArray(s1);
    arr2 = getArray(s2);
    cout<<obj.findLength(arr1, arr2)<<'\n';
    return 0;
}