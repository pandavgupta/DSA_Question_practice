// Find	the	first	repeating	element	in	an	array	of	integers. 
#include <iostream>
#include<unordered_map>

using namespace std;

int firstRepeated(int* arr, int n) {
        int value=-1;
        unordered_map<int,int>m;
        
        for(int i=0; i<n; i++){
            if(m.find(arr[i])!=m.end()){
                m[arr[i]]+=n;
            }
            else
            m[arr[i]]=i+n;
        }
        for(int i=0; i<n; i++){
            if(m[arr[i]]/n > 1)
            {   
               value=(m[arr[i]]%n)+1;
               break;
            }
            
        }
    
    return value;
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
   
   cout<<"first repeated element (-1 means Null): "<<value;
   
   
   delete arr; 
    return  0;
    

}
