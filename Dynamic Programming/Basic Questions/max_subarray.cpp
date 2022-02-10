#include<iostream>
#include<vector>
using namespace std;
int max_subarray(vector<int>arr, int size){
    if(size==0)
      return 0;
    int sum{};
    sum=max((arr,size-1),arr[size-1]+(arr,size-1));
    return sum;
}
int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<max_subarray(arr,size);
    
    return 0;
}