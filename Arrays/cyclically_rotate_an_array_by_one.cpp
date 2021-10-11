#include<iostream>
using namespace std;


void rotate_array(int* arr, int size){
    int i=size-2, tmp=arr[size-1];
    while ( i >= 0 )
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[0]=tmp;

    cout<<"Array after cyclic rotation by one: ";
    for ( i = 0; i < size; i++)
    cout<<arr[i]<<" ";
    
    return;
}


int main(){
    int size;
    int* arr=NULL;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    rotate_array(arr, size);

    return 0;
    
}