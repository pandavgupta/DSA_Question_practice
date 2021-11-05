//Given an array with all distinct elements, find the largest three elements.
//Expected time complexity is O(n) and extra space is O(1).
#include<iostream>
using namespace std;

int main(){
    int size, max1,max2,max3;
    int *arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr=new int[size];
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    max1=arr[0];
    max2=arr[0];
    max3=arr[0]; 

    for (int i = 1; i < size; i++)
    {
        if (arr[i]>max3)
        {
            if(arr[i]>max1){
            max3=max2;
            max2=max1;
            max1=arr[i];
            }
            
            else{
                if(arr[i]>max2)
                {
                    max3=max2;
                    max2=arr[i];
                }
                
                else{
                    if(arr[i]>max3)
                    max3=arr[i];
                }
            }
        }
        
    }

    cout<<"Max :"<<max1<<", Max2: "<<max2<<", Max3: "<<max3;
    


    return 0;
}