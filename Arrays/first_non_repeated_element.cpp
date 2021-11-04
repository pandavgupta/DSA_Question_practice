// Find	the	first	repeating	element	in	an	array	of	integers. 
#include <iostream>
#include<unordered_map>

using namespace std;

int firstRepeated(int* arr, int n) {
        int value=-1;
        unordered_map<int,int>m;
        
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        for(int i=0; i<n; i++){
            if(m[arr[i]] == 1)
            return arr[i];
            
        }
    
    return -1;
    }

int main(){
    
   int size;
   int* arr;
   int value;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   cout<<"Enter element of array: ";
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   
  value =  firstRepeated(arr, size);
   
   cout<<"first non-repeated element (-1 means Null): "<<value;
   
   
   delete arr; 
    return  0;
    

}
