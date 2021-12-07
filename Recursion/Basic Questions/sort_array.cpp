#include<iostream>
#include<vector>
using namespace std;
//sorting array using recursion
/*
void add_element(vector<int>&arr, int pos,int tmp ){
    if(pos==0 || arr[pos-1]<=tmp ){
        arr[pos]=tmp;
        return;
    }

       arr[pos]=arr[pos-1];
       add_element(arr,pos-1,tmp);

}
*/
void add_element(vector<int>&arr, int pos){
  if(arr[pos-1]<=arr[pos] || pos==0)
    return ;
    swap(arr[pos-1],arr[pos]);
    add_element(arr,pos-1);
}

void sort_array(vector<int>&arr,int size){
    if (size==0)
    return;
    sort_array(arr,size-1);
    add_element(arr,size);
}

int main(){
    int size,tmp;
    vector<int>arr;
    cout<<"Enter the number size of array:";
    cin>>size;
    cout<<"Enter the element of array:";
    for (int i = 0; i < size; i++)
    {
     cin>>tmp;
     arr.push_back(tmp);
    }
    sort_array(arr,arr.size()-1);
    cout<<"array after sorting: ";
    for (int i = 0; i < size; i++)
    cout<<arr[i]<<" ";

    return 0;
}