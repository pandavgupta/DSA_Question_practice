#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>res(nums.size());
        res[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            res[i] = res[i-1]*nums[i];
        }
        int suffix = 1;
        for(int i = nums.size()-1; i > 0; i--){
            res[i] = res[i-1]*suffix;
            suffix = suffix*nums[i];
        }
        res[0] = suffix;
        return res;
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<int>arr;
    while(getline(ss, tmp,',')) arr.push_back(stoi(tmp));
    Solution obj;
    vector<int>res = obj.productExceptSelf(arr);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}