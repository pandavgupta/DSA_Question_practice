#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   bool isSafe(vector<int> path, int row, int col){
       for(int i = 0; i < path.size(); i++){
           if(path[i] == col || (path[i] - row + i) == col || (path[i] + row - i) == col ) return false;
       }
       return true;
   }
    void helper(vector<vector<int>>&res, vector<int>path, int n, int row){
        if( row == n){
              res.push_back(path);
            return ;
        }
        for(int i = 0; i < n; i++){
            vector<int>tmp = path;
            if(isSafe(path, row, i )){
                tmp.push_back(i);
                helper(res, tmp, n, row+1);
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>res;
        helper(res, vector<int>(), n, 0);
        return res;
    }
};

int main(){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    return 0;
} 