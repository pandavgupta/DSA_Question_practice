#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
       vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1) return {};
        vector<int>original;
        unordered_map<int,int>hash;
        for(int i:changed) hash[i]++;
        sort(changed.begin(), changed.end());
        for(int i:changed){
            if(hash[i] > 0){
                hash[i]--;
                int val = i*2;
                if(hash.count(val) && hash[val] > 0){
                    original.push_back(i);
                    hash[val]--;
                }
                else return {};
            }
        }
        return original;
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<int>arr;
    while(getline(ss, tmp, ',')) arr.push_back(stoi(tmp));
    Solution obj;
    vector<int>res = obj.findOriginalArray(arr);
    cout<<"[";
    for(int i:res) cout<<i<<" ";
    cout<<"]"<<endl;
    return 0;
}