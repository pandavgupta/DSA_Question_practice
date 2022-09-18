#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Method -1: using stack, time complexity O(N) and space O(N)
    // int trap(vector<int>& height) {
    //     stack<int>level;
    //     int result{}, tmp{}, count{}, sum{}, contain{};
    //     for(int i = 0; i < height.size(); i++){
    //        sum = 0;
    //        while(!level.empty() && height[level.top()] <= height[i]){
    //             tmp = level.top();
    //             level.pop();
    //             if(!level.empty()){
    //                 contain= min(height[level.top()] - height[tmp],height[i] - height[tmp]);
    //                 result += contain;
    //                 if(i - level.top()-2 > 0) result+=(i - level.top()-2)*contain;
    //             }
    //        } 
    //         level.push(i);
    //     }
    //     return result;
    // }

    // Method -2: using two pointer, time complexity O(N) and space complexity O(1)
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, left_max = 0, right_max = 0;
        int ans{};
        while(left < right){
            if(height[left] < height[right]){
                height[left] >= left_max ? (left_max = height[left]) :
                   ans += (left_max - height[left]);
                left++;
            }
            else{
                height[right] >= right_max ? (right_max = height[right]) :
                  ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1,s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<int>arr;
    while(getline(ss, tmp, ',')) arr.push_back(stoi(tmp));
    Solution obj;
    cout<<obj.trap(arr)<<endl;
    return 0;
}