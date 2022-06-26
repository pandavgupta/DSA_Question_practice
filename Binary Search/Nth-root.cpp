#include<bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m)
{
    if(n == 1 || m == 1) return m;
    long long int start = 1, end = m/2, mid, prod=1;
    while(start <= end){
        mid = start + (end-start)/2;
        prod = pow(mid,n);
        if(prod == m) return mid;
        else if(prod > m || prod < 0) end = mid-1;
        else start = mid+1;
    }
    return -1;
}  
int main(){
    int n, m;
    cin>>n>>m;
    cout<<NthRoot(n,m);
    return 0;
}