#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(NULL),right(NULL){}
        TreeNode(int val): val(val), left(NULL), right(NULL) {}

};
class Solution {
public:
    int helper(TreeNode* root, vector<int>&hash, int node){
        if(!root) return 0;
        if(!root->left && !root->right){
            node++;
            hash[root->val]++;
            int odd_count{};
            for(int i = 1; i < 10; i++){
                if(hash[i]&1) odd_count++;
            }
            hash[root->val]--;
            if(odd_count > 1) return  0;
            return 1;
        }
        hash[root->val]++;
        int ans{};
        ans += helper(root->left, hash, node+1);
        ans += helper(root->right, hash, node+1);
        hash[root->val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>hash(10);
        return helper(root, hash, 0);
    }
};
TreeNode* createTree(vector<string>&arr, int i){
    if(i >= arr.size() || arr[i] == "null") return NULL;
    TreeNode* node = new TreeNode(stoi(arr[i]));
    node->left = createTree(arr, 2*i+1);
    node->right = createTree(arr, 2*i+2);
    return node;
}
int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<string>arr;
    while(getline(ss, tmp, ',')) arr.push_back(tmp);
    TreeNode* root = createTree(arr, 0);
    Solution obj;
    cout<<obj.pseudoPalindromicPaths(root)<<endl;
    cout<<'\n';
    return 0;
}