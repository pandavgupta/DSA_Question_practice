#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 void create_bst(Node* root, int key, int &suc){
	    if(root == nullptr) return ;
	    if(root->data >key){
			suc = root->data;
	    	if(root->left == nullptr){
	    		root->left = new Node(key);
				return ;
	    	}
	       create_bst(root->left, key, suc);
	    }
	    else{
	    	if(root->right == nullptr){
	    		root->right = new Node(key);
	    		// suc =-1;
				return;
	    	}
	        create_bst(root->right, key, suc);
	    }
	    return ;
	}

	void replace(vector<int> &nums)
	{
		int size = nums.size();
		// if(size == 0) return {};
	    Node* root = new Node(nums[nums.size()-1]);
	    int suc;
		nums[size-1] =-1;
	    for(int i=size-2; i>=0; i--){
	    	suc =-1;
	        create_bst(root, nums[i],suc);
	        nums[i] = suc;
		}
	}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
     cin>>arr[i];
     replace(arr);
     for(auto i:arr){
         cout<<i<<" ";
     }
     cout<<endl;
    return 0;
}