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
  cout<<"\n";
}

ListNode* remove_duplicate(ListNode* head){
    ListNode* curr= head;
    while( curr!=nullptr && curr->next!=nullptr){
        if(curr->key==curr->next->key){
            curr->next=curr->next->next;
            
        }
        if(curr->next!=nullptr && curr->key !=curr->next->key)
        curr=curr->next;
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
    // head=remove_duplicate(head);
    cout<<"After removing:";
    print_list(remove_duplicate(head));
   
    return 0;
}