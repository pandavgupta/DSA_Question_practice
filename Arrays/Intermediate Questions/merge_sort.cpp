#include<iostream>
#include<vector>
using namespace std;

void merge( vector<int> &arr , int start, int mid, int last)
{
    int arr2[last], i, j, k;
    i = start;
    j = mid+1;
    k = start;

    while ( i <= mid && j <= last )
    {
        if (  arr[i] < arr[j] )
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
        
    }

    if( i > mid  )
    {
        while ( j <= last)
        {
            arr2[k++] = arr[j++];
        }
        
    }
    else{
        while ( i <= mid)
        {
            arr2[k++] = arr[i++];
        }
    }

    for ( k = start ; k <= last ;  k++ )
    {
        arr[k]=arr2[k];
    }


    return;
    

}

void merge_sort( vector<int> &arr , int start , int last )
{
  if( start < last )
  {
      int mid = ( start + last )/2 ;
      merge_sort( arr, start, mid );
      merge_sort( arr, mid+1 , last);
      merge(arr, start, mid, last);
  }

  return;
}

int main(){
    int size,tmp;
    vector<int> arr;
    
    cout<<"Enter the size of array: ";
    cin>>size;
    
    cout<<"Enter the element of array: ";
    for ( int i = 0 ; i < size ; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    merge_sort( arr , 0 , size-1 );

    cout<<"After merge sort: ";

    for( int i=0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    

    return 0;
    
}