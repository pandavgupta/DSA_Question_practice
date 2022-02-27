// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest=i;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;
        if(leftchild<n && arr[leftchild]>arr[largest]) largest=leftchild;
        if(rightchild<n && arr[rightchild]>arr[largest]) largest=rightchild;
        if(largest!=i ){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
      int i=n/2-1;
      for(i; i>=0; i-- ){
          heapify(arr,n,i);
      }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {   buildHeap(arr,n);
        int size=n;
        while(size>1){
            swap(arr[0],arr[size-1]);
            heapify(arr,size-1,0);
            size--;
        }
       
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[100],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    return 0;
}
  // } Driver Code Ends