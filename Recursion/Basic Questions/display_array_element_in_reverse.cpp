#include<iostream>
using namespace std;
void display(int arr[], int n){
    if(n==0)
    return;
    
    cout<<arr[n-1]<<" ";
    display(arr,n-1);
 
}
int main(){
    int n,*arr;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the element of array: ";
    arr= new int[n];
    for (size_t i = 0; i < n; i++)
    cin>>arr[i];
    display(arr,n);

    return 0;
}