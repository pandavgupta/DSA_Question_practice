// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void minHeapify(int arr[], int size, int i){
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
    void build_heap(int arr[],int n){
        int i=(n/2)-1;
        for(i; i>=0; i--){
            minHeapify(arr,n,i);
        }
        
    }
 string solve(int arr[], int n) {
       if(n==1) return to_string(arr[0]);
       int heap_size=n;
       build_heap(arr,heap_size);
       vector<int>first(n/2+2);
       vector<int>second(n/2+2);
       int size1{};
       int size2{};
       string result = "";
       while(arr[0]==0){
           swap(arr[0],arr[heap_size-1]);
           heap_size--;
           minHeapify(arr,heap_size,0);
       }
       first[size1++]=arr[0];
       swap(arr[0],arr[heap_size-1]);
       heap_size--;
       minHeapify(arr, heap_size, 0);
       second[size2++]=arr[0];
       swap(arr[0],arr[heap_size-1]);
       heap_size--;
       minHeapify(arr, heap_size, 0);
       for(int i=heap_size; i>0; i--){
           if(i&1){
               first[size1++]=arr[0];
           }
           else{
               second[size2++]=arr[0];
           }
           
       swap(arr[0],arr[heap_size-1]);
       heap_size--;
       minHeapify(arr, heap_size, 0);
           
       }
       reverse(first.begin(),first.begin()+size1);
       reverse(second.begin(),second.begin()+size2);
       int carry{};
       for(int i=0; i<size1; i++){
           result=to_string((first[i]+second[i]+carry)%10)+result;
           carry = (first[i]+second[i]+carry)/10;
       }
       if(carry) result=to_string(carry)+result;
    return result;
    }
};
// 28 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5 7 6 1 8 9 2 7 9 5 4 3 1
// { Driver Code Starts.
int main() {
  
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    return 0;
}  // } Driver Code Ends