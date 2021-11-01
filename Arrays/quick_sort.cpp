#include<iostream>
using namespace std;

void swap(int *pos1, int *pos2){
    int tmp = *pos1;
    *pos1 = *pos2;
    *pos2 = tmp;

    return;

}
// pivot at starting position
/* int partition(vector<int>&arr, int pivot, int last){
    int i = pivot+1, j = last;
    while( i <= j )
        {
            while(  arr[pivot] >= arr[i] && i<=last)
                i++;
            while(  arr[pivot] <= arr[j] && j>=pivot)
               j--;
            if(i< j)
            swap(&arr[i],&arr[j]);
        }
        if(j>=pivot)
        swap(&arr[pivot],&arr[j]);
    return j;

}
*/

// pivot at last position

 int partition(int* arr, int start, int pivot){
    
    int i = start-1, j;
    for (int j=start ; j < pivot; j++)
    {
        if( arr[j] < arr[pivot])
        {
            i++;
            swap(&i, &j);
        }
        
    }
    swap(&arr[i+1],&arr[pivot]);
    

    
    return i+1;

}


void quick_sort(int* arr, int start, int last  ){

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
    int *arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr = new int[size];
    cout<<"Enter the element of array : ";
    for(int i=0 ; i<size; i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,size-1);
    cout<<"Array after quick sort: ";
    for(int i=0; i< size; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}
