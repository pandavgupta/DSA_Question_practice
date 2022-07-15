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
// Method-1: using backtracking here sorting optimise the time complexity.
//  bool helper(vector<int>&matchsticks, vector<long long int>&arr, int n, long int &sum){
//         if(n == matchsticks.size() ) {
//            // next line is not needed as we are making sure that every element is included.
//           //  if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0&& arr[3] == 0) return true;
//            // return false;
// 
//           // simply we can return true;
//          return true;
//         }
//         bool ans  = false;
//         for(int i = 0; i < 4; i++){
//            if(arr[i]+matchsticks[n] <= sum ){
                // int j = i;
                // while (--j >= 0) // third
                // if (arr[i] == arr[j]) 
                //     break;
                // if (j != -1) continue;
                //     arr[i] += matchsticks[n];
                //     ans = ans || helper(matchsticks, arr, n+1,sum);
                //     if(ans) return true;
                //     arr[i] -= matchsticks[n];
                    
                // }
            
//         }
//         return ans;
//     }
//     bool makesquare(vector<int>& matchsticks) {
        
//         long int sum{};
//         for(auto i:matchsticks) sum += i;
//         if(sum%4 !=0) return false;
//         sum = sum/4;
//         vector<long long int>arr(4,sum);
//         sort(matchsticks.begin(), matchsticks.end(), greater<int>());
//         return helper(matchsticks, arr, 0, sum);
//     }

// Method-2: using backtracking , thinking in different way...
    vector<bool>check;
    bool helper(vector<int>&matchsticks, int side, int &one_side, int total_side, int index){
        if(total_side == 1) return true;
        if(side == one_side){
            return helper(matchsticks, 0, one_side, total_side-1, 0);
        }
        for(int i = index; i < matchsticks.size(); i++){
            if(!check[i] && side + matchsticks[i] <= one_side){
                check[i] = true;
                if(helper(matchsticks, side+matchsticks[i], one_side, total_side, i+1))  return true;
                check[i] = false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        check = vector<bool>(matchsticks.size());
        int sum{};
        for(auto i:matchsticks) sum += i;
        if(sum%4 != 0) return false;
        int one_side = sum/4;
        return helper(matchsticks, 0, one_side, 4, 0);
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    if(obj.makesquare(arr)) cout<<"true";
    else cout<<"false";
    return 0;
}