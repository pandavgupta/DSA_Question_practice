// program	to	remove	Duplicate	characters	from the String printing output in sorted manner.
#include<iostream>
using namespace std;
void removeDuplicate(string &s){
    char str[128]={0};
    for (int i=0; i < s.size(); i++)
       str[s[i]]++;
    s.clear();
    
    for (int i = 65; i <91; i++)
    {
       if(str[i]>=1){
           s.push_back(char(i));
           str[i]=0;
       }
       
    }
    
    for (int i = 97; i <123; i++)
    {
       if(str[i]>=1){
           s.push_back(char(i));
           str[i]=0;
       }
    }

}
int main(){
    string s;
    cout<<"enter the string :";
    getline(cin,s);
    removeDuplicate(s);
    cout<<"string after removal of duplicate element :"<<s;
    return 0;
}