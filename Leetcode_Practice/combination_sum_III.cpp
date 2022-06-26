#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k> n || (k>1 && k==n)) return {};
        vector<int>sum;
        solve(k,n,sum,1, n);
        return result;
    }
    void solve(int k, int n, vector<int>sum, int num, int total){
        if(n<1 || sum.size()==k || num > total){
           if(sum.size()==k && n==0 ) result.push_back(sum);
            return ;
        }
        for(int i = num; i<=9; i++){
            if(n-i<0 ) break;
            vector<int>tmp = sum;
            tmp.push_back(i);
            if(n-i==0) solve(k, n-i, tmp,i+1, total);
            else{
            solve(k, n-i, tmp,i+1, total);
            solve(k,n,sum, i+1,total);

            }
        }
        
    }
};
int main(){
    int k, n;
    cin>>k>>n;
    Solution obj;
    auto res = obj.combinationSum3(k,n);
    for(auto i:res){
        for(auto j:i)
        cout<<j<<",";
        cout<<",";
    }
    return 0;
}