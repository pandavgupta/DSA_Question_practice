
#include <bits/stdc++.h>
using namespace std;

class Solution
{ 
    vector<int>minHeap;
    vector<int>maxHeap;
    public:
    void maxHeapify(int i){
        int largest = i ;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;
        if( leftchild < maxHeap.size() && maxHeap[largest] < maxHeap[leftchild]  ) 
            largest = leftchild;
        if( rightchild < minHeap.size() && maxHeap[largest] < maxHeap[rightchild] )
            largest = rightchild;
        if( largest != i ){
            swap( maxHeap[largest], maxHeap[i] );
            maxHeapify( largest);
        }
        
        return;
    }
    void minHeapify(int i){
        int largest = i ;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;
        if( leftchild < maxHeap.size() && minHeap[largest] > minHeap[leftchild]  ) 
            largest = leftchild;
        if( rightchild < minHeap.size() && minHeap[largest] > minHeap[rightchild] )
            largest = rightchild;
        if( largest != i ){
            swap( minHeap[largest], minHeap[i] );
            minHeapify( largest);
        }
        
        return;
    }
    void minUp(int i){
        int parent = ceil(i/2.0)-1;
        int child = i;
        while(parent>=0 && minHeap[parent] > minHeap[child]){
            swap(minHeap[parent] , minHeap[child]);
            child = parent;
            parent = ceil(child/2.0)-1;
        }
        
        return;
    }
    void maxUp(int i){
        int parent = ceil(i/2.0)-1;
        int child = i;
        while(parent>=0 && maxHeap[parent] < maxHeap[child]){
            swap(maxHeap[parent] , maxHeap[child]);
            child = parent;
            parent = ceil(child/2.0)-1;
        }
        
        return;
    }
    void insertHeap(int &x)
    {
        int median = getMedian();
        if( x>median ){
            if(minHeap.empty()) {
                minHeap.push_back(x);
                return;
            }
            else if(maxHeap.empty()){
                maxHeap.push_back(minHeap[0]);
                minHeap[0]=x;
                return;
            }
            if( minHeap.size() > maxHeap.size() ){
              balanceHeaps();
              minHeap[0]=x;
              minHeapify(0);
            }
            else {
                minHeap.push_back(x);
                minUp(minHeap.size()-1);
            }
            
        }
        else{
            if(maxHeap.empty()) {
                maxHeap.push_back(x);
                return;
            }
            else if(minHeap.empty()){
                minHeap.push_back(maxHeap[0]);
                maxHeap[0]=x;
                return;
            }
            if( maxHeap.size() > minHeap.size() ){
              balanceHeaps();
              maxHeap[0]=x;
              maxHeapify(0);
            }
            else{
                maxHeap.push_back(x);
                maxUp(maxHeap.size()-1);
            }
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.size() > minHeap.size()){
            minHeap.push_back(maxHeap[0]);
            minUp(minHeap.size()-1);
        }
        else{
            maxHeap.push_back(minHeap[0]);
            maxUp(maxHeap.size()-1);
        }
       
    }
    
    //Function to return Median.
    double getMedian()
    {   
        if(minHeap.empty() && maxHeap.empty()) return 0;
        if(minHeap.empty() || maxHeap.empty()){
            if(minHeap.empty()) return maxHeap[0];
            else return minHeap[0];
        }
        if(minHeap.size() == maxHeap.size())
           return (minHeap[0]+maxHeap[0])/2.0;
           
        if(minHeap.size() > maxHeap.size())
            return minHeap[0];
        else
            return maxHeap[0];
       
        
    }
};



int main()
{
    int n, x;
    Solution ob;
    cin >> n;
    for(int i = 1;i<= n; ++i)
    {
        cin >> x;
        ob.insertHeap(x);
        cout << floor(ob.getMedian()) << endl;
    }

	return 0;
}