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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int count{};
        for(auto i:nums){
            hash[i]++;
        }
        for(auto i:hash){
            int sec_key = k-i.first;
                if(hash[i.first] >0){
                    if(sec_key == i.first){
                            count+=i.second/2;
                        hash[i.first] = 0;
                        i.second = hash[i.first];
                    }
                    else {
                        if(hash.find(sec_key)==hash.end()) continue;
                        int minv = min(i.second,hash[k-i.first]);
                        count+=minv;
                        hash[i.first] -=minv ;
                        i.second = hash[i.first];
                        hash[sec_key]-= minv;
                    }
                        
                    
                }
        }
        return count;
    }
};
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.maxOperations(arr,k)<<endl;
    return 0;
}