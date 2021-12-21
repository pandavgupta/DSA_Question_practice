#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> getKPC(string s) {
    
 string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

if(s.size()==0){
        vector<string>k;
        k.push_back("");
        return k;
    }
vector<string>res,prev;

    prev=getKPC(s.substr(0,s.size()-1));

    int t=prev.size();
    
    for(int i=0;i<t; i++ ){
        
        
        int k=codes[stoi(s.substr(s.size()-1,1))].length();
        
        for(int j=0;j<k;j++){    
             string tmp=prev[i];
            tmp.push_back(   codes[  stoi( s.substr(s.size()-1,1)) ][j]  );
            res.push_back( tmp);
        }
        
        
    }
   
   
   return res;



}


int main() {
  string s;
  cout<<"Enter the number: ";
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;
  cout<<"Output is: ";
  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}