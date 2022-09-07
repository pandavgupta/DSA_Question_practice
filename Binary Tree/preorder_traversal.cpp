#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node() : val(0), left(NULL), right(NULL){}
        Node(int val): val(val), left(NULL), right(NULL){}
};

// Method-1 : Recursion  , time complexity O(N) and space complexity O(N)
// class Solution{
//     vector<int>res;
//     public:
//         vector<int> preorderTraversal(Node *root){
//             if(root){
//                 res.push_back(root->val);
//                 preorderTraversal(root->left);
//                 preorderTraversal(root->right);
//             }
//             return res;
//         }
// };

// Method-2: using stack , time complexity O(N) and space complexity O(N)
// class Solution {
// public:
//     vector<int> preorderTraversal(Node* root) {
//         if(!root) return {};
//         vector<int>nodes;
//         stack<Node*>todo;
//         Node* it = root;
//         while(!todo.empty() || it){
//             if(it){
//                 nodes.push_back(it->val);
//                 if(it->right) todo.push(it->right);
//                 it = it->left;
//             }
//             else{
//                 it = todo.top();
//                 todo.pop();
//             }
//         }
//         return nodes;
//     }
// };

// Method-3: using morris Traversal, time complexity O(N) and space O(1)
class Solution {
public:
    vector<int> preorderTraversal(Node* root) {
        vector<int>nodes;
        Node* it = root;
        while(it){
            if(it->left){
                Node* left = it->left;
                while(left->right && left->right != it) left = left->right;
                if(left->right){
                    left->right = NULL;
                    it = it->right;
                }
                else{
                    left->right = it;
                    nodes.push_back(it->val);
                    it = it->left;
                }
            }
            else{
                nodes.push_back(it->val);
                it = it->right;
            }
        }
        return nodes;
    }
};
Node* createBT(vector<string>&node, int index){
    if(index >= node.size() || node[index] == "null") return NULL;
    Node* root = new Node(stoi(node[index]));
    root->left = createBT(node, 2*index+1);
    root->right = createBT(node, 2*index+2);  
    return root;
}



int main(){
    string s;
    cin>>s;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    string tmp;
    vector<string>node;
    while(getline(ss, tmp, ',')){
        node.push_back(tmp);
    }
    Node* root = createBT(node,0);
    Solution obj;
    vector<int>res = obj.preorderTraversal(root);
    for(int i : res) cout<<i<<" ";
    cout<<endl;
    return 0;
}