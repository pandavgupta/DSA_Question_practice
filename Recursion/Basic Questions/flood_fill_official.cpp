#include<iostream>
#include<vector>

using namespace std;
// asf -> answer so far
void floodfill(vector<vector<int>> maze, int sr, int sc, string asf) {
   
   if(sc==maze[0].size()-1 && maze.size()-1==sr){
      cout<<asf<<endl;
      return;
   }
   if (sc==maze[0].size() || maze.size()==sr)
   return;
   



  maze[0][0]=1;
  vector<vector<int>> m1=maze;
  vector<vector<int>> m2=maze;
  vector<vector<int>> m3=maze;
  vector<vector<int>> m4=maze;
  string op1=asf;
  string op2=asf;
  string op3=asf;
  string op4=asf;
  if((sr-1)>=0 && maze[sr-1][sc] ==0){
      op1.push_back('t');
      m1[sr-1][sc] =1;
      floodfill(m1,sr-1,sc,op1);
  }
  
  if((sc-1)>=0 && maze[sr][sc-1] ==0){
      op2.push_back('l');
      m2[sr][sc-1] =1;
      floodfill(m2,sr,sc-1,op2);
  }
  
   if((sr+1)<maze.size() && maze[sr+1][sc] ==0){
      op3.push_back('d');
      m3[sr+1][sc] =1;
      floodfill(m3,sr+1,sc,op3);
  }
  
   if((sc+1)<maze[0].size() && maze[sr][sc+1] ==0){
      op4.push_back('r');
      m4[sr][sc+1] =1;
      floodfill(m4,sr,sc+1,op4);
  }
   return;
  
}


int main() {
  int n, m;
  cout<<"Enter row and column: ";
  cin >> n >> m;
  cout<<"Enter 2d array:";
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  cout<<"result:"<<endl;
  floodfill(arr, 0, 0, "");
}