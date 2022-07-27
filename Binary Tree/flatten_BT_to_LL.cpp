// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	Node* root = newNode(stoi(ip[0]));

	queue<Node*> queue;
	queue.push(root);

	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		Node* currNode = queue.front();
		queue.pop();

		string currVal = ip[i];

		if (currVal != "N") {

			currNode->left = newNode(stoi(currVal));

			queue.push(currNode->left);
		}

		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		if (currVal != "N") {

			currNode->right = newNode(stoi(currVal));

			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

void inorder(struct Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

class Solution
{
    public:
// Method-1: Recursive solution ,time O(N) and space O(N) for stack creation
	// void helper(Node* root, Node* &prev){
    //     if(root == nullptr) return;
    //     helper(root->right, prev);
    //     helper(root->left, prev);
    //     root->right = prev;
    //     root->left = nullptr;
    //     prev = root;
    // }
    // void flatten(Node* root) {
    //     Node* prev = nullptr;
    //     helper(root, prev);
    // }

// Mehtod-2: Iterative solution time O(N) and space O(1);
    void flatten(Node *root){
        if(root == nullptr) return;
        stack<Node*> mystack;
        mystack.push(root);
        Node* node = nullptr;
        while(!mystack.empty()){
            node = mystack.top();
            mystack.pop();
            if(node->right) mystack.push(node->right);
            if(node->left) mystack.push(node->left);
            node->left = nullptr;
            if(!mystack.empty())node->right = mystack.top();
        }
        return ;
    }
    
};

int main() {


		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";

	return 0;
}