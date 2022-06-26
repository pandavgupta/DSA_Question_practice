#include<iostream>
#include<vector>
using namespace std;
void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        int count{};
        vector<vector<int>>arr(board);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                count =0;
                if(j>0){ 
                    count+=arr[i][j-1];
                    if(i < row-1) count+=arr[i+1][j-1];
                    if(i > 0 ) count+=arr[i-1][j-1];
                }
                if(j < col-1){
                    count+=arr[i][j+1];
                    if( i > 0) count+=arr[i-1][j+1];
                    if( i < row-1) count+=board[i+1][j+1];
                }
                if(i < row-1) count+=arr[i+1][j];
                if(i > 0) count+=arr[i-1][j];
                if(board[i][j]){
                    if(count==2 || count==3) continue;
                    else board[i][j]=0;
                }
                else if(count == 3 ) board[i][j] = 1;
                
            }
        }
    }
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    gameOfLife(arr);
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}