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
// ListNode* reverseList(ListNode* head){
//         ListNode* it=head;
//         ListNode* prev=nullptr;
//          ListNode* tmp=nullptr;
//         while(it!=nullptr){
//             tmp=it->next;
//             it->next=prev;
//             prev=it;
//             it=tmp;
//         }
//         return prev;
//     }

   ListNode* reverse(ListNode* head){
        if( head == nullptr ) return head;
        ListNode* prev= nullptr;
        ListNode*  tmp=nullptr;
        while(head!=nullptr ){
            tmp = head -> next;
            head -> next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode *head)
    {
      ListNode* slow=head;
      ListNode* fast = head->next;
      while ( fast != nullptr && fast -> next != nullptr){
          slow = slow->next;
          fast = fast->next -> next;
      }
      ListNode* head2 = slow -> next;
      slow -> next = nullptr;
      head2 = reverse(head2);
      while( head != nullptr && head2 != nullptr ){
          if( head -> key != head2 -> key)
               return false;
          head = head -> next;
          head2 = head2 -> next;
      }
      return true;
    }
int main() {
    ListNode* head = nullptr;
    int n{}; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) { cin >> nums[i];}
    for (int i = n - 1; i >= 0; --i) {  push_front(&head, nums[i]); }

    cout << isPalindrome(head) << "\n";
    // checkPallidrome(head);

    return 0;
}