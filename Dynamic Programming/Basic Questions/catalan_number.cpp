#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


class Solution
{
    public:
    //Function to find the nth catalan number.
    // method-1: memoization
    // vector<cpp_int>dp;
    // cpp_int helper(int n){
    //    if(n == 0 || n == 1) return 1;
    //    if(dp[n] != -1) return dp[n];
    //    cpp_int res{};
    //    for(int i = 0, j = n-1 ; i <=n -1; i++)
    //        res += helper(i)*helper(j--);
    //     return dp[n] = res;
    // }
    // cpp_int findCatalan(int n) 
    // {
    //     dp = vector<cpp_int>(n+1,-1);
    //     return helper(n);
    // }

    // method-2: using tabulation with time complexity O(N^2) and space O(N)
    // cpp_int findCatalan(int n) 
    // {
    //     vector<cpp_int>dp(n+1,0);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     cpp_int ans{};
    //     int j{},k{};
    //     for(int i = 2; i <= n; i++){
    //         ans = 0;
    //         j = 0;
    //         k = i-1;
    //         while(j <= i-1){
    //             ans += dp[j++]*dp[k--];
    //         }
    //         dp[i] = ans;
    //     }
    //     return dp[n];
        
    // }
    // method-3: using formula, time complexity O(N), space complexity(1)
    cpp_int findCatalan(int n) 
    {
        // vector<cpp_int>dp(n+1,0);
        cpp_int ans = 1;
        for(int i = 1; i <= n; i++){
            ans *=(4*i-2);
            ans /= (i+1);
        }
        return ans;
        
    }

};

int main() 
{
    int n;
    cin>>n;
    Solution obj;
    cout<< obj.findCatalan(n) <<"\n";    
	return 0;
} 