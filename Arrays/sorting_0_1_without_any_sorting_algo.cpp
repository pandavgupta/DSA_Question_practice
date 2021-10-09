#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>&arr){
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
    // cout<<"0 element is : "<<count1<<endl;
    // cout<<"1 element is : "<<count2<<endl;
    // cout<<"2 element is : "<<count3<<endl;

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
    sort(arr);

    return 0;
    
}