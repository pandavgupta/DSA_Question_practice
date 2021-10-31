#include<iostream>
#include<unordered_map>
using namespace std;

int find_sum_pair(int* arr, int n, int k){
     int count=0;
        unordered_map<int,int>map;

        for(int i=n-1; i >= 0; i--){
            if( map.find(k-arr[i])  != map.end())
            {
               count=count+map[k-arr[i]];
                
            }
            if(map.find(arr[i])==map.end())
            map[arr[i]]=1;
            else
            map[arr[i]]++;
        }
        
        
        
        return count;
    
}





int main(){
    
   int size, sum,count=0;
   int* arr;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   cout<<"Enter the sum element: ";
   cin>>sum;
   count =  find_sum_pair(arr, size, sum);

   cout<<"Number of pair is/are :"<<count;
    
    return  0;

}