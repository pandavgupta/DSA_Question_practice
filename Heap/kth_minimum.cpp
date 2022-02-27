// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
   void heapify(int arr[],int n , int i){
        int largest=i;
        int leftchild=2*i+1;
        int rightchild = 2*i+2;
        if(leftchild<n && arr[largest]>arr[leftchild]) largest=leftchild;
        if(rightchild<n && arr[largest]>arr[rightchild]) largest=rightchild;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        return;
    }
    void build_heap(int arr[],int n){
        int i=(n/2)-1;
        for(i; i>=0; i--){
            heapify(arr,n,i);
        }
        
    }
   int kthSmallest(int arr[], int l, int r, int k)
    {
        build_heap(arr+l,r+1);
        int maxv=0;
        int size=r+1;
        for(int i=0; i<k; i++){
            maxv=arr[l];
            swap(arr[l],arr[size-1]);
            heapify(arr,size-1,l);
            size--;
        }
        return maxv;
        
    }
};

// { Driver Code Starts.
 
int main()
{
    
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    return 0;
}  // } Driver Code Ends