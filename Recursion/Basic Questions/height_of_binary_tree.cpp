#include <bits/stdc++.h>
using namespace std;

 //creating tree only for sample
            
            struct Node {
                int key;
                Node* left;
                Node* right;
            };
            
            struct Node* newNode(int value)
            {
                Node* n = new Node;
                n->key = value;
                n->left = NULL;
                n->right = NULL;
                return n;
            }
            
            struct Node* insertValue(struct Node* root, int value,
                                    queue<Node *>& q)
            {
                Node* node = newNode(value);
                if (root == NULL)
                    root = node;
            
                // The left child of the current Node is
                // used if it is available.
                else if (q.front()->left == NULL)
                    q.front()->left = node;
            
                else {
                    q.front()->right = node;
                    q.pop();
                }
            
                q.push(node);
                return root;
            }
            
            Node* createTree(int arr[], int n)
            {
                Node* root = NULL;
                queue<Node*> q;
                for (int i = 0; i < n; i++)
                root = insertValue(root, arr[i], q);
                return root;
            }
            void levelOrder(struct Node* root)
            {
                if (root == NULL)
                    return;
                queue<Node*> n;
                n.push(root);
                while (!n.empty()) {
                    cout << n.front()->key << " ";
                    if (n.front()->left != NULL)
                        n.push(n.front()->left);
                    if (n.front()->right != NULL)
                        n.push(n.front()->right);
                    n.pop();
                }
            }
            //code for creating tree

//finding height of tree using recursion

int height_of_tree(struct Node* root){
  if(root==NULL)
     return 0;
  return 1+max(height_of_tree(root->left),height_of_tree(root->right));

}
int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60,80,90,100,12,23,34,22,2,89,99,211 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, n);
    levelOrder(root);
    cout<<"Height of tree: "<<height_of_tree(root);
    return 0;
}
