#include<iostream>
using namespace std;

void maze_path(int dr,int dc,int sr=1,int sc=1,string op=""){
  if(dr==sr && dc ==sc){
      cout<<op<<" ";
      return;
  }
  if(sc>dc || sr>dr)
  return;
  string op1=op;
  string op2=op;
  op1.push_back('h');
  op2.push_back('v');
  maze_path(dr,dc,sr+1,sc,op1);
  maze_path(dr,dc,sr,sc+1,op2);
  return;

}

int main(){
    int row,col;
    cout<<"Enter the destination row : ";
    cin>>row;
    cout<<"Enter the destination column: ";
    cin>>col;
    maze_path(row,col);
    return 0;

}