//GCDs of given index ranges in an array
#include<iostream>
using namespace std;

int gcd(int num1, int num2){
  if (num2 ==0)
  return num1;
 
  return gcd(num2,num1%num2);
}
// time complexity O(n)
int gcd_of_range(int* arr, int lower,int upper){
 int tmp = arr[lower];
 for (int i = lower; i < upper; i++)
 {
   tmp = gcd(tmp,arr[i+1]);
 }
 
 return tmp;
}

int main(){
    int *arr,size, result, lower, upper;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];
    cout<<"Enter the lower index of array: ";
    cin>>lower;
    cout<<"Enter the upper index of array: ";
    cin>>upper;
    result = gcd_of_range(arr, lower, upper);
    cout<<"GCD is :"<<result;
    return 0;
    

}