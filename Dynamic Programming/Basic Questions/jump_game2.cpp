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
//     greedy approach:
    int jump( vector<int>&nums){
        int curr_reach{}, steps{}, max_reach{}, size = nums.size();
        for(int i=0; i<size-1; i++){
            max_reach = max(max_reach, i+nums[i]);
            if(i == curr_reach){
                steps++;
                curr_reach = max_reach;
            }
        }
        return steps;
    }
    
    
    
//     dp approach:
    // int jump(vector<int>&nums){
    //     int size = nums.size();
    //     vector<int> dp(size+1,1e9);
    //     dp[0]=0;
    //     for(int i=0; i<size; i++){
    //         for(int j=1; j<=nums[i]; j++){
    //             if(i+j >= size) break;
    //             dp[i+j] = min(dp[i+j],dp[i]+1);
    //         }
    //     }
    //     return dp[size-1];
    // }
    
    
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.jump(arr)<<endl;
    return 0;
}