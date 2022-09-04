#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* create_tree(vector<string>&data, int i){
    if(i >= data.size() || data[i] == "null") return NULL;
    TreeNode* node = new TreeNode(stoi(data[i]));
    node->left = create_tree(data, 2*i+1);
    node->right = create_tree(data, 2*i+2);
    return node;
}
void print_tree(TreeNode* root){
    if(!root) return ;
    cout<<root->val<<" ";
    print_tree(root->left);
    print_tree(root->right);
    return;
}
class comparator{
    public:
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    int maxv, minv;
    unordered_map<int,vector<pair<int,int>>>hash;
    vector<vector<int>>res;
    void preorder(TreeNode* root, int row , int col){
        hash[col].push_back({root->val,row});
        if(root->left)  preorder(root->left, row+1, col-1);
        else  minv = min(minv, col);
        
        if(root->right) preorder(root->right, row+1, col+1);
        else  maxv = max(maxv, col);
        
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        minv = 0;
        maxv = 0;
        preorder(root, 0, 0);
        res = vector<vector<int>>(abs(minv)+maxv+1);
        int base = abs(minv);
        int start = 0, j = 0;
        comparator cmp;
        for(auto i:hash){
            sort(i.second.begin(), i.second.end(),cmp);
            for(auto j:i.second) res[i.first+base].push_back(j.first);
        }
        return res;   
    }
};
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    vector<string>data;
    string tmp;
    while(getline(ss, tmp, ',')){
        data.push_back(tmp);
    }
    TreeNode* root = create_tree(data, 0);
    // print_tree(root);
    Solution obj;
    auto res = obj.verticalTraversal(root);
    cout<<'[';
    for(int i= 0; i < res.size(); i++){
        cout<<'[';
        for(int j = 0; j < res[i].size(); j++){
             cout<<res[i][j];
             if(j+1 < res[i].size()) cout<<',';
        }
        cout<<']';
        if(i+1 < res.size()) cout<<',';
    }
    cout<<"]";
    return 0;
}