#include<iostream>
int table[256];
//method 3 with constant time - O(8)
void initialize(){
    table[0]=0;
    for (int i = 1; i < 256; i++)
    {
       table[i]= (i&1)+ table[i/2];
    }
    
}
int check_bit_set(int n){
    initialize();
    int res{};
    // for 64 bit platform
    for (int i = 0; i < 8; i++)
    {
        // n & 0xff is Bitwise AND operation of n with last 8 bits of n.
        res=res+ table[(n & 0xff)];
        n=n>>8;
    }
    return res;

}



// method 1 and 2
// int check_bit_set(int n){
//    int count{};
//    // method 1 , complexity is O(n) where n is number of bits in number
//     // while(n>0){
//     //     if(n&1)
//     //      count++;
//     //     n=n>>1;
//     // }
    
//  // method 2 complexity is O(n) where n is number of set bits
//  //Brian and kerningham algorithm
//     while(n>0){
//         n=n&(n-1);
//         count++;
//     }
//     return count;
   

// }





int main(){
   int n;
   std::cout<<"enter number and kth term: "; 
   std::cin>>n;
   std::cout<<check_bit_set(n
   );
    return 0;
}