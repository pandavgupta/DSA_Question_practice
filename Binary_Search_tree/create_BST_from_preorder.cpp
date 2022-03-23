#include<bits/stdc++.h>
struct Node{
   int data;
   Node* left;
   Node* right;
   Node(int val){
       data = val;
       left = nullptr;
       right = nullptr;
   }
};
void preorder(Node* root){
    if(root==nullptr) return;
    preorder(root->left);
    std::cout<<root->data<<" ";
    preorder(root->right);
}

Node* creatBST(std::vector<int>&arr){
   int size = arr.size();
   if(size ==0) return nullptr;
   int i=0;
   Node* root = new Node(arr[i]);
   i++;
   Node* it = root;
   for(int i=1; i<size; i++){
       it  = root;
       while(true){
           if(it->data >= arr[i]){
               if(it->left ==nullptr){
                   it->left = new Node(arr[i]);
                   break;
               }
               else{
                   it = it->left;
               }
           }
           else{
               if(it->right ==nullptr){
                   it->right = new Node(arr[i]);
                   break;
               }
               else{
                   it = it->right;
               }
           }
       }
   }
  
   return root;

}
int main(){
    int n;
    std::cin>>n;
    std::vector<int>arr(n);
    for (int i = 0; i < n; i++)
      std::cin>>arr[i];
    Node* root = creatBST(arr);
    std::cout<<"preorder: ";
    preorder(root);
    
    return 0;
}