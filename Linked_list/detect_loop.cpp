#include<iostream>
using namespace std;
class ListNode{
    public:
      int key;
      ListNode* next;
      ListNode(): key(0),next(nullptr){};
      ListNode(int key): key(key),next(nullptr){};
      ListNode(int key, ListNode* next): key(key),next(next){};
};

void push_front(ListNode** head, int key){
    ListNode* newNode= new ListNode(key);
    newNode->next= *head;
    *head= newNode;
}
void print_list(ListNode* headptr){
  while (headptr!=nullptr)
  {
     cout<<(headptr->key)<<" ";
     headptr= headptr->next;
  }
  
}

bool detect_loop(ListNode* head){
    ListNode* fast= head;
    ListNode* slow= head;
    while ( fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow= slow->next;
        if(slow==fast) return true;
    }
    
    return false;
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
    cout<<"LOOP is present or not: ";
    cout<<detect_loop(head);

    return 0;
}