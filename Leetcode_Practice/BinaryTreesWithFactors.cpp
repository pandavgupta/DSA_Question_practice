#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int,long>dp;
        int M = 1e9+7;
        for(auto i:arr) dp[i] = 1;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[i]%arr[j] == 0 && dp.find(arr[i]/arr[j]) != dp.end()) dp[arr[i]]+= (dp[arr[j]]*dp[arr[i]/arr[j]])%M;
            }
        }
        long sum{};
        
        for(auto i:dp) sum += i.second;
        return sum%M;
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    vector<int>arr;
    string tmp;
    while (getline(ss, tmp,',')) arr.push_back(stoi(tmp));
    Solution obj;
    cout<<obj.numFactoredBinaryTrees(arr)<<endl;
    
    return 0;
}