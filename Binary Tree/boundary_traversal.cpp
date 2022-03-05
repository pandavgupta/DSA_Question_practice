// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









class Solution {
    
public:
    void leaf_node(Node* root, vector<int>&arr){
        if(root == nullptr)
          return ;
        if(root->left == nullptr && root->right == nullptr)
           arr.push_back(root->data);
        leaf_node(root->left,arr);
        leaf_node(root->right,arr);
    }
    void left_node(Node* root, vector<int>&arr){
        if(root->left == nullptr && root->right == nullptr )
          return ;
        arr.push_back(root->data);
        if(root->left!=nullptr)
          left_node(root->left, arr);
        else if(root->right!=nullptr)
          left_node(root->right, arr);
       
    }
    void right_node(Node* root, vector<int>&arr){
        if(root->right == nullptr && root->left == nullptr )
          return ;
        if(root->right!=nullptr)
          right_node(root->right, arr);
        else if(root->left!=nullptr)
          right_node(root->left, arr);
        arr.push_back(root->data);
       
    }
    vector <int> boundary(Node *root)
    {
        vector<int>res;
        vector<int>res2;
        if(root->left!=nullptr) left_node(root, res);
        else res.push_back(root->data);
         leaf_node(root->left, res);
         leaf_node(root->right, res);
        if(root->right!=nullptr) right_node(root, res2);
        if(!res2.empty()){
            int size = res2.size();
            for(int i=0; i<size-1; i++)
               res.push_back(res2[i]);
        }
        return res;
        
    }
};

int main() {
  
    string s ,ch;
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    vector <int> res = ob.boundary(root);
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
} 