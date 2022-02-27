#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}



class Solution
{
    public:
   
    void update(vector<int>&arr,int size){
        int child=size;
        int parent=(ceil(child/2.0)-1);
        while(parent>=0 && arr[child]>arr[parent]){
            swap(arr[child],arr[parent]);
            child=parent;
            parent=(ceil(child/2.0)-1);
        }
        return;
    }
    void heapify(vector<int>& arr,int n , int i){
        int largest=i;
        int leftchild=2*i+1;
        int rightchild = 2*i+2;
        if(leftchild<n && arr[largest]<arr[leftchild]) largest=leftchild;
        if(rightchild<n && arr[largest]<arr[rightchild]) largest=rightchild;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        return;
    }
    void build_heap(vector<int>&arr,int n){
        int i=(n/2)-1;
        for(i; i>=0; i--){
            heapify(arr,n,i);
        }
        
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
       vector<int>res(k*k);
       for(int i=0; i<k; i++){
           res[i]=arr[0][i];
       }
       build_heap(res,k);
       int heap_size=k;
       for(int i=1; i<k; i++){
           for(int j=0; j<k; j++){
               res[heap_size]=arr[i][j];
               update(res,heap_size);
               heap_size++;
           }
       }
       
   
      int size=heap_size;
      while(size>1){
            swap(res[0],res[size-1]);
            heapify(res,size-1,0);
            size--;
        }
       return res;
    }
};


int main()
{
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
	return 0;
}
