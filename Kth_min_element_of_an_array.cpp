/*
Find the Kth max and min element of an array  using set
#include<iostream>
#include<set>
using namespace std;

void kth_min_max(int arr[],int size, int kth){
    int count=1;
    set<int>s;
    for (int i = 0; i < size; i++)
    {
        s.insert(arr[i]);
    }
    
    cout << "Elements of set: \n";
    for (auto i :s)
    {
     cout<<i<<" ";
    }
    cout<<endl;
    for (auto i =s.begin(); i!=s.end(); i++)
    { if(count==kth){
        cout<<"kth min element is: "<<*i;
        break;
        }
        count++;
    }
    
    
        
    return ;


}

int main(){
    int arr[100];
    int kth=0,size=0;
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Enter the array: ";
    for ( int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"which  kth term of element you want to find:";
    cin>>kth;

    kth_min_max(arr,size,kth);
    return 0;


}
*/ 

// <---------------------------------------------------------------------------------------------->
// max heap--------------->(kth largest) O(N+logN)
// Min heap--------------->(kth largest) O(N+(k-N+1)log(N-k+1))
 
//  where O(N) is for building a heap
//  log(N) for heapify 
//  K th element 
// For finding Max kth element min heap is good where as in case of min kth element max heap is good.

#include<iostream>
#include<cmath>
using namespace std;
void swap(int arr[],int curr, int largest){
    int tmp=arr[curr];
    arr[curr]=arr[largest];
    arr[largest]=tmp;
    return;
}

void heapify(int arr[],int size, int curr){
    int largest=curr,
    Lchild=2*curr+1,
    Rchild= 2*curr+2;
    if(Lchild<=size && arr[Lchild]>arr[largest])
      largest=Lchild;
    if(Rchild<=size && arr[Rchild]>arr[largest])
      largest=Rchild;
    if(largest!=curr){
        swap(arr,curr,largest);
        heapify(arr,size,largest);
    }
    return;

}

int main(){
    int size,arr[100],nth;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the array: ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"which term you want to find: ";
    cin>>nth;
    for (int curr = floor(size/2)-1; curr >=0; curr--)
    {
       heapify(arr,size,curr);
    }

cout<<"After heapify: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
cout<<"\n";

    for (int i = size-1; i >0; i--)
    {
        swap(arr,0,i);
        cout<<"\nAfter swap: ";
       for (int i = 0; i < size; i++)
       {
        cout<<arr[i]<<" ";
        }
        heapify(arr,i-1,0);
         cout<<"\nAfter heapify: ";
       for (int i = 0; i < size; i++)
       {
        cout<<arr[i]<<" ";
        }
        
    }

    cout<<"\nAfter heap sort: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"\nKth element is: "<<arr[size-nth-1];

 return 0;
    
}