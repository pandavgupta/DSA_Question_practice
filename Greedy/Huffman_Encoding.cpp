// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
   
   
   
class Node{
  public:
    int freq;
    char ch;
    Node* left;
    Node* right;
    Node(int val): freq(val), ch('0') ,left(nullptr), right(nullptr){};
};
struct comp
{
    bool operator()(const Node* l, const Node* r) const
    {
        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

class Solution
{
	public:
	Node* getNode(int freq, char ch, Node* left=nullptr, Node* right=nullptr){
	    Node* node = new Node(freq);
	    node->ch = ch;
	    node->left = left;
	    node->right = right;
	    return node;
	}
// my heapify method is not working  in this case , we are only getting answer through stl priority heap.
// 	void heapify(vector<Node*>&arr, int n, int i){
// 	    int parent = i;
// 	    int leftchild = 2*i+1;
// 	    int rightchild = 2*i+2;
// 	    if(leftchild < n && arr[parent]->freq > arr[leftchild]->freq) parent = leftchild;
// 	    if(rightchild < n && arr[parent]->freq > arr[rightchild]->freq) parent = rightchild;
// 	    if(parent!=i){
// 	        swap(arr[parent], arr[i]);
// 	        heapify(arr, n, parent);
// 	    }
// 	    return ;
// 	}
// 	Node* extract(vector<Node*>&arr, int& N){
// 	    Node* newNode = new Node(1e9);
	    
// 	    Node* top =arr[0];
// 	    arr[0] = arr[N-1];
// 	    arr[N-1] = newNode;
// 	    heapify(arr,N,0);
// 	    N--;
// 	    return top;
// 	}
// 	void build_heap(vector<Node*>&arr, int n){
// 	    int i = n/2 -1;
// 	    for(i ; i>0; i--)
// 	       heapify(arr, n, i);
// 	   return;
// 	}
 
	void traverse(Node* root, vector<string>&res, string output){
	    if(root == nullptr) return;
	    if(root->left == nullptr & root->right == nullptr) res.push_back(output);
	    string output2 = output;
	    output +="0";
	    output2 +="1";
	    traverse(root->left, res, output);
	    traverse(root->right, res, output2);
	}
	
// 	static bool comp(const Node* a, Node* b){
// 	    return a->freq < b->freq;
// 	}
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
		    vector<Node*>arr;
		   for(int i=0; i<N; i++){
		       arr.push_back(getNode(f[i],S[i]));
		   }
		  // build_heap(arr, N);
		  priority_queue<Node*, vector<Node*>, comp> pq;
		  for(auto i:arr)
		    pq.push(i);
		  
		   Node* left = nullptr;
		   Node* right = nullptr;
		   Node* sum = nullptr;
		   while(pq.size()>1){
		       left = pq.top();
		       pq.pop();
		       right = pq.top();
		       pq.pop();
		       pq.push(getNode(left->freq+right->freq, '0', left, right));
		       
		}
		Node* root = pq.top();
		vector<string>res;
	    traverse(root,res, "");
	    return res;
	}
};

// { Driver Code Starts.
int main(){
    
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
	return 0;
}  // } Driver Code Ends