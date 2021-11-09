#include<iostream>
using namespace std;

int min_element(int* arr, int n){
       //time complexity O(N)
       //int min=arr[n-1], i=n-2;
        // while( arr[i] <= min && i>=0){
        //     min=arr[i];
        //     i--;
        // }
        

        //time complexity O(logN)
        int low=0, high=n-1, mid, min=arr[n-1];
        if ( arr[n-1] > arr[0])
        return arr[0];
        
        while( low < high ){
            mid=(low + high)/2;
            if(mid==low)
            break;
            if( arr[mid] > min ){
                low=mid;
            }
            else if ( arr[mid] < min )
            {
               min=arr[mid];
               high=mid;
            }
            

        }
        
        return min;

}

int main(){
    
   int size,*arr,result;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   cout<<"Enter the array's element: ";
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   
   result =  min_element(arr, size);

   cout<<"minimum element in array is :"<<result;
    
    return  0;

}