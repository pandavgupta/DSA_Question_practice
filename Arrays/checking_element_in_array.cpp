#include<iostream>
#include<vector>
using namespace std;
 int main(){
   int size, tmp, key, flag=0;
   vector<int> arr;

   //using Vector inserting element 
   cout<<"Enter the size of array: ";
   cin>>size;
   cout<<"Enter element of array : ";
   for(int i=0; i<size; i++){
     cin>>tmp;
     arr.push_back(tmp);
   }
   cout<<"Enter key element to check: ";
    cin>>key;


    /* printing elment of vector array
   cout<<"Element of array: ";
   for( auto i = arr.begin(); i!=arr.end() ; i++) {
     
     cout<<*i<<" ";

   }
   */ 


  //iterating the vector
   for(auto i:arr){
     if(key==i)
     flag=1;
   }
   if(flag)
   cout<<" True\n";
   else
   cout<<" False\n";
   return 0;
 }