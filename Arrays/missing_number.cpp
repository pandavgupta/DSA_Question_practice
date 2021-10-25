#include<iostream>
using namespace std;

/* // Method- using summation approach
void missing_element(int* arr, int size){
    int total_sum= (size*(size+1)/2),
        sum=0,
        element;
    for (int i = 0; i < size-1; i++)
     sum=sum+arr[i];

     element= total_sum - sum;

     cout<<"Missing element is : "<<element;

   return;
        
}
*/

void missing_element(int* arr, int size){
    int a=1,b=arr[0];
    for (int i = 2; i <= size; i++)
       a=a^i;
    for (int i = 1; i < size; i++)
       b= b^arr[i];
    cout<<"Missing element in the array : "<<(a^b);
    return;
}





int main(){
    int size;
    int* arr=NULL;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size-1; i++)
    cin>>arr[i];

    missing_element(arr, size);

    return 0;

    
}