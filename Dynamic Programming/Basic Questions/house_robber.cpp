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
int rob(vector<int>& nums) {
        int size = nums.size();
        if(size ==1 ) return nums[0];
        if(size>=3) nums[2]+=nums[0];
        for(int i=3; i<size; i++){
           nums[i]+=max(nums[i-2],nums[i-3]);
        }
        return max(nums[size-1],nums[size-2]);
    }
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    cout<<rob(arr);
    return 0;
}