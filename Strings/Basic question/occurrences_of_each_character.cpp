// a	program	to	count	the	number	of	occurrences	of	each	character	
// in	the	string	and	print	it.	

#include<iostream>
using namespace std;

int main(){
    int arr[128]={0};
    int max_length=100,tmp=0;
    char value[max_length];
    cout<<"Enter the string: ";
    cin.getline(value, max_length);

    for (int i = 0; value[i] !=0 ; i++)
    {  
        arr[int(value[i])]++;
    }

    for (int i = 0; i <=127; i++)
    {    
        if(arr[i]>0)
        cout<<char(i)<<": "<<arr[i]<<endl;
    }
    
    return 0;
}