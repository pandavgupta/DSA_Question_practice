#include<iostream>
using namespace std;
//method-1, brute force, finding all subarray 
//method-2, kadane's algorithm
long long max_subarray_sum(int *arr, int size){
    long long max=arr[0],sum=0;
    for (int i = 0; i < size; i++)
    {
        sum=sum+arr[i];
        if(sum>max)
        max=sum;
        if(sum<0)
        sum=0;
    }

    return max;
    
}

int main(){
    int size,*arr;
    long long max;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    cout<<"Enter element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    max=max_subarray_sum(arr, size);
    cout<<"Maximum subarray sum is: "<<max;

 return 0;   
}