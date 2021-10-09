#include<iostream>
using namespace std;

void swap(int* arr, int i, int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;

    return;
}

void move_negative_element(int* arr, int size){
    int i=0, j=0;
    while( j< size){
        if (arr[j] < 0 )
        {
            swap(arr,i,j);
            i++;
        }
        j++;
        
    }
}

int main(){
    int* arr=NULL;
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
     arr=new int[size];
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    move_negative_element(arr,size);

    cout<<"After operation: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}