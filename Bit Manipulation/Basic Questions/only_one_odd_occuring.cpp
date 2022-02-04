#include<iostream>
#include<vector>
int one_odd_occuring(std::vector<int>arr,int n){
    int tmp{};
    for (int i = 0; i < n; i++)
      tmp ^=arr[i];
    return tmp;   
}


int main(){
    int n;
    std::cout<<"enter size: ";
    std::cin>>n;
    std::vector<int>arr(n);
    for (int i = 0; i < n; i++)
      std::cin>>arr[i];
    
    std::cout<<one_odd_occuring(arr,n);
    return 0;
}