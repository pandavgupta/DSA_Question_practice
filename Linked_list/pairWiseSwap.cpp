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

ListNode* pairWiseSwap(ListNode* head) 
    {    ListNode* curr=head;
        ListNode* tmp=nullptr;
        ListNode* prev=new ListNode();
        if(curr!=nullptr && curr->next!=nullptr) head=head->next;
       while(curr!=nullptr && curr->next!=nullptr){
          tmp=curr->next->next;
          curr->next->next=curr;
          prev->next=curr->next;
          prev=curr;
          curr->next=tmp;
          curr=tmp;
      }
      return head;
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
    cout<<"Element after pair wise swapping: ";
    // head= reverse_list(head);
    head= pairWiseSwap(head);
    print_list(head);

 return 0;
}