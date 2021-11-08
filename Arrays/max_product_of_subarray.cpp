#include<iostream>
using namespace std;
// time complexity O(N), space complexity O(1)
long long max_product(int *arr, int n){
    long long max_prod=1,min_prod=1,max=arr[0],tmp;
	    for(int i=0; i<n; i++){
	         tmp=max_prod*arr[i];
	        
	        max_prod=max_prod*arr[i]>arr[i]?max_prod*arr[i]:arr[i];
	        if(min_prod*arr[i]>max_prod)
	        max_prod=min_prod*arr[i];
            //above three line can be written as  max_prod = max( max_prod*arr[i], arr[i], min_prod*arr[i] )
	        
	        min_prod=min_prod*arr[i]<arr[i]?min_prod*arr[i]:arr[i];
	        if(tmp<min_prod)
	        min_prod=tmp;
	        //above three line can be written as min_prod = min( min_prod*arr[i], arr[i], tmp );
	        
	        if(arr[i]==0)
	        {
	            max_prod=1;
	            min_prod=1;
	        }
	        
	        
	        if(max_prod>max)
	        max=max_prod;
	        
	        
	    }
	    return max;

}

/*
long long max_product(int *arr, int n){
    long long minVal = arr[0];
    long long maxVal = arr[0];

    long long maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] < 0)
            swap(maxVal, minVal);

        
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        maxProduct = max(maxProduct, maxVal);
    }

    return maxProduct;
}
*/

int main(){
    
   int size,*arr;
   long long result;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   cout<<"Enter the array's element: ";
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   
   result =  max_product(arr, size);

   cout<<"maximum product of subarray :"<<result;
    
    return  0;

}