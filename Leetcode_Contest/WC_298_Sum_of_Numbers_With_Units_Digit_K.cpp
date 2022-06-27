#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        for(int i = 1; i <= 10; i++){
            if((i*k)%10 == num%10 && i*k <= num) return i;
        }
        return -1;
    }
};
int main(){
    int n, k;
    cin >> n >> k;
    Solution obj;
    cout<<obj.minimumNumbers(n,k);
    return 0;
}