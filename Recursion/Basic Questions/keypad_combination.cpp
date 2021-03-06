#include<iostream>
using namespace std;
string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void keypad(string ip, string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
    
    int loop=codes[stoi(ip.substr(0,1))-1].length();
    for(int i=0; i < loop;  i++ ){
      string op1=op;
      string ip1=ip;
      op1.push_back(codes[stoi(ip.substr(0,1))-1][i]);
      ip1.erase(ip1.begin()+0);
      keypad(ip1,op1);
    }
    return;
    
}
/*
for returning vector value

vector<string> keypad(string ip, vector<string> result=vector<string>(),string op=""){
    if(ip.size()==0){
        result.push_back(op);
        return result;
    }
    
    int loop=codes[stoi(ip.substr(0,1))-1].length();
    for(int i=0; i < loop;  i++ ){
      string op1=op;
      string ip1=ip;
      op1.push_back(codes[stoi(ip.substr(0,1))-1][i]);
      ip1.erase(ip1.begin()+0);
      result=keypad(ip1,result,op1) ;
    }
    return result;
    
}

*/


int main(){
    string s1;
    cout<<"Enter the string:";
    cin>>s1;
    keypad(s1,"");

    return 0;
}
