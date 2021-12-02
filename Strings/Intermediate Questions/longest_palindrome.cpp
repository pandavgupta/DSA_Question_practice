#include<iostream>
using namespace std;
bool isPalindrome(string s, int start, int last){
      for(int i=start; i<=start+(last-start)/2; i++){
         if(s[i]!=s[start+last-i])
         return false;
      }
      return true;
  }
  
    string longestPalin (string S) {
        string a;
        int max_length=0;
        int max_start=0,max_end=0;
        for(int i=0; i<S.size()-1; i++){
            for(int j=S.size(); j>=i+1; j--){
             if(isPalindrome(S,i,j)){
                 if(j-i+1>max_length){
                     max_length=j-i+1;
                     max_start=i;
                     max_end = j;
                 }
             }   
            }
        }
        
        if(max_length ==0)
        a=S.substr(0,1);
        else
        a= S.substr(max_start,max_end-max_start+1);

        return a;
        
    }

int main(){
    string s;
    cout<<"enter the string :";
    getline(cin,s);
    cout<<"longest palindrome: "<<longestPalin(s);
    return 0;
}