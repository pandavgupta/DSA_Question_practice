#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL){};
    ListNode(int val) : val(val), next(NULL){};
    ListNode(int val, ListNode* next) : val(val), next(next){};
};
class Solution {
public:

    bool isPalindrome(ListNode* head) {
        if(head == NULL && head->next == NULL) return true;
        ListNode *prev = NULL, *slow = head, *fast = head, *tmp = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        if(fast) slow = slow->next;
        while(prev && slow){
            if(prev->val != slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};
ListNode* create_linked_list(vector<int>&arr){
    if(arr.size() == 0) return {};
    ListNode* head = new ListNode(arr[0]);
    ListNode* it = head;
    for(int i = 1; i < arr.size(); i++) it->next = new ListNode(arr[i]), it = it->next;
    return head;
}
int main(){
    string s;
    cin>>s;
    s = s.substr(1,s.size()-2);
    vector<int>arr;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ','))
    {
        arr.push_back(stoi(tmp));
    }
    ListNode* head = create_linked_list(arr);
    Solution obj;
    if(obj.isPalindrome(head)) cout<<"True";
    else cout<<"False";
    cout<<'\n';
    return 0;
}