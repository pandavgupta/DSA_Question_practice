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

void create_intersection(ListNode* head1, ListNode* head2, int k){
    int count=0;
    while(head2->next!=nullptr){
        head2= head2->next;
    }
    while(k!=count){
       head1= head1->next;
       count++;
    }
    head2->next=head1;
    return;
}
// Method-1: using difference of node count
int intersectPoint(ListNode* head1, ListNode* head2){
    int count1=0;
    int count2=0;
    int diff =0;
    ListNode* it1 = head1;
    ListNode* it2 = head2;
    while(it1!=nullptr || it2!=nullptr){
        if(it1!=nullptr){
            count1++;
            it1=it1->next;
        }
        if(it2!=nullptr){
            count2++;
            it2=it2->next;
        }
    }
    diff=count1-count2;
    it1=head1;
    it2=head2;
    if(diff<0){
        while(diff!=0){
            diff++;
            it2=it2->next;
        }
    }
    else if(diff>0){
        while(diff!=0){
            diff--;
            it1=it1->next;
        }
    }
    while(it1!=nullptr){
        if(it1==it2){
            return it1->key;
        }
        it1=it1->next;
        it2=it2->next;
    }
    return -1;
}





// int intersectPoint(ListNode* head1, ListNode* head2)
// {
//    unordered_set<ListNode*>set;
//    int n=-1;
//    while(head1!=nullptr){
//        set.insert(head1);
//        head1= head1->next;
//    }
//    while(head2!=nullptr){
//        if(set.find(head2)!=set.end()){
//            n = head2->key;
            //   break;
//        }
//        head2= head2->next;
//    }
//    return n;
// }


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
    cout<<"Element in second linked list: ";
    print_list(head2);
    cout<<"enter position in first LL for creating intersection:";
    cin>>tmp;
    create_intersection(head1,head2,tmp);
    cout<<"Element in second linked list: ";
    print_list(head2);

     n= intersectPoint(head1,head2);
    cout<<"Intersection of two Linked List is: ";
    cout<<(n);

 return 0;
}