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
    bool isValid(vector<int>&nums, int m, int maxv){
        int count = 1, sum{};
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxv){
                sum = nums[i];
                count++;
            }
            if(count > m) return false;
        }
        return true;
    }
    int findPages(vector<int>& nums, int m) {
        if(nums.size() < m) return -1;
        int upper_limit{}, lower_limit = nums[0], mid{}, res = -1;
        for(int i = 0; i < nums.size(); i++){
            lower_limit = max(lower_limit, nums[i]);
            upper_limit += nums[i];
        }
        while(lower_limit <= upper_limit){
            mid = lower_limit + (upper_limit-lower_limit)/2;
            if(isValid(nums, m, mid)){
                res = mid;
                upper_limit = mid-1;
            }
            else lower_limit = mid+1;
        }
        return res;
    }
};
int main() {
        string s;
        int m;
        cin>>s>>m;
        vector<int>A = getArray(s);
        Solution ob;
        cout << ob.findPages(A, m) << endl;
    return 0;
}