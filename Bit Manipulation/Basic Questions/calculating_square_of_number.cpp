#include<iostream>
using namespace std;
int calculateSquare(int nums)
{
	if(nums < 0) nums = -nums;
	int tmp = nums, res{}, i{};
	while(1<<i <= nums){
		if(nums&(1<<i)){
			res+=nums<<i;
		}
		i++;
	}
	return res;
}
int main(){
    int n;
    cin>>n;
    cout<<calculateSquare(n);
    return 0;
}