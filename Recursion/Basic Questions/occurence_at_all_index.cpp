#include<iostream>
#include<vector>
using namespace std;
void find_element(vector<int>&arr, int n, int data){
    if(n == 0)
    return ;
    find_element(arr,n-1,data);
    if ( arr[n-1]==data )
    cout<<n-1<<" ";
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
    cout<<"index of "<<element<<": ";
    find_element(arr,arr.size(),element);

    return 0;
}