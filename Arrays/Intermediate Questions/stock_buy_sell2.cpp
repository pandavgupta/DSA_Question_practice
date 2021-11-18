//Buy and sell atmost 2 stock with maximum profit.
#include<iostream>
#include<algorithm>
using namespace std;


//time complexity O(N) and space O(1).

struct max_min_index
{
    int max_index=0;
    int min_index=0;
    int max_profit=0;
};


max_min_index max_profit(int *arr, int start, int last){
    max_min_index pair;
     pair.max_profit=0;
     pair.max_index=start;
     pair.min_index= start;
    for (int i = start; i < last; i++)
    {
        if(pair.max_profit < arr[i]-arr[pair.min_index]){
           pair.max_profit= arr[i]-arr[pair.min_index];
           pair.max_index = i;
        }
        else if(arr[pair.min_index] > arr[i] ){
            pair.min_index = i;
        }
        
        
    }

    return pair;

}

int stock(int *arr, int size){
    max_min_index pair1;
    int tmp1=0, tmp2=0, tmp3=0,tmp_max=0;

    pair1= max_profit(arr, 0,size);

    if(pair1.max_profit == 0)
       return 0;
    else{
        
        tmp1 = max_profit(arr,0,pair1.min_index).max_profit;

        tmp2 = max_profit(arr,0,pair1.min_index).max_profit;

        tmp_max = max(tmp1, tmp2);
        tmp1=0;
        tmp1 = max_profit(arr,pair1.min_index+1 ,pair1.max_index).max_profit; 
        tmp_max = max(tmp_max, tmp1);
        
    }
   

 return    pair1.max_profit + tmp_max;
 
}






int main(){
    int *arr, size, max=0;
    cout<<"Enter the size of array: ";
    cin>>size;
    arr= new int[size];
    cout<<"Enter the element of array: ";
    for (int i = 0; i < size; i++)
    cin>>arr[i];

    max= stock(arr, size);
    cout<<"maximum profit in buying and selling stocks is: "<<max;
 
    return 0;
}