#include<iostream>

bool isPower_two(int n){
  if(n<=0)
    return false;
    
   return ( n&(n-1))==0;

//   n= n&(n-1);
//   if(n==0)
//      return true;
//   else
//      return false;

}


int main(){
    int n;
    std::cout<<"enter number: ";
    std::cin>>n;
    if(isPower_two(n))
      std::cout<<"true";
    else 
      std::cout<<"false";


    return 0;
}