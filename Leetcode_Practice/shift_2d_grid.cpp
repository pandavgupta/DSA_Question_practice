#include<iostream>
#include<vector>
using namespace std;
// time complexity O(n) and space complexity O(N)
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int row = grid.size();
    int col = grid[0].size();
    int size = row*col;
    int tmp{};
    vector<vector<int>>arr(row,vector<int>(col));
    for(int i=0 ; i<row; i++){
        for(int j=0; j<col; j++){
            tmp = (col*i +j+k)%(size);
            arr[tmp/col][tmp%col] = grid[i][j];
        }
    }
    return arr;
}
    // Method -1: My way
    ;
// time complexity O(n) and space complexity O(1)
//     vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
//         int col = grid[0].size();
//         int row = grid.size();
//         int size = col*row;
//         k = k%size;
//         if(k == 0 ) return grid;
//         int m = k;
//         int  tmp1;
//         vector<int>arr;
        
//         while(m>0){
//             tmp1 = size-m;
//             arr.push_back(grid[tmp1/col][tmp1%col]);
//             m--;
//         }
//         m=size-k-1;
//         while(m>=0){
//             grid[(m+k)/col][(m+k)%col] = grid[m/col][m%col];
//             m--;
//         }
//         m=0;
//         while(m<k){
//             grid[m/col][m%col] = arr[m];
//             m++;
//         }
//         return grid;
//     }
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>>arr(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    arr = shiftGrid(arr,k);
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}