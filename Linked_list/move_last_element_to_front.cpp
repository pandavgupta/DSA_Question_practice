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

ListNode* move_last_to_front(ListNode* head) 
    {    
        ListNode* curr=head;
        ListNode* prev =new ListNode(); 
        while(curr->next!=nullptr){
            prev=curr;
            curr=curr->next;
        }
        prev->next=nullptr;
        curr->next=head;
        head=curr;
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
     head= move_last_to_front(head);
    cout<<"Element after moving: ";
    print_list(head);

 return 0;
}