#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
  if(sr==dr && sc==dc){
      vector<string>k;
      k.push_back("");
      return k;
  }
  vector<string>res;
  vector<string>op1;
  vector<string>op2;
  vector<string>op3;
  
      for(int i=1; i+sc<=dc; i++){
          op1=get_maze_paths(sr,sc+i,dr,dc);
          for(auto it:op1)
          res.push_back("h"+to_string(i)+it);
      }

      for(int i=1; i+sr<=dr; i++){
          op1=get_maze_paths(sr+i,sc,dr,dc);
          for(auto it:op1)
          res.push_back("v"+to_string(i)+it);
      }
  
      for(int i=1,j=1; i+sr<=dr && j+sc<=dc; i++,j++){
          op1=get_maze_paths(sr+i,sc+j,dr,dc);
          for(auto it:op1)
          res.push_back("d"+to_string(i)+it);
      }
      
      return res;
  
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cout<<"Enter row and column: ";
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}