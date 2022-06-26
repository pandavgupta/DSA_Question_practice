#include<bits/stdc++.h>
using namespace std;
int divide(long long int dividend, long long int divisor) {
        if(divisor == 1) return dividend;
        else if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = 1;
        int count{};
        if(dividend < 0){
            dividend = -dividend;
            sign = -sign;
        }
        if(divisor < 0) {
            divisor = -divisor;
            sign = -sign;
        }
        while(dividend >= divisor){
            int i = 0;
            while(divisor<<(i+1) < dividend) i++;
            dividend = dividend - (divisor<<i);
            count += 1<<i;
        }
        if(sign < 0) return -count;
        return count;
    }
int main(){
    long long int n1, n2;
    cin>>n1>>n2;
    cout<<divide(n1, n2);
    return 0;
}