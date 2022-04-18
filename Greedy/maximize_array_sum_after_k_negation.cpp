#include<bits/stdc++.h>
using namespace std;
// time complexity O(NlogN)
long long int maximizeSum(long long int arr[], int n, int k)
    {
        long long int sum = 0;
        int i=0;
        sort(arr, arr + n);
        while(k>0){
            if(arr[i]>=0) break;
            else{
                arr[i]=-arr[i];
                k--;
                i++;
            }
        }
        for(int j=0; j<n; j++) sum+=arr[j];
        if(k>0 && k&1) {
            if(i==n) i--;
            sum-=2*arr[i];
            
        }
        return sum;
    }
// simplest solution in O(K*N)
// long long int maximizeSum(long long int arr[], int n, int k)
//     {
//         int min, index;
//         long long int sum{};
//         for(int i=0; i<k; i++){
//             min = arr[0];
//             index = 0;
//             for(int j=0; j<n; j++){
//                 if(arr[j] < min){
//                     min = arr[j];
//                     index = j;
//                 }
//             }
//             if(min == 0) break;
//             arr[index] = -arr[index];
//         }
//         for(int i=0; i<n; i++){
//             sum+=arr[i];
//         }
//         return sum;
//     }

int main(){
    int n,k;
    cin>>n>>k;
    long long int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<maximizeSum(arr,n,k);
    return 0;
}