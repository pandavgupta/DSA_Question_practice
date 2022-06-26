#include<iostream>
#include<vector>
using namespace std;
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n-1;
        int up = 0;
        int down = n-1;
        int count=1;
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0; i<n/2; i++){
            for(int k=left; k<=right; k++ ) arr[left][k]=count++;
            up++;
            for(int k=up; k<=down; k++ ) arr[k][down]=count++;
            right--;
            for(int k=right; k>=left; k-- ) arr[right+1][k]=count++;
            down--;
            for(int k=down; k>=up; k--) arr[k][up-1]=count++;
            left++;
        }
        for(int k=left; k<=right; k++ ) arr[left][k]=count++;
        return arr;
            
    }
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr = generateMatrix(n);
    for(auto i:arr){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}