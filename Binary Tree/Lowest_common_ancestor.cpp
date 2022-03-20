// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
     Node* lca(Node* root ,int n1 ,int n2 )
    {  
       if(root == nullptr) return nullptr;
       
       Node * left = lca(root->left, n1, n2);
       Node* right = lca(root->right, n1, n2);
       
       if(left !=nullptr && right != nullptr) return root;
       
       if(root->data == n1 || root->data == n2) return root;
       return left!=nullptr?left: right;
    }
    // Method -1: with the help of path
    // string path(Node* root, string output, int target){
    //     if(root == nullptr){
    //         return "";
            
    //     }
    //     if(root->data == target) {
    //         output+=to_string(root->data)+" ";
    //         return output;
    //     }
    //     string res="";
    //     output+=to_string(root->data)+" ";
    //     string left = path(root->left, output, target);
    //     string right = path(root->right, output,target);
    //     if(left!="") res= left;
    //     if(right != "") res = right; 
    //     return res;
    // }
    // Node* lca(Node* root ,int n1 ,int n2 )
    // {  
    //   string left = path(root, "", n1);
    //   string right = path(root, "", n2);
    //   vector<int> arr1;
    //   vector<int>arr2;
    //   left = left.substr(0,left.size()-1);
    //   right = right.substr(0,right.size()-1);
    //   string tmp1;
    //   stringstream ss1(left);
    //   while(getline(ss1,tmp1,' ')){
    //       arr1.push_back(stoi(tmp1));
    //   }
    //   stringstream ss2(right);
    //   while(getline(ss2,tmp1,' ')){
    //       arr2.push_back(stoi(tmp1));
    //   }
   
    //   Node* res = new Node(-1);
    //   int i=0;
    //   if(left[0]!=right[0]){
    //       return res;
    //   }
    //   else{
    //       i=0;
    //       while( i<arr1.size() && i<arr2.size() && arr1[i]==arr2[i]){
    //           i++;
    //       }
    //       i=i-1;
    //       res->data =arr1[i];
           
    //   }
    //   return res;
    // }
};

// { Driver Code Starts.

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;

    return 0;
}