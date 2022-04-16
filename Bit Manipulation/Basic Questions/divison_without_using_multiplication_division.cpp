#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
   long long divide(long long dividend, long long divisor) 
    {
        int sign = 1;
        if(dividend < 0){
            dividend = abs(dividend);
            sign=-sign;
        }
        if(divisor < 0){
            divisor = abs(divisor);
            sign =-sign;
        }
        long long  quotient{}, tmp{};
        int i=0;
        while(divisor<<i < dividend) i++;
        if(divisor<<i > dividend) i--;

        tmp = divisor<<i;
        quotient = 1<<i;
        for(int j=i-1; j>=0; j--){
            if(tmp+(divisor<<j) <= dividend){
                tmp +=divisor<<j;
                quotient|=1<<j;
            }
        }
        if(sign==-1) quotient=-quotient;
        return quotient;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}