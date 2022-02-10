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

ListNode* reverse_list(ListNode* head, int k){
  ListNode* prev=nullptr;
  ListNode* tmp=nullptr;
  ListNode* curr= head;
  ListNode* start=head;
  ListNode* startp=new ListNode();
  int count=0;
  int flag=0;
  while (curr!=nullptr)
  {  
       tmp=prev;
      prev =curr;
      curr=curr->next;
      prev->next= tmp;  
      count++;
      flag++;
      if(flag==k)
       head = prev;
       
      if(count==k){
          count=0;
          startp->next=prev;
          start->next=curr;
          startp=start;
          start=curr;
          prev=nullptr;
          
      }
     
  }
  if(count){
          startp->next=prev;
          start->next=curr;
  }

  return head;
  
}

int main(){
    ListNode* head = new ListNode();
    head =nullptr;
    int n,tmp,k;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        push_front(&head,tmp);
    }
    cin>>k;
    cout<<"Element in linked list: ";
    print_list(head);
    cout<<"\n";
    cout<<"Element after reversing: ";
    head= reverse_list(head,k);
   
    print_list(head);

 return 0;
}