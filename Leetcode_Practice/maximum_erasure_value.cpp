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
 int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,pair<int,int>>mymap;
//         first is key and pair consist of starting index of sliding window and local sum.
        int i = 0, j = 0, sum{}, local{};
        while(j < nums.size()){
            if(mymap.find(nums[j]) != mymap.end() && mymap[nums[j]].first >= i) 
                local -= mymap[nums[j]].second, i = mymap[nums[j]].first + 1;
            local += nums[j];
            mymap[nums[j]] = {j,local};
            j++;
            if(local > sum) sum = local;
        }
        
        return sum;
    }
int main(){
     string s;
     cin>>s;
     vector<int>arr = getArray(s);
     cout<<maximumUniqueSubarray(arr);
    return 0;
}