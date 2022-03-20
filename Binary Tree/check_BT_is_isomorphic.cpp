// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        queue<Node*>q1,q2,q3,q4;
        q1.push(root1);
        q3.push(root2);
        string s1,s2;
        while(!q1.empty()){
            s1="",s2="";
            while(!q1.empty()){
                
                s1+=to_string(q1.front()->data);
                if(q1.front()->left!=nullptr){
                    q2.push(q1.front()->left);
                }
                if(q1.front()->right!=nullptr){
                    q2.push(q1.front()->right);
                }
                q1.pop();
            }
            while(!q3.empty()){
                
                s2+=to_string(q3.front()->data);
                if(q3.front()->left!=nullptr){
                    q4.push(q3.front()->left);
                }
                if(q3.front()->right!=nullptr){
                    q4.push(q3.front()->right);
                }
                q3.pop();
            }
            if(s1 !=s2){
                
                rotate(s2.begin(),s2.begin()+1, s2.end());
                if(s1!=s2)return false;
            }
            if(q2.empty())break;
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            while(!q4.empty()){
                q3.push(q4.front());
                q4.pop();
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    
        string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		Node* root1 = buildTree(s1);
		Node* root2 = buildTree(s2);
		Solution obj;
		if(obj.isIsomorphic(root1,root2))
		    cout<<"Yes"<<endl;
		else
		    cout<<"No"<<endl;
    
    return 0;
}