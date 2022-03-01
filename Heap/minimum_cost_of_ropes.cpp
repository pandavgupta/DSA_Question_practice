#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void minHeapify(long long arr[], int size, int i){
        int largest = i ;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;
        if( leftchild < size && arr[largest] > arr[leftchild]  ) 
            largest = leftchild;
        if( rightchild < size && arr[largest] > arr[rightchild] )
            largest = rightchild;
        if( largest != i ){
            swap( arr[largest], arr[i] );
            minHeapify( arr, size,largest);
        }
        
        return;
    }
    void build_heap(long long arr[],int n){
        int i=(n/2)-1;
        for(i; i>=0; i--){
            minHeapify(arr,n,i);
        }
        
    }
    long long minCost(long long arr[], long long n) {
      long long maxv{};
      build_heap(arr,n);
      long long heap_size=n;
      long long first, second;
      while(heap_size>1){
          first=arr[0];
        //   second=arr[1];
          swap(arr[0],arr[heap_size-1]);
          heap_size--;
          minHeapify(arr,heap_size,0);
          second=arr[0];
          arr[0]=first+second;
          minHeapify(arr,heap_size,0);
          maxv+=(first+second);
      }
      return maxv;
    }
};


int main() {
   
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    return 0;
}