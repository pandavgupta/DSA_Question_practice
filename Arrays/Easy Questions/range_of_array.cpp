#include<iostream>
using namespace std;


/*
void merge( int* arr , int start, int mid, int last)
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

void merge_sort( int* arr , int start , int last )
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
    int* arr=NULL;
    
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    
    cout<<"Enter the element of array: ";
    for ( int i = 0 ; i < size ; i++)
    {
        cin >> arr[i];
    }

    merge_sort( arr , 0 , size-1 );

    cout<<"range of array is  "<<arr[size-1]-arr[0];

    delete[] arr;
    

    return 0;
    
}
*/
struct Pair
{
   int max;
   int min;
};

void swap(int* arr, int i, int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
    return;
}


struct Pair find_range(int * arr, int size){
    struct Pair min_max;

         if ( size/2==0)
        {
           if(arr[1]> arr[0]){

                min_max.max=arr[1];
                min_max.min=arr[0];
            }

            else{

                min_max.max=arr[1];
                min_max.min=arr[0];

            }
        }
        else {
              min_max.max=arr[0];
              min_max.min=arr[0];

        }

        for (int i = 2; i < size-1; i=i+2)
        { 
            if ( arr[i] > arr[i+1])
            {
                if(arr[i] > min_max.max )
                    min_max.max=arr[i];
                if(arr[i+1] < min_max.min )
                    min_max.min=arr[i+1];
                
            }
            else{
                if(arr[i+1] > min_max.max )
                    min_max.max=arr[i+1];
                if(arr[i] < min_max.min )
                    min_max.min=arr[i];
                
            }
            
            
        }
        
   return min_max; 
    
}




int main(){
    int size,tmp;
    int* arr=NULL;
    struct Pair min_max;
    
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    
    cout<<"Enter the element of array: ";
    for ( int i = 0 ; i < size ; i++)
    {
        cin >> arr[i];
    }

    min_max=find_range( arr , size );

    cout<<"range of array is  "<<min_max.max-min_max.min;

    delete[] arr;
    

    return 0;
    
}