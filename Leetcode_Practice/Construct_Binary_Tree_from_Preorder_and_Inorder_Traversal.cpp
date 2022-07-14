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
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    unordered_map<int,int>map;
    TreeNode* helper(vector<int>&pre, vector<int>&in, int start, int end, int &i ){
        if(start > end ) return nullptr;
        
        TreeNode* node = new TreeNode(pre[i++]);
        int pos = map[pre[i-1]];
        
       node->left = helper(pre, in, start, pos-1,i);
       node->right = helper(pre, in, pos+1, end, i);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        int index = 0;
        return helper(preorder, inorder, 0, preorder.size()-1,index);
    }
};
void print_tree(TreeNode* root){
    queue<TreeNode*>myqueue;
    myqueue.push(root);
    while(!myqueue.empty()){
        if(myqueue.front()->left) myqueue.push(myqueue.front()->left);
        if(myqueue.front()->right) myqueue.push(myqueue.front()->right);
         cout<<myqueue.front()->val<<" ";
         myqueue.pop();
    }
    cout<<"\n";
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<int>arr1 = getArray(s1);
    vector<int>arr2 = getArray(s2);
    Solution obj;
    TreeNode* root = obj.buildTree(arr1, arr2);
    print_tree(root);
    return 0;
}