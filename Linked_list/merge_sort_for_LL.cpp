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
  cout<<"\n";
  
}

ListNode* midPoint(ListNode* head){
    ListNode* slow=head;
    ListNode* fast = head;
    if(head->next==nullptr ) return nullptr;
    if( head->next->next==nullptr ) {
        slow = head->next;
        head->next= nullptr;
        return slow;
    }
    while (fast!=nullptr  && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast=slow;
    slow=slow->next;
    fast->next = nullptr;
    return slow;
}

//with extra spaces 
// ListNode* merge(ListNode* head,ListNode* midNode){
//     if(head==nullptr) return midNode;
//     if(midNode==nullptr) return head;

//      ListNode* headref=new ListNode(0);
//     if(head->key < midNode->key){
//         headref->key=head->key;
//         head = head->next;
//     }
//     else{
//         headref->key=midNode->key;
//         midNode = midNode->next;
//     }
//     ListNode* node =headref;
//     while(head!=nullptr && midNode!=nullptr){
//         if(head->key < midNode->key){
//         ListNode* newNode = new ListNode(0);
//         node->next= newNode;
//         node = node->next;
//         node->key=head->key;
//         head = head->next;
//         }
//         else{
//         ListNode* newNode = new ListNode(0);
//         node->next= newNode;
//         node = node->next;
//         node->key=midNode->key;
//         midNode = midNode->next;
//         }

//     }
//     while (head!=nullptr)
//     {
//        ListNode* newNode = new ListNode(0);
//         node->next= newNode;
//         node = node->next;
//         node->key=head->key;
//         head = head->next;
//     }
//     while (midNode!=nullptr)
//     {
//        ListNode* newNode = new ListNode(0);
//         node->next= newNode;
//         node = node->next;
//         node->key=midNode->key;
//         midNode = midNode->next;
//     }
    
//    return headref;
// }


// with less extra spaces
ListNode* merge(ListNode* head,ListNode* midNode){
    if(head==nullptr) return midNode;
    if(midNode==nullptr) return head;

     ListNode* headref=nullptr;
    if(head->key < midNode->key){
        headref=head;
        head=head->next;
        headref->next=nullptr;
    }
    else{
        headref=midNode;
        midNode = midNode->next;
        headref->next=nullptr;
    }
    ListNode* node =headref;
    while(head!=nullptr && midNode!=nullptr){
        if(head->key < midNode->key){
        node->next= head;
        head = head->next;
        node->next->next=nullptr;
        node=node->next;
        }
        else{
         node->next= midNode;
        midNode = midNode->next;
        node->next->next=nullptr;
        node=node->next;
        }

    }
    while (head!=nullptr)
    {
       node->next= head;
        head = head->next;
        node->next->next=nullptr;
        node=node->next;
    }
    while (midNode!=nullptr)
    {
       node->next= midNode;
        midNode = midNode->next;
        node->next->next=nullptr;
        node=node->next;
    }
    
   return headref;
}

ListNode* merge_sort(ListNode* head){
    if( head != nullptr && head->next!=nullptr){
        ListNode* midNode=midPoint(head);
        head = merge_sort(head);
        midNode =  merge_sort(midNode);
        
        head =merge(head,midNode);
        
    }
  return head;
}


int main(){
    ListNode* head = new ListNode();
    head=nullptr;
    
    int n,tmp;
    cout<<"enter size of first list:";
    cin>>n;
    cout<<"enter element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        push_front(&head,tmp);
    }
    cout<<"Element in first linked list: ";
    print_list(head);
    head =merge_sort(head);
    cout<<"After sorting : ";
    print_list(head);

 return 0;
}