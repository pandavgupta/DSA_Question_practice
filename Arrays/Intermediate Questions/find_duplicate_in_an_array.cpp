#include<iostream>
#include<vector>
#include<map>
using namespace std;

// time complexity= O(n)
// space complexity= O(n)
/* vector<int> duplicates(int* arr, int n) {
        vector<int> arr2;
        int a[n]{};
        for(int i=0; i< n;i++)
            a[arr[i]]++;
        for (int i = 0; i < n; i++)
        {
          if(a[i]>1)
          arr2.push_back(i);
        }
        if(!arr2.size())
        arr2.push_back(-1);

       return arr2;
}
*/
//without using extra array a for storing it's frequency;
//if time comlexity O(n), space complexity O(1)+O(m), where m is no of duplicate element.
vector<int> duplicates(int* arr, int n) {
        vector<int> arr2;
        int index;
        for(int i=0; i< n;i++){
            index=arr[i]%n;
            arr[index]+=n;
        }

        for (int i = 0; i < n; i++)
        {
          if(arr[i]/n>1)
          arr2.push_back(i);
        }
        if(!arr2.size())
        arr2.push_back(-1);

       return arr2;
}

int main(){
    
   int size;
   int* arr;
   vector<int>arr2;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   cout<<"Enter element of array: ";
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   
   arr2 =  duplicates(arr, size);
   
   cout<<"Duplicates element are (-1 means Null): ";
   for (int i = 0; i < arr2.size(); i++)
   cout<<arr2[i]<<" ";
   
   
   delete arr; 
    return  0;
    

}