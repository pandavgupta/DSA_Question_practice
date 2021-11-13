#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>&arr, int i , int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;

    return;
}

void reverse_array(vector<int> &arr){


    for(int i = 0; i < (arr.size())/2 ; i++ ){
       swap(arr, i, arr.size()-1-i);
    }
}


int main()
{
    int tmp, size;
    vector<int> arr;

    cout<<"Enter the size of array: ";
    cin>>size;

    cout<<"Enter the element of array: ";
    for(int i= 0 ; i < size ; i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    reverse_array(arr);
    cout<<"Array after reverse: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}