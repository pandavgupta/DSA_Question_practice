#include<bits/stdc++.h>
using namespace std;
int partition (vector<int>&arr, int low, int high,int pivot)
{
    int i = low, j = high, pivot_value = 0, tmp =0;
    pivot_value = arr[pivot];
    while(i < j ){
        while( i < pivot && arr[i] <= pivot_value) i++;
        while( j > pivot && arr[j] >= pivot_value) j--;
        if(i == pivot || j == pivot){
            if(i != pivot) pivot = i;
            else pivot = j;
        }
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        
    }
    return pivot;
}
void quickSort(vector<int>&arr, int low, int high)
{
    int pivot = (low + high)/2;;
    if( low < high){
        pivot = partition(arr, low, high, pivot);
        quickSort(arr, low, pivot-1);
        quickSort(arr,pivot+1, high);
    }
}

int main() {
    int n;
    cin>>n;
     vector<int>arr(n);
    // for(int i =0 ; i  < n; i++) cout<<arr[i]<<" ";
    // cout<<"\n";
    for(int i =0 ; i < n; i++) cin>>arr[i];
    // for(int i =0 ; i  < n; i++) cout<<arr[i]<<" ";
    // cout<<"\n";
    quickSort(arr, 0, n-1);
    for(int i =0 ; i  < n; i++) cout<<arr[i]<<" ";

    return 0;
}