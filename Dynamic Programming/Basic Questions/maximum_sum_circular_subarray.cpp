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
/*
Here there are two case:
  case 1: max subarray in middle of array
         for this case we have kadane algorithm for max subarray sum.

  case 2: max subarray in circular subarray
         for this case we have method using kadane algo
               total sum of array - min subarray sum 

*/
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxv_straight=-1e9, minv_straight= 1e9;
        int sum_maxv{}, sum_minv{}, total{};
        for(int i=0; i<nums.size(); i++){
            // total array sum
            total+=nums[i];
            
            // max subarray sum
            sum_maxv+=nums[i];
            if(sum_maxv > maxv_straight) maxv_straight = sum_maxv;
            if(sum_maxv < 0) sum_maxv =0;
            
            // min subarray sum 
            sum_minv+=nums[i];
            if(sum_minv < minv_straight) minv_straight = sum_minv;
            if(sum_minv > 0) sum_minv = 0;
        }
        if(total == minv_straight) return maxv_straight;
        return max( maxv_straight ,(total- minv_straight));
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.maxSubarraySumCircular(arr)<<endl;
    return 0;
}