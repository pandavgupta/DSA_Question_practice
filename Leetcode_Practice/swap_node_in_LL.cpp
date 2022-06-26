#include<bits/stdc++.h>
using namespace std;
class ListNode{
  public:
     int val;
     ListNode* next;
     ListNode(int val): val(val),next(nullptr){};
};
//     function to swap value of node
ListNode* swapNodes(ListNode* head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    ListNode* it = head;
    int count{0};
    while(it!=nullptr){
        count++;
        if(count==k) first = it;
        it = it->next;
    }
    int n = count-k+1;
    count=1;
    while(count < n){
        count++;
        second = second->next;
    }
    swap(first->val, second->val);
    return head;
}
// function to swap node in LL
// ListNode* swapNodes(ListNode* head, int k) {
//         if(k==0) return head;
//         int count{}, n{};
//         ListNode* first = nullptr;
//         ListNode* prev = new ListNode(0);
//         prev->next = head;
//         ListNode* second= nullptr;
//         while(head!=nullptr){
//             count++;
//             head = head->next;
//         }
//         head = prev;
//         n = count;
//         count=0;
//         while(head!=nullptr){
//             count++;
//             if(count == k) first = head;
//             if( count == (n+1-k)) second = head;
//             head = head->next;
//             if(first !=nullptr && second!=nullptr) break;
//         }
//         ListNode* tmp = first->next;
//         first->next = second->next;
//         second->next = tmp;
//         first = first->next;
//         second = second->next;
//         tmp = first->next;
//         first->next = second->next;
//         second->next = tmp;
        
//         return prev->next;
//     }
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
ListNode* getLL(vector<int>&arr){
    int size = arr.size();
    if(size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* it = head;
    for(int i=1; i<size; i++){
        it->next = new ListNode(arr[i]);
        it = it->next;
    }
    return head;
}
void printLL(ListNode* head){
    while( head!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
     string s;
     cin>>s;
     int k;
     cin>>k;
     vector<int>arr = getArray(s);
     ListNode* head = getLL(arr);
     head = swapNodes(head,k);
     printLL(head);
    return 0;
}