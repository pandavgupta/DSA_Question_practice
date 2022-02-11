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

int first_loop_node(ListNode* head){
   ListNode* fast= head;
    ListNode* slow= head;
    while ( fast!=nullptr && fast->next!=nullptr)
    {   
        fast=fast->next->next;
        slow= slow->next;
        if(slow==fast) {
            slow= head;
            if(fast==head){
                    return fast->key;
                }
                else
                {
                    while ( slow->next!= fast->next)
                    { slow= slow->next;
                      fast= fast->next;
                    }
                    
                    return fast->next->key;
                }
        }
    }
    
    return 0;

}

void create_loop(ListNode* head, int index_first){
    ListNode* it = head;
    ListNode* prev=nullptr;
    int count=0;
    while (it->next!=nullptr)
    {
        if(index_first==count){
          prev = it;
        }
        it=it->next;
        count++;
    }
    it->next=prev;
    return ;
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
    //creating loop
    cout<<"enter index to connect to last index: ";
    cin>>n;
    create_loop(head,n);
    cout<<"First starting loop element is :"<<first_loop_node(head);
    return 0;
}