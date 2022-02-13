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
//#### Method-1
ListNode* reverseList(ListNode* head){
        ListNode* it=head;
        ListNode* prev=nullptr;
         ListNode* tmp=nullptr;
        while(it!=nullptr){
            tmp=it->next;
            it->next=prev;
            prev=it;
            it=tmp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1= reverseList(l1);
        l2=reverseList(l2);
        ListNode* head=new ListNode();
        ListNode* it=head;
        int carry=0;
        int sum=0;
        while(l1!=nullptr || l2!=nullptr){
            sum=0;
           if(l1!=nullptr){
               sum+=l1->key;
               l1=l1->next;
           }
            if(l2!=nullptr){
                sum+=l2->key;
                l2=l2->next;
            }
            
            it->key=sum+carry;
            carry = (it->key)/10;
            it->key=(it->key)%10;
            if(carry || l1!=nullptr || l2!=nullptr){
                ListNode* newNode= new ListNode(0);
                it->next=newNode;
                it= it->next;
            }
            
            
        }
        if(carry){
            it->key=carry;
        }
        head=reverseList(head);
        return head;
        
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
     head= addTwoNumbers(head1,head2);
    cout<<"Element after adding : ";
    print_list(head);

 return 0;
}