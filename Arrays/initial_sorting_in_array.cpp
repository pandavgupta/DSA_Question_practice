
#include <iostream>
#include<vector>

using namespace std;

void swap(vector <int> &arr, int position1, int position2)
 {
     int tmp;
     tmp=arr[position1];
     arr[position1]=arr[position2];
     arr[position2]=tmp;
     return;
 }
 
 
 void display(vector <int> &arr, string sort)
 {
     cout<<"Element after "<<sort<<" sorting:";
     for(auto i=arr.begin(); i != arr.end(); i++)
     cout<<*i<<" ";
     cout<<"\n";
 }
 
 
 
 void bubble_sort(vector<int>&arr)
 {
     for(int i=0 ; i < arr.size()-1 ; i++ )
     {
         for(int j=1; j < arr.size() - i ; j++ )
         {
             if( arr.at(j-1) > arr.at(j) )
             swap(arr,j-1,j);
         }
     }
     
     
     return;
 }


void selection_sort(vector<int>&arr)
{
    int  flag=0, pos;
    for(int i = 0 ; i < arr.size()-1 ;i++ )
    {
        pos = i;
        for (int j = i+1; j < arr.size(); j++)
        {
           if( arr[j] < arr[pos])
           {
               flag=1;
               pos=j;
           }
           
        }

        if(flag)
           swap(arr,pos,i);
        
        
    }

    return;

}


void insertion_sort(vector<int>&arr)
{    
    int j , tmp ;
    for(int i = 0 ; i < arr.size()-1 ; i++ )
    {
        j=i+1;
        tmp=arr[j];
        while ( j > 0 &&  arr[j-1] > tmp )
        {
            arr[j]=arr[j-1];
            j--;       
        }
        arr[j]=tmp;

    }
}





int main()
{
    int size,tmp;
    vector<int> arr1,arr2,arr3;
    cout<<"enter the size of element you want to enter: ";
    cin>>size;
    cout<<"Enter the element of array: ";
    for(int i=0 ; i < size ; i++ )
    {
        cin >> tmp ;
        arr1.push_back(tmp);
        arr2.push_back(tmp);
        arr3.push_back(tmp);
    }
    
    bubble_sort(arr1);
    display(arr1,"Bubble");

    selection_sort(arr2);
    display(arr2,"Selection");

    insertion_sort(arr3);
    display(arr3,"insertion");



    return 0;
}