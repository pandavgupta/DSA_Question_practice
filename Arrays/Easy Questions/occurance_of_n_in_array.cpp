//ptr[i] is equivalent to *(ptr+i)

#include<iostream>
#include<vector>
using namespace std;

// Occurance of every element in array using another array
/*
void find_occurance(vector<int>&arr, int size, int max){
    int arr2[max+1]={0}, tmp;
    for(int i = 0 ; i < size; i++ ){
        if(arr[i]){
        arr2[arr[i]]++;
        }

    }

    cout<<"\nOccurance of element in array are: "<<endl;
    for (int i = 0; i <= max; i++)
    {   if(arr2[i])
        cout<<i<<" : "<<arr2[i]<<endl;
    }

    return ;
    
}
*/





//occurance of key element in the array

void find_occurance(vector<int>&arr, int key){
    int tmp=0, flag=0;
    for(int i = 0 ; i < arr.size(); i++ ){
        if(arr[i]==key){
        tmp++;
        flag=1;
        }

    }
    if (flag)
    cout<<"Occurance of element in array are: "<<tmp<<endl;
    else
    cout<<"Element not found!!";
    return ;
    
}





int main(){
    int tmp ,size, element;

    vector<int>arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    cout<<"Enter the element the for which you want to find occurance: ";
    cin>>element;


    // max=arr[0];
    // for (int i = 1; i < size; i++)
    // {
    //     if( arr[i] > max)
    //     max=arr[i];
    // }
    // cout<<"max: "<<max;

    find_occurance(arr, element);
    
    

    return 0;

}