#include<iostream>
using namespace std;



bool string_interleaving(string s1,string s2,string s3){
    string first,second;
    int i=0,j=0;

    if(  s3.size()  !=  s1.size()+s2.size() )
    return false;


    if( s3[0]==s1[0] || s3[0]==s2[0]){
        if(s2[0]==s1[0]){
            i++;
            j++;
            while(s1[i]==s2[j]){
                i++;
                j++;
            }
               
                                if( s3.substr(0,i+1)==s1.substr(0,i+1) ){
                                  string first=s1;
                                   string second=s2;

                                }
                                else{
                                   string first=s2;
                                   string second= s1;

                                }
            

        }
        else if(s3[0]==s1[1]){
           string first= s1;
           string second= s2;

        }
        else{
          string first=s2;
          string second=s1;

        }
    }
    else
        return false;


   j=0;
   int k=0;
    for (int i = 0; i < s3.length(); i++){
        if( s3[i] != first[j] )
        return false;
        while (first[i]==s3[i])
        {
            i++;
            j++;
        }
        if(second[k]!=s3[i])
        return false;
        while (second[i]==s3[i])
        {
            i++;
            k++;
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