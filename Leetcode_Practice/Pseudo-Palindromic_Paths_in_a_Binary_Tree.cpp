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
// Method-1
// class Solution {
// public:
//     int ans;
//     void helper(TreeNode* root, vector<int>&hash){
//         if(!root) return ;
//         if(!root->left && !root->right){
//             hash[root->val]++;
//             int odd_count{};
//             for(int i = 1; i < 10; i++){
//                 if(hash[i]&1) odd_count++;
//             }
//             hash[root->val]--;
//             if(odd_count > 1) return  ;
//             ans++;
//             return ;
//         }
//         hash[root->val]++;
//         helper(root->left, hash);
//         helper(root->right, hash);
//         hash[root->val]--;
//         return ;
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int>hash(10);
//         ans = 0;
//         helper(root, hash);
//         return ans;
//     }
// };
// Method-2
class Solution {
public:
    int ans;
    void helper(TreeNode* root,int path){
        if(!root) return ;
        path = path^(1<<root->val);
        if(!root->left && !root->right){
            if((path & (path-1)) == 0) ans++;
            return ;
        }
        helper(root->left, path);
        helper(root->right, path);
        return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        int path = 0;
        helper(root, path);
        return ans;
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
    return 0;
}