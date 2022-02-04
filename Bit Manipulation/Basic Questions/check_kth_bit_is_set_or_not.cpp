#include<iostream>
// if counting start with 1th term  means last element from right is 1st term.

// Right shift
bool check_bit_set(int n, int k){
    if(n==0 || k==0)
      return false;

    // if last bit is 1 then it is odd otherwise it is even
    // if((n>>k-1)%2==0)
    //   return false;
    // else
    //   return true;


    // Bitwise AND operation with 1 will give 1 if last bit is 1 otherwise 0
    if((n>>k-1)&1)
      return true;
    else
      return false;


  

}



//left shift
// bool check_bit_set(int n, int k){
//     if(n==0 || k==0)
//       return false;

//     // Bitwise AND operation with 1 will give 1 if last bit is 1 otherwise 0
//     if((1<<k-1)&n)
//       return true;
//     else
//       return false;

// }



int main(){
   int n, k;
   std::cout<<"enter number and kth term: "; 
   std::cin>>n>>k;
   if(check_bit_set(n,k))
      std::cout<<"true ";
   else
      std::cout<<"false";

    return 0;
}