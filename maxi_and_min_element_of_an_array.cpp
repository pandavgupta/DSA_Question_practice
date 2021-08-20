/*
Linear method:
time complexity  is O(n)
number of comparison in worst case is 2(n-1)


#include<iostream>
using namespace std;
void max_and_min(int arr[],int size){
 int min=arr[0],max=arr[0];
 for(int i=1;i< size;i++){
     if (arr[i]>max)
       max=arr[i];
     else if (arr[i]<min)
       min=arr[i];
 }
 cout<<"Max element is : "<<max<<endl;
 cout<<"Min element is : "<<min<<endl;
 
}

int main(){
    int arr[10]={0};
    int size;
    cout<<"Enter size of an array: ";
    cin>>size;
    cout<<"Enter the element in array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    max_and_min(arr,size);


    return 0;
}

 */



// Comparison  Method:  Compare in Pairs
/*
If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements
*/ 


#include<iostream>
using namespace std;
struct mypair
{
   int max;
   int min;
};


struct mypair  max_and_min(int arr[],int size){
    struct mypair MaxMin;
    int i;

    if(size%2==0){
        if(arr[0]>arr[1]){
            MaxMin.max=arr[0];
            MaxMin.min=arr[1];
        }
        else{
            MaxMin.max=arr[1];
            MaxMin.min=arr[0];
        }
         
        i=2;
    }
    else{
         MaxMin.max=arr[0];
        MaxMin.min=arr[0];
        i=1;
    }


    for(i;i<size-1;i+=2){
        if (arr[i]>arr[i+1]){
            if(arr[i]>MaxMin.max){
                MaxMin.max=arr[i];
            }
            
            if(arr[i+1]<MaxMin.min)
            MaxMin.min=arr[i+1] ;
        }

        else{
            if(arr[i+1]>MaxMin.max)
            MaxMin.max=arr[i+1];
            if (arr[i]<MaxMin.min)
            MaxMin.min=arr[i];
        } 
    }
    return MaxMin;

}
int main(){
    int arr[10]={0};
    int size;
    cout<<"Enter size of an array: ";
    cin>>size;
    cout<<"Enter the element in array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
   mypair mycom=max_and_min(arr,size);

   cout<<"Maximum element is: "<<mycom.max<<endl;
   cout<<"Minimum element is: "<<mycom.min<<endl;


    return 0;
}