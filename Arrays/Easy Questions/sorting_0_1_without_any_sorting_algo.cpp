#include<iostream>
#include<vector>
using namespace std;


/* METHOD-1 
Sorting using simple if else and variable
void sort_without_any_sort_algo(vector<int>&arr){
    int count1=0,count2=0,count3=0;
    vector<int>arr2;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i]==0)
      count1++;
      else if (arr[i]==1)
      count2++;
      else
      count3++; 
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if ( i < count1 )
        arr2.push_back(0);
        else 
          { if (i >= count1 && i < count1+count2)
            arr2.push_back(1);
            else
            arr2.push_back(2);
          }
    }
    cout<<"Element after sorting: ";
    for (int  i = 0; i < arr2.size(); i++)
    {
        cout<<arr2[i]<<" ";
    }
    
    return ;
}
*/



/* METHOD-2
void swap(vector<int>&arr, int i ,int j){
  int tmp=arr[i];
  arr[i]=arr[j];
  arr[j]=tmp;
  return;
}

void sort_without_any_sort_algo(vector<int>&arr){
  int i=0, j=0;
  while(j < arr.size()){
    if ( arr[j]==0)
    {swap(arr, i,j);
      i++;
    }
    j++;
    
  }
  i=arr.size()-1;
  j=arr.size()-1;
  while( j >= 0 ){
    if(arr[j]==2){
      swap(arr,j,i);
      i--;
    }
    j--;
  }

 return;
}
*/

// METHOD-3 DUTCH National Flag Algorithm
void swap(vector<int>&arr, int i ,int j){
  int tmp=arr[i];
  arr[i]=arr[j];
  arr[j]=tmp;
  return;
}

void sort_without_any_sort_algo(vector<int>&arr){
  int i=0, j=0, h=arr.size()-1;
  while(j <= h){
    if ( arr[j]==0)
    {swap(arr, i,j);
      i++;
      j++;
    }
    else {
            if ( arr[j]==2)
              {swap(arr, h,j);
              h--;
              }
            else
            j++;
         }
  }

 return;
}







int main(){
    int size,tmp;
    vector<int>arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    {
     cin>>tmp;
     arr.push_back(tmp);
    }
    sort_without_any_sort_algo(arr);
    cout<<"Element after tunning: ";
    for (int  i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
    
}