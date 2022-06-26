#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
      this->kth = k;
       for(auto i:nums) {
           this->pq.push(i);
           if(pq.size()>k) pq.pop();
       }
    }
   
    int add(int val) {
        this->pq.push(val);
        if(pq.size() > this->kth) pq.pop();
        return pq.top();
        
    }
};


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0; i<n; i++)
      cin>>arr[i];
    int k;
    cin>>k;
    KthLargest obj(k,arr);
    cout<<obj.add(3)<<endl;
    cout<<obj.add(5)<<endl;
    cout<<obj.add(9)<<endl;
    return 0;

}