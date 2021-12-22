#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> chess){
  for (int i = 0; i < chess.size(); i++)
  {
      for (int j = 0; j < chess[0].size(); j++)
      {
          cout<<chess[i][j]<<" ";
      }
      cout<<endl;
  }
  
}

bool isSafe(string s,int row, int col){
    for(int i=2; i< 5*row; i=i+5){
        if(stoi(s.substr(i,1))==col)
        return false;
    }
    for(int i=0; i< 5*row; i=i+5){
        int r=stoi(s.substr(i,1));
        int c=stoi(s.substr(i+2,1));
        int diff=row-r;
        if(c-diff==col || c+diff==col )
        return false;
    }
    
    return true;
}


void printNQueens(vector<vector<int>> chess, string qsf, int row) {

 if(row==chess.size()){
     cout<<qsf<<"."<<endl;
     display(chess);
     return;
 }
  
 for(int i=0; i<chess.size(); i++){
    if(isSafe(qsf,row,i)){
        vector<vector<int>> tk=chess;
        tk[row][i]=1;
        string op1=qsf;
        op1=op1+to_string(row)+"-"+to_string(i)+", ";
        printNQueens(tk,op1,row+1);
    }
    
 }

}



int main() {
  int n;
  cout<<"enter n:";
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n));

  printNQueens(chess, "", 0);
  

}
