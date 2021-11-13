#include<iostream>
#include<unordered_set>
using namespace std;
// Find	if	there	is	any	subarray	with	sum	equal	to	zero
//Method-1 brute force, time complexity O(n^2) and space complexity O(1)
/*
bool subarray_sum(int *arr, int size){
    int sum;
    for (int i = 0; i < size; i++)
    {
        sum=0;
        for (int j = i; j < size; j++)
        {
            sum+=arr[j];
            if (sum ==0)
            return true;
            
        }
        

    }

    return false;

}
*/

//Method-2 using hashing, concept of prefix sum.
//time complexity O(n) and space complexity O(n).
bool subarray_sum(int *arr, int size){
    int sum=0;
    unordered_set<int> s;
    for (int i = 0; i < size; i++)
    { 
        sum+=arr[i];
        if ( sum==0 || s.find(sum)!=s.end())
        return true;
        else
        s.insert(sum);
        
    }
    return false;
}

int main(){
    int size,*arr;
    bool found;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    cout<<"Enter element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    found = subarray_sum(arr, size);
    if(found)
    cout<<"Yes";
    else
    cout<<"No";

 return 0;   
}