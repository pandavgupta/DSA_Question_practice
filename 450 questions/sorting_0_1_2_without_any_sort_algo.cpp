#include<iostream>
using namespace std;
int main(){
    int arr[]={0,1,2,1,0,2,0,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    int count1=0,count0=0,count2=0;
    for (int i = 0; i <size; i++)
    {
        if(arr[i]==0)
        count0++;
        else{
            if (arr[i]==1)
                count1++;
            else
            count2++;
        }
    }
    for (int i = 0; i < size; i++)
    {
       if (i<count0)
        arr[i]=0;
        else {
            if (i>=count0 && i<count0+count1)
            arr[i]=1;
          else
            if (i>=count0+count1)
          arr[i]=2;
            
        }
        
    }
    for (int i = 0; i < size; i++)
    {
     cout<<arr[i]<<" ";
    }
    
    

    
return 0;
    
}