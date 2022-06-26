#include<bits/stdc++.h>
using namespace std;
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
    int findKthLargest(vector<int>& nums, int k) {
//          use min_heap in case of k > size/2;
        if(nums.size()/2 < k){
            priority_queue<int, vector<int>, greater<int>>pqueue;
            for(int i = 0; i < nums.size(); i++) pqueue.push(nums[i]);
             k = nums.size() - k +1;
            while(k-- > 1) pqueue.pop();
            return pqueue.top();
        }
//         max heap
        priority_queue<int>pqueue;
        for(int i = 0; i < nums.size(); i++) pqueue.push(nums[i]);
        while(k-- > 1) pqueue.pop();
        return pqueue.top();
    }
int main(){
     string s;
     int k;
     cin>>s;
     cin>>k;
     vector<int>arr = getArray(s);
     cout<<findKthLargest(arr,k);
    return 0;
}