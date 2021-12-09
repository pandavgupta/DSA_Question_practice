#include<iostream>
#include<vector>
using namespace std;
int find_element(vector<int>&arr, int n, int data){
    if(arr.size() == n)
    return -1;
    if ( data == arr[n-1])
     return n-1;
    return  find_element(arr,n+1,data);
    
}
int main(){
    int n,element,tmp;
    vector<int>arr;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the element of array: ";
    for (size_t i = 0; i < n; i++){
     cin>>tmp;
     arr.push_back(tmp);
    }
    cout<<"Enter the element to be find: ";
    cin>>element;
    cout<<"index of "<<element<<": "<<find_element(arr,1,element);

    return 0;
}