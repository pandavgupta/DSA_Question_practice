//Buy and sell one stock with maximum profit.
#include<iostream>
#include<algorithm>
using namespace std;

//time complexity O(n^2).
/* int stock(int *arr, int size){
 int max=0;
 for (int i = 1; i < size; i++)
 {
     for (int j = i+1; j < size; j++)
     {
         if((arr[j]-arr[i]) > max)
         max=arr[j]-arr[i];
     }
     
 }
 return max;
}
*/

//time complexity O(N) and space O(1).
int stock(int *arr, int size){
 int max_profit=0,min_element=arr[0];

 for (int i = 0; i < size; i++)
 {  
    max_profit = max(max_profit, arr[i]-min_element);
    min_element = min(min_element, arr[i]); 
        
 }

 return max_profit;
 
}
//above two line max_profit,min_element can also be written as
/*
if ( min_element > arr[i])
            min_element=arr[i];
        else if ((arr[i]-min_element) > max_profit )
            max_profit = arr[i]-min_element;
*/




int main(){
    int *arr, size, max_profit;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    max_profit = stock(arr, size);
    
 cout<<"max profit : "<<max_profit;
    return 0;
}