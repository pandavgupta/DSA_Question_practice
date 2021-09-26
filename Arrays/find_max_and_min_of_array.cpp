#include<iostream>
#include<vector>
using namespace std;

struct Pair
{
    int min;
    int max;
};


struct Pair get_max_min(vector<int> &arr,int size)
{    
    int i=1;
    struct Pair max_min;
    if( size%2 == 0 ) 
    {
        if( arr[1] > arr[0] )
        {
           max_min.max=arr.at(1);
           max_min.min=arr.at(0);
        }
        else
        {
            max_min.max=arr.at(0);
            max_min.min=arr.at(1);
        }

        i=2;


    }

    else
    {
        max_min.max=arr.at(0);
        max_min.min=arr.at(0);
    }

    while ( i< size-1 )
    {
        if( arr.at(i+1) > arr.at(i) )
        {
            if( arr.at(i+1) > max_min.max)
            max_min.max=arr.at(i+1);

            if( arr.at(i) < max_min.min )
            max_min.min=arr.at(i);
        }
        else
        {
            if( arr.at(i) > max_min.max)
            max_min.max=arr.at(i);

            if( arr.at(i+1) < max_min.min )
            max_min.min=arr.at(i+1);
        }
        i++;
    }
    

    return max_min;


}


int main()
{
    int size,tmp;
    vector<int> arr;
    cout<<"Enter the size of array: ";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    struct Pair max_min=get_max_min(arr,size);

    cout<<"Maximum element of array is : "<<max_min.max<<endl;
    cout<<"Minimum element of array is : "<<max_min.min<<endl;



    return 0;
}