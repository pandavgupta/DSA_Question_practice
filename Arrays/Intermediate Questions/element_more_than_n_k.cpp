//Given an array of size n and a number k, find all elements that appear more than n/k times
#include<iostream>
#include<unordered_map>
using namespace std;
//time complexity O(N) and space is O(N).
void finding_element(int* arr, int n, int k){
    unordered_map<int,int>m;
    int count=1;
    for (int i = 0; i < n; i++)
    {
        if( m.find(arr[i]) == m.end() )
            m[arr[i]]=1;
        else
        m[arr[i]]++;
    }
    cout<<"element more than n/k are: ";
    for(int i=0; i<n; i++){
        if ( m[arr[i]] >(n/k))
        {
           cout<<arr[i]<<" ";
           m[arr[i]]=1;
        }
        

    }
    
}

int main(){
    
   int size,*arr,k;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   cout<<"Enter the array's element: ";
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   cout<<"Enter the value of k: ";
   cin>>k;
   
   finding_element(arr, size,k);

    
    return  0;

}