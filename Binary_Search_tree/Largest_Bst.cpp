// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
struct info{
  int size;
  int min;
  int max;
  int ans;
  bool isbst;
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    info BST(Node *root){
        if(root == nullptr) return {0,1000000009,-1000000009,0,true};
        if(root->left == nullptr && root->right == nullptr) 
            return {1,root->data,root->data,1,true};
         
         info left = BST(root->left);
         info right = BST(root->right);
         
         info res;
         res.size = (1+left.size+right.size);
         
         if(left.isbst && right.isbst && left.max < root->data && right.min > root->data){
             res.ans = res.size;
             res.min = min(left.min,min(right.min,root->data));
             res.max = max(right.max,max(left.max,root->data));
             res.isbst = true;
             return res;
         }
        //  else {
             res.ans = max(left.ans, right.ans);
             res.isbst = false;
        //  }
         
         return res;
    }
    int largestBst(Node *root, int minv=-1e9, int maxv=1e9)
    {
        info data =  BST(root);
    	return data.ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
   
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    
    return 0;
}
  // } Driver Code Ends