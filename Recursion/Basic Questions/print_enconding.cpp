#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
   
   if(str.size()==0){
       cout<<asf<<endl;
       return;
   }
   if(str[0]=='0')
     return;
    int i=1;
    while (i<=str.size() && stoi(str.substr(0,i)) <= 26)
    {
        string ip=str;
        string op=asf;
        char t=stoi(str.substr(0,i)) +96;
        op.push_back(t);
        ip=str.substr(i);
        printEncoding(ip,op);
        i++;    }
    
    
    
}

int main(){
    string str;
    cout<<"Enter the value:";
    cin>>str;
    printEncoding(str,"");
    
}