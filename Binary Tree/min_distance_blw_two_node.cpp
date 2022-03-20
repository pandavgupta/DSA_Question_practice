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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int solve(Node* root, int target, int count){
        if(root == nullptr) return 0;
        
        if(root->data == target) return count;
        int left = solve(root->left, target, count+1);
        int right = solve(root->right, target, count+1);
        
        return  left==0?right:left;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {  
       if(root == nullptr) return nullptr;
       
       Node * left = lca(root->left, n1, n2);
       Node* right = lca(root->right, n1, n2);
       
       if(left !=nullptr && right != nullptr) return root;
       
       if(root->data == n1 || root->data == n2) return root;
       return left!=nullptr?left: right;
    }
    int findDist(Node* root, int a, int b) {
        Node* node = lca(root, a, b);
        if(node == nullptr) return -1;
        int sum{};
        
        return solve(node,a,0)+solve(node,b,0);
        
    }
    // Method -:2 using path
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
    // int findDist(Node* root, int a, int b) {
    //     string left = path(root, "", a);
    //   string right = path(root, "", b);
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
    //   int i{},sum{};
    //       while( i<arr1.size() && i<arr2.size() && arr1[i]==arr2[i]){
    //           i++;
    //       }
    //       i=i-1;
    //     for(int j=i; j<arr1.size() && arr1[j]!=a ; j++){
    //         sum++;
    //     }
    //     for(int j=i; j<arr2.size() && arr2[j]!=b ; j++)
    //         {
    //             sum++;
    //         }
    //     if(sum==0) return -1;
    //     return sum;
    // }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        cout<<endl;
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    
    return 0;
}
  // } Driver Code Ends