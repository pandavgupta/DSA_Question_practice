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
int minOperations(vector<int>& nums, int x) {
        int i = 0, j = nums.size()-1, count = 0;
        while(i <=j && (nums[i] <= x || nums[j] <= x) ){
            if(nums[i] > x) x -= nums[j--], count += 1;
            else if(nums[j] > x) x -= nums[i++], count += 1;
            else if(nums[i] > nums[j]) x -= nums[i++], count += 1;
            else x -= nums[j--], count += 1;
        }
        // cout<<x<<" "<<i<<" "<<j<< " "<<count;
        if(x != 0 || count == 0 ) return -1;
        return count;
    }
int main(){
     string s;
     cin>>s;
     int k;
     cin>>k;
     vector<int>arr = getArray(s);
     cout<<minOperations(arr,k);
    return 0;
}