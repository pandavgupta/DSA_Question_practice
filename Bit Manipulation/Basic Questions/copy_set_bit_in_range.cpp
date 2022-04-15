#include<iostream>
using namespace std;
// copy the set bits of ‘A’ in the range ‘X’ to ‘Y’ in ‘B’ ;
// time complexity O(l-r+1)
// int copyBitsInRange(int a, int b, int x, int y)
// {
//     while(x<=y){
// 		if(a&(1<<(x-1)) && !( b& (1<<(x-1)) ) ){
// 			b = b|(1<<(x-1));
// 		}
// 		x++;
// 	}
// 	return b;
// }

// time O(1)
int copyBitsInRange(int a, int b, int x, int y)
{
	int mask_length = y-x+1;
	int mask = ((1<<mask_length)-1)<<(x-1);
	int value = mask & a;
	b= b|value;
	
	return b;
}
int main(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<copyBitsInRange(a,b,x,y)<<endl;
    return 0;
}