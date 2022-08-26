#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> digit_freq_table(int n){
        int digit{};
        vector<int>res(11);
        while(n){
            res[n%10]++;
            n /= 10;
            digit++;
        }
        // At position 10 , we are storing it's number of digit
        res[10] = digit;
        return res;
    }
    bool compare_number(vector<int>&num_freq_table, int n, int start, int end){
        for(int i = start; i <= end; i++){
            long num_test = 1L<<i;
            vector<int>test_hash = digit_freq_table(num_test);
            bool flag = true;
            for(int i = 0; i < 10; i++){
                if(test_hash[i] != num_freq_table[i]){ flag = false; break;}
            }
            if(flag) return true;
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        if(n < 10) return (n&(n-1)) == 0;
        vector<int>num_freq_table = digit_freq_table(n);
        int incr = 2, digit = num_freq_table[10];
        vector<int>starting_power(digit+1);
        for(int i = 1; i <= digit; i++){
            if(incr == 2) {
                incr = 0;
                starting_power[i] = starting_power[i-1]+4;
            }
            else{
                incr++;
                starting_power[i] = starting_power[i-1]+3;
            }
        }
        return compare_number(num_freq_table, n, starting_power[digit-1], starting_power[digit]-1);
        
    }
};
int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.reorderedPowerOf2(n)<<endl;
    return 0;
}