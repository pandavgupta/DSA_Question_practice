#include<bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash{{0,0}};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(!hash.count(sum%k)) hash[sum%k] = i+1;
            else if(hash[sum%k] < i) return true;
        }
        return false;
    }
int main(){
    string s;
    int k;
    cin>>s>>k;
    s = s.substr(1, s.size()-2);
    string tmp;
    stringstream ss(s);
    vector<int>arr;
    while(getline(ss, tmp, ',')) arr.push_back(stoi(tmp));
    if(checkSubarraySum(arr,k)) cout<<"true";
    else cout<<"false";
    cout<<'\n';
    return 0;
}