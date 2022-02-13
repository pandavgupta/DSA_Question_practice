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

ListNode*  findIntersection(ListNode*  head1, ListNode*  head2)
{
    ListNode*  curr = new ListNode(0);
    ListNode*  head3 = nullptr;
    int flag=1;

    while(head1!=nullptr && head2!=nullptr){
        if(head1->key == head2->key){
            ListNode* newNode = new ListNode(0);
            newNode->key = head1->key;
            curr->next= newNode;
            curr = curr->next;
            if(flag){
                head3=curr;
                flag=0;
            }
             head1= head1->next;
             head2=head2->next;
        }
        else if(head1->key < head2->key){
            head1= head1->next;
        }
        else{
            head2=head2->next;
        }
    }
    return head3;
    
}
int main(){
    ListNode* head = new ListNode();
    head=nullptr;
    ListNode* head1 = new ListNode();
    head1 =nullptr;
    ListNode* head2 = new ListNode();
    head2 =nullptr;
    int n,tmp;
    cout<<"enter size of first list:";
    cin>>n;
    cout<<"enter element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        push_front(&head1,tmp);
    }
    cout<<"enter size of second list:";
    cin>>n;
    cout<<"enter element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        push_front(&head2,tmp);
    }
    cout<<"Element in first linked list: ";
    print_list(head1);
    cout<<"\n";
    cout<<"Element in second linked list: ";
    print_list(head2);
    cout<<"\n";
     head= findIntersection(head1,head2);
    cout<<"Intersection of two Linked List is: ";
    print_list(head);

 return 0;
}