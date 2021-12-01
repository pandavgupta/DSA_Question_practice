// program	to	remove	Duplicate	characters	from the String printing output in sorted manner.
//complexity is O(n) space O(1).
#include<iostream>
using namespace std;
void removeDuplicate(string &s){
    char str[128]={0};
    int index=0;
    for (int i = 0; i <=s.size(); i++)
    {
        if(str[s[i]]==0){
            s[index++]=s[i];
            str[s[i]]++;
        }

    }
    s.resize(index);

}
int main(){
    string s;
    cout<<"enter the string :";
    getline(cin,s);
    removeDuplicate(s);
    cout<<"string after removal of duplicate element :"<<s;
    return 0;
}