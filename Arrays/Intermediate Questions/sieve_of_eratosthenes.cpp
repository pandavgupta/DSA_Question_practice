#include<iostream>
using namespace std;

void isPrime(int size){
    int arr[size+1]={0};
    int j;
    arr[0]=1;
    arr[1]=1;
    cout<<"array :";
    for (int i = 0; i <=size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    for (int i = 2; i*i<=size; i++)
    {
        for (int j=2*i; j<=size;j+=i)
        {  
            if(!arr[j])
            arr[j]=1;
        }
        
    }

    cout<<"Prime number are: ";
    for (int i = 2; i <=size; i++)
    {
        if (!arr[i])
        cout<<i<<" ";
    }
    
    return;
}

int main(){
    int size;
    cout<<"Enter the last number till which you want to find the prime number : ";
    cin>>size;
    isPrime(size);
    return 0;
}