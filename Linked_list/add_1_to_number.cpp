#include<bits/stdc++.h>
using namespace std;
class ListNode {
    public: 
      int key;
      ListNode* next;
      //initializer;
      ListNode(): key(0),next(nullptr){};
      ListNode(int key): key(key), next(nullptr){};
      ListNode(int key, ListNode* next): key(key), next(next){};
};

void push_front(ListNode** headptr, int key){
    ListNode* newNode = new ListNode(key);
    newNode->next=(*headptr);
    *headptr = newNode;
}

void print_list(ListNode* headptr){
  while (headptr!=nullptr)
  {
     cout<<(headptr->key)<<" ";
     headptr= headptr->next;
  }
  
}
//Add 1 to a number represented as linked list
ListNode* addOne(ListNode *curr) 
    {
        if(curr->next==nullptr){
            curr->key=curr->key+1;
            return curr;
        }
        
        ListNode* Next=addOne(curr->next);
        if(Next->key >9){
            Next->key=0;
             curr->key=curr->key+1;
        }
        return curr;
    }



int main(){
    ListNode* head = new ListNode();
    head =nullptr;
    int n,tmp;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        push_front(&head,tmp);
    }
    cout<<"Element in linked list: ";
    print_list(head);
    cout<<"\n";
     head= addOne(head);
    cout<<"Element after adding 1: ";
    print_list(head);

 return 0;
}