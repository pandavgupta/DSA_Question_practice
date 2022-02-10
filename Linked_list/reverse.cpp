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

ListNode* reverse_list(ListNode* head){
  ListNode* prev=nullptr;
  ListNode* tmp=nullptr;
  while (head!=nullptr)
  {   tmp=prev;
      prev =head;
      head=head->next;
      prev->next= tmp;  
  }
  return prev;
  
}

ListNode* recursive_reverse_link(ListNode* prev,ListNode* curr){
    if(curr==nullptr){
        return prev;
    }
    ListNode* tmp=prev;
        prev= curr;
    curr=curr->next;
       prev->next= tmp; 

   return recursive_reverse_link(prev, curr);

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
    cout<<"Element after reversing: ";
    // head= reverse_list(head);
    head= recursive_reverse_link(nullptr,head);
    print_list(head);

 return 0;
}