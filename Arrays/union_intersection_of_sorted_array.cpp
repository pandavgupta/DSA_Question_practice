#include<iostream>
using namespace std;

void find_union(int* arr1,int* arr2, int size1, int size2 ){

    int arr3[size2+size1+1]{};
    int i=0,j=0,k=0;

    while ( i < size1 && j < size2 )
    {
        if( arr1[i] < arr2[j])
        {   if (arr3[k-1] == arr1[i])
             i++;
            else
             arr3[k++]=arr1[i++];
        }

        else
        {
               if(arr1[i] > arr2[j])
                {  
                    if (arr3[k-1] == arr2[j])
                    j++;
                    else
                    arr3[k++]=arr2[j++];
                }
            
                else{
                    if (arr3[k-1] == arr1[i])
                      i++;
                    else
                    arr3[k++]=arr1[i++];
                      j++;      
                    
                }

        }
    }

    if ( i < size1  )
    {
        while ( i< size1 )
        {   if (arr3[k-1] == arr1[i])
            i++;
            else
            arr3[k++]=arr1[i++];
        }
        
    }
    if(j < size2){
        while ( j < size2 )
        {   if (arr3[k-1] == arr2[j])
            j++;
            else
            arr3[k++]=arr2[j++];
        }
        
    }
    
    cout<<"Union of array is : ";
    for (int i = 0; i < k; i++)
    {
         cout<<arr3[i]<<" ";
    }
    

 return;

}


void find_intersection(int* arr1,int* arr2, int size1, int size2){
    int max = size1>size2?size1:size2;
    int arr3[max];
    int i=0,j=0,k=0;
    while ( i < size1 && j < size2 )
    {
        if(arr1[i]==arr2[j]){
            if ( arr3[k-1] == arr1[i])
            {
                i++;
                j++;
            }
            else{
               arr3[k++]=arr1[i++];
               j++; 
            }
            
        }
        else{
            if ( arr1[i] < arr2[j])
            i++;
            else
            j++;
            
        }
    }

    cout<<"\nIntersection of array is : ";
    for (int i = 0; i < k; i++)
    {
         cout<<arr3[i]<<" ";
    }


    return ;
    
}


int main(){
    int size1, size2;
    int* arr1=NULL;
    int* arr2=NULL;
    
    cout<<"Enter the size of first array: ";
    cin>>size1;
    arr1= new int[size1];
    cout<<"Enter element of first array: ";
    for (int i = 0; i < size1; i++)
    cin>>arr1[i];

    cout<<"Enter the size of second array: ";
    cin>>size2;
    arr2=new int[size2];
    cout<<"Enter element of second array: ";
    for (int i = 0; i < size2; i++)
    cin>>arr2[i];

    find_union( arr1, arr2, size1, size2) ;
    find_intersection( arr1, arr2, size1, size2) ;

    return 0;
    
}