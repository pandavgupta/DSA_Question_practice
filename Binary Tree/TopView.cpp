// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
// iterative approach 
    vector<int> topView(Node *root)
    {
        unordered_map<int,int>mymap;
        queue<pair<int,Node*>>myqueue1;
        pair<int,Node*> it ;
        vector<int>arr;
        myqueue1.push(make_pair(0,root));
        int m_left = 0;
        int m_right = 0;
       
            
            while(!myqueue1.empty()){
                it = myqueue1.front();
                if(it.second->left!=nullptr)  myqueue1.push(make_pair(it.first -1,it.second->left));
                if(it.second->right!=nullptr) myqueue1.push(make_pair(it.first +1,it.second->right));
                
                if(mymap.find( it.first ) == mymap.end()){
                    mymap.insert({it.first,it.second->data});
                }
                
                if(it.first < m_left){
                 m_left = it.first;
                }
                
                if(it.first > m_right){
                 m_right = it.first;
                }
                
                myqueue1.pop();
            }
           
        
        for(int j = m_left; j<=m_right; j++ )
          arr.push_back(mymap[j]);
          
        return arr;
        
    }
    
    // !!!! recursive approach not running


    // int min_offset(Node* root,int curr){
    //     if(root == nullptr) return 0;
        
    //     return min(min_offset(root->left, curr-1),min_offset(root->right, curr+1));
    // }
    // int max_offset(Node* root,int curr){
    //     if(root == nullptr) return 0;
        
    //     return max(min_offset(root->left, curr-1),min_offset(root->right, curr+1));
    // }
    //  void leftV(Node* root, int left, int depth, int &l_maxv ,unordered_map<int,pair<int,int>>& mymap ){
    //     if(root == nullptr ) return ;
        
    //     if( left < l_maxv){
    //         if(mymap.find(left) == mymap.end()){
    //             mymap.insert({left,make_pair(depth,root->data)});
    //         }
    //         else if(mymap[left].first > depth){
    //                 mymap[left].first = depth;
    //                 mymap[left].second = root->data;
    //             }
            
           
    //         l_maxv = left;
    //     }
     
    //     // if(min_offset(root->left,0) < min_offset(root->right,0) )
    //     leftV(root->left, left-1, depth+1, l_maxv,  mymap);
    //     // else
    //     leftV(root->right, left+1, depth+1, l_maxv,  mymap);
        
        
    // }
    // void rightV(Node* root, int right, int depth, int &r_maxv ,unordered_map<int,pair<int,int>>& mymap ){
    //     if(root == nullptr ) return ;
        
    //     if( right > r_maxv){
    //         if(mymap.find(right) == mymap.end()){
    //             mymap.insert({right,make_pair(depth,root->data)});
    //         }
    //         else if(mymap[right].first > depth){
    //                 mymap[right].first = depth;
    //                 mymap[right].second = root->data;
    //             }
            
           
    //         r_maxv = right;
    //     }
    //     rightV(root->right, right+1, depth+1, r_maxv,  mymap);
    //     rightV(root->left, right-1, depth+1, r_maxv,  mymap);
        
        
    // }
   

    // vector<int> topView(Node *root)
    // {
    //   unordered_map<int,pair<int,int>>mymap;
    //   vector<int>arr;
    //   int l_maxv = 0;
    //   int r_maxv = 0;
    //   mymap.insert({0,make_pair(0,root->data)});
    //   rightV(root, 0, 0, r_maxv, mymap);
    //   leftV(root, 0, 0, l_maxv, mymap);
    //   for(int i=l_maxv; i<=r_maxv; i++){
    //       arr.push_back(mymap[i].second);
    //   }
      
    //   return arr;
    // }

// void leftV(Node* root, int left, int &l_maxv, vector<int>& arr1 ){
//         if(root == nullptr ) return ;
        
        
//         if(left<0 && left < l_maxv){
//             arr1.push_back(root->data);
//             l_maxv = left;
//         }
     
//         leftV(root->left, left-1, l_maxv, arr1);
//         leftV(root->right, left+1, l_maxv, arr1);
        
//     }
//     void rightV(Node* root, int right, int &r_maxv, vector<int>&arr2 ){
//         if(root == nullptr ) return ;
        
//         if(right>0 && right > r_maxv){
//             arr2.push_back(root->data);
//             r_maxv = right; 
//         }
//         rightV(root->right, right+1, r_maxv, arr2);
//         rightV(root->left, right-1, r_maxv, arr2);
        
        
//     }
//     vector<int> topView(Node *root)
//     {
//        vector<int>arr1;
//        vector<int>arr2;
//        int l_maxv = 0;
//        int r_maxv = 0;
//        vector<int>arr;
//        leftV(root, 0, l_maxv, arr1);
//        leftV(root, 0,r_maxv, arr2);
//        for(int i=arr1.size()-1; i>=0; i--)
//           arr.push_back(arr1[i]);
          
//        arr.push_back(root->data);
//        for(int i=0; i<arr2.size(); i++)
//           arr.push_back(arr2[i]);
          
//        return arr;
//     }
};




int main() {
    
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    return 0;
}  