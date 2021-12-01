#include<iostream>
using namespace std;



bool string_interleaving(string s1,string s2,string s3){
    if(s3.size()!= s1.size()+s2.size())
      return false;
    int j=0,k=0;
    for (int i = 0; i < s3.size(); i++)
    {
        if(s1[j]=s3[i]){
            j++;
        }
        else if(s2[k]=s3[i]){
            k++;
           }
        else{
            return false;
        }
    }


    return true;

}

int main(){
    string s1,s2,s3;
    cout<<"Enter string 1 :";
    getline(cin,s1);
    cout<<"Enter string 2 :";
    getline(cin,s2);
    cout<<"Enter string 3 :";
    getline(cin,s3);
    if(string_interleaving(s1,s2,s3))
    cout<<"yes";
    else
    cout<<"NO";
    return 0;

}