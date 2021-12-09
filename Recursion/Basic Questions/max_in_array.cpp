#include<iostream>
#include<vector>
using namespace std;
int find_max(vector<int>&arr, int n){
    if(n == 1)
    return arr[n-1];
    
    return  max(arr[n-1],find_max(arr,n-1));

}

int main(){
    int n,element,tmp;
    vector<int>arr;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the element of array: ";
    for (size_t i = 0; i < n; i++){
     cin>>tmp;
     arr.push_back(tmp);
    }
    cout<<"max element is :"<<find_max(arr,arr.size());

    return 0;
}