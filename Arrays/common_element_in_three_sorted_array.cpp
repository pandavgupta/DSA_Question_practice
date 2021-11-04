//Find	common	elements	in	three	sorted	arrays
#include<iostream>
using namespace std;

void find_common_element(int* arr1, int size1,int* arr2,int size2, int* arr3,int size3){
 int i=0,j=0,k=0;
 cout<<"Common elements are: ";
 while ( i < size1 && j < size2 && k < size3 )
 {
    if(arr1[i]==arr2[j] && arr1[i]==arr3[k] && arr2[j]==arr3[k])
    {
        cout<<arr1[i]<<" ";
        i++;
        j++;
        k++;
    }

    else{
        if(arr1[i] < arr2[j] || arr1[i]<arr3[k])
        i++;
        if(arr2[j] < arr1[i] || arr2[j]<arr3[k])
        j++;
        if(arr3[k] < arr2[j] || arr3[k]<arr1[i])
        k++;

    }
    


 }
 
 
 
 
 return;
}


int main(){
    int size1,size2,size3;
    int *arr1,*arr2,*arr3;
    
    cout<<"Enter the size of first array: ";
    cin>>size1;
    arr1= new int[size1];
    cout<<"Enter element of first array: ";
    for (int i = 0; i < size1; i++)
    cin>>arr1[i];

    cout<<"Enter the size of second array: ";
    cin>>size2;
    arr2= new int[size2];
    cout<<"Enter element of second array: ";
    for (int i = 0; i < size2; i++)
    cin>>arr2[i];

    cout<<"Enter the size of third array: ";
    cin>>size3;
    arr3= new int[size3];
    cout<<"Enter element of third array: ";
    for (int i = 0; i < size3; i++)
    cin>>arr3[i];

    find_common_element(arr1,size1,arr2,size2,arr3,size3);

    return 0;
    
}