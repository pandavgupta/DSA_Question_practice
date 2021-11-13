#include<iostream>
using namespace std;

//Swap function
void swap(int *number1,int *number2){
 int tmp;
 tmp=*number1;
 *number1=*number2;
 *number2=tmp;
 
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;

}
int main(){
    int arr[10]={0};
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the element of array: ";
    for(int i=0;i<size; i++)
    cin>>arr[i];
    cout<<"Normal array: ";
    printArray(arr,size);


    //Calling swap function for swapping values
    for (int i = 0; i < size/2; i++)
    {
        swap(&arr[i],&arr[size-i-1]);
    }


    //printing the element in reverse order
    cout<<"Reverse array: ";
    printArray(arr,size);

    return 0;
}