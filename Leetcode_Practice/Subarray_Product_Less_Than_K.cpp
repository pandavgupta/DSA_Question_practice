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
    int ans;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int prod = 1, count{}, start = 0;
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            while(prod >= k && start <= i){
                prod /= nums[start++];
            }
            if(i-start+1 > 0) count += (i-start+1);
        }
        return count;
    }
};
int main(){
    int n;
    string s;
    cin>>s>>n;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.numSubarrayProductLessThanK(arr,n)<<endl;
    return 0;
}