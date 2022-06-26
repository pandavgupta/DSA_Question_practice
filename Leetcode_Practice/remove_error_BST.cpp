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
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
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

        // Get the current node's dataue from the string
        string currdata = ip[i];

        // If the left child is not null
        if (currdata != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currdata));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currdata = ip[i];

        // If the right child is not null
        if (currdata != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currdata));

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

    Node(int data) {
        data = data;
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

class Solution {
public:
    void recover(Node* root,Node*&minv,Node* maxv) {
        if(root == nullptr) return ;
        if(root->data > maxv->data){
            swap(root->data, maxv->data);
            return ;
        }
        if(root->data < minv->data){
            swap(root->data, minv->data);
            return ;
        }
        
        if(maxv->data == 1000000009)maxv = root;
           recover(root->left , minv, maxv->data < root->data?root:maxv);
        if(minv->data == -1000000009) minv = root;
         maxv = newNode(100000009);
          recover(root->right,minv->data > root->data?root:minv, maxv);
        
    }
    void recoverTree(Node* root){
        Node* minv=  newNode(-1000000009);
        Node* maxv =  newNode(1000000009);
        recover(root, minv, maxv);
    }
 //   void  recoverTree(Node* root) {
//         stack<Node*>mystack;
//         vector<Node*>res;
//         Node* it = root;
//         while(!mystack.empty() || it!=nullptr){
//             if(it!=nullptr){
//                 mystack.push(it);
//                 it = it->left;
//             }
//             else {
//                 it = mystack.top();
//                 res.push_back(it);
//                 mystack.pop();
//                 it = it->right;
//             }
//         }
        
//         int size = res.size(), j=1;
//         for(j=1; j<size; j++){
//             if(res[j-1]->data > res[j]->data ) break;
//         }
//         int i=j-1;
//         Node* node = res[j];
//         while(j+1<size && res[i]->data > res[j+1]->data){
//             node = node->data > res[j+1]->data?res[j+1]:node;
//             j++;
//         }
//         swap(res[i]->data, res[j]->data);

//     }
};

void print(Node* root){
    if(root == nullptr) return ;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main() {

   
   
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        ob.recoverTree(root);
        print(root);
        cout<<endl;
    
    return 0;
}
  // } Driver Code Ends