#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(): data(0), left(nullptr), right(nullptr){};
    Node(int x): data(x), left(nullptr), right(nullptr){};
};

Node* create(int s){
    Node* it = new Node(s);
    return it;
}

Node* construct_binary_tree(string s){
    stack<pair<Node*, int>>mystack;
    int size = s.size();
    pair<Node*,int> it ,tmp;
    Node* newNode = new Node(stoi(s.substr(0,1)));
    mystack.push(make_pair(newNode,0));
    int i=1;
    while ( i<size )
    {   
        if(s[i]=='(' && s[i+1] == ')'){
            mystack.top().second = 1;
        }
       else if(s[i]=='(' && s[i+1] != '('){
          i++;
          mystack.push(make_pair(create(stoi(s.substr(i,1))),0));
        }
        else if(s[i] == ')' && s[i-1] != '('){
            tmp = mystack.top();
            mystack.pop();
            it = mystack.top();
            if(it.second == 0){
                it.first->left = tmp.first;
                mystack.top().second = 1;
                }
            else
               it.first->right = tmp.first;
        }
        i++;
    }
    return mystack.top().first;
    
}

void printv(Node* root){
    if(root == nullptr)
      return ;
    printv(root->left);
    cout<<(root->data)<<" ";
    printv(root->right);
}


int main(){
    string s;
    cin>>s;
    Node* it = construct_binary_tree(s);
    printv(it);
    return 0;
}