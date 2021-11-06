//Rearrange	the	array	in	alternating	positive	and	negative	items	with O(1)	extra	space.
//setting  first element as negative . 
#include<iostream>
using namespace std;

//time complexity O(n*2) and space O(1), ordered is maintained.
/*
void right_rotate(int *arr,int start, int last){
    int tmp = arr[last];
    for (int i = last-1; i >=start; i--)
    arr[i+1]=arr[i];
    arr[start]=tmp;

    
    return;
}

void rearrange(int *arr, int size){
    int i=0,j=0;
    while( i < size && j< size){

        while (arr[i]<0 && i< size)
        i++;
        while (arr[j]>-1 && j< size)
        j++;

        if ( i <size && j< size)
        {
            if(i< j ){

                right_rotate(arr,i,j);
                i+=2;
                j;
            }
            
            else{

                right_rotate(arr,j+1,i);
                i++;
                j+=2;
            }
            
        }    

    }
    return;
    
}
*/


/*
//naive approach
// time complexity O(n*2) and space O(1),  and order of element is maintained.
// Naive Approach : 
// The above problem can be easily solved if O(n) extra space is allowed.
// It becomes interesting due to the limitations that O(1) extra space and order of appearances. 
// The idea is to process array from left to right. While processing, 
// find the first out of place element in the remaining unprocessed array.
// An element is out of place if it is negative and at odd index, or it is
// positive and at even index. Once we find an out of place element, we find
// the first element after it with opposite sign. We right rotate the subarray 
between these two elements (including these two).


void rearrange(int* arr, int size){
    int out_of_place=-1;
    for (int i = 0; i < size; i++)
    {
        if(out_of_place == -1){
            if((i%2==0 && arr[i]>0) || (i%2!=0 && arr[i]<0))
            out_of_place=i;
        }
        else{
            if((out_of_place%2==0 && arr[i]<0) || (out_of_place%2!=0 && arr[i]>0) ){

               right_rotate(arr,out_of_place,i);
               if(i-out_of_place>=2)
               out_of_place=out_of_place+2;
               else
               out_of_place=-1;
            }
        }
    }
    
    
    return;
}
*/


//Method-2, time complexity O(n)+O(n)=O(n) but ordered is not maintained.

void swap(int *pos1,int *pos2){
    int tmp=*pos1;
    *pos1=*pos2;
    *pos2=tmp;
    return;
}

void rearrange(int* arr, int size){
    int i=0, j;
    for(j=0; j<size; j++){
        if(arr[j]<0)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    j=0;
   while(i <size && j<size){
       if (j== i)
       break;
       else{
           if(j%2!=0 && arr[j]<0){
               swap(&arr[i],&arr[j]);
               i++;
           }
       }
       j++;
       
   }
    
    
    return;
}

int main(){
    int size;
    int *arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    rearrange(arr,size);

    cout<<"After alternating elements: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}