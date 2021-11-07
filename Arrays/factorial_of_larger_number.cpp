#include<iostream>
#include<vector>
using namespace std;

//complexity O(n^2) 
vector<int> factorial_largest_number(int number){
    vector<int>arr;
    arr.push_back(1);
    int carry=0;
    for (int i = 2; i <=number; i++)
    {
        for(int j=arr.size()-1; j>=0;j--)
        { 
            arr[j]=arr[j]*i+carry;
            carry=arr[j]/10;
            arr[j]=arr[j]%10;
        }
        while(carry){
                arr.insert(arr.begin(),carry%10);
                carry=carry/10;
            }
    }
    
   return arr;
}

int main(){
    
   int number;
   vector<int>v1;
   cout<<"Enter the number : ";
   cin>>number;
   v1 = factorial_largest_number(number);

   cout<<"Factorial of "<<number<<" :";
   for (auto it:v1)
   {
       cout<<it;
   }
   
    
    return  0;

}