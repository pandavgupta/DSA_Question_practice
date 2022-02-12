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
//#### Method-1: Add 1 to a number represented as linked list using recursive method
ListNode* adding_carry(ListNode *curr) 
    {
        if(curr->next==nullptr){
            curr->key=curr->key+1;
            return curr;
        }
        
        ListNode* Next=adding_carry(curr->next);
        if(Next->key/10){
            Next->key=0;
             curr->key=curr->key+1;
        }
        return curr;
    }

ListNode* addOne(ListNode* head){
    head= adding_carry(head);
    if(head->key/10){
        ListNode* newNode = new ListNode(1);
        head->key=0;
        newNode->next=head;
        head=newNode;
    }
    return head;
}


// <----------------------------------------------------->
//##### Method-2 : Reversing the element then adding 1
// ListNode* reverse(ListNode* head){
//     ListNode* prev=nullptr;
//     ListNode* tmp=nullptr;
//     while(head!=nullptr){
//       tmp=head->next;
//       head->next=prev;
//       prev=head;
//       head=tmp;
//     }
//     return prev;
// }

// ListNode* addOne(ListNode *head){
     
//      head = reverse(head);
//      ListNode* it=head;
//      int carry=1;
//      while(it!=nullptr){
//          it->key=(it->key+carry)%10;
//          carry=(it->key)>0?0:1;
//          if(carry){
//              if(it->next==nullptr){
//                  ListNode* newNode=new ListNode(0);
//                  it->next=newNode;
//              }
//              it = it->next;
//          }
//          else
//          break;
//      }
//      head=reverse(head);
//      return head;
     
// }

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