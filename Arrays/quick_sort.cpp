#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>&arr, int pos1, int pos2){
    int tmp=arr[pos1];
    arr[pos1]=arr[pos2];
    arr[pos2]=tmp;

    return;

}

int partition(vector<int>&arr, int pivot, int last){
    int i = pivot+1, j = last;
    while( i <= j )
        {
            while(  arr[pivot] >= arr[i] && i<=last)
                i++;
            while(  arr[pivot] <= arr[j] && j>=pivot)
               j--;
            if(i< j)
            swap(arr,i,j);
        }
        if(j>=pivot)
        swap(arr,pivot,j);
    return j;

}


void quick_sort(vector<int> &arr, int start, int last  ){

    if( start < last ){
        int pivot_pos;

        pivot_pos = partition(arr,start,last);
        quick_sort(arr,start,pivot_pos-1);
        quick_sort(arr,pivot_pos+1,last);
        

    }

    return ;


}

int main()
{
    int tmp, size;
    vector<int>arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the element of array : ";
    for(int i=0 ; i<size; i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    quick_sort(arr,0,size-1);
    cout<<"Array after quick sort: ";
    for(int i=0; i< size; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}
