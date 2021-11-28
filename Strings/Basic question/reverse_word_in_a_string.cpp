//Given an input string s, reverse the order of the words.
// Input: s = "the sky is blue"
//Output: "blue is sky the"
// with O(1) space and string

#include<iostream>
using namespace std;

void reverse(string &s, int start, int last){
        char tmp;
        for(int i=start; i <=start+(last-start)/2; i++){
            tmp= s[i];
            s[i]=s[start+last-i];
            s[start+last-i]=tmp;
        }
    }
    string reverseWords(string s) {
        int start=0,last=0;
        while (s[start]==' ')
        start++;

        for(int j=start; j<s.size(); j++){
            if(s[j]==' ' && s[j+1]==' ' )
            continue;
                char tmp=s[last];
                s[last]=s[j];
                s[j]=tmp;
                last++; 
        }

        if(s[last-1]==' ')
        last--;
        
        s.resize(last);
        
        reverse(s,0,s.size()-1);
        start=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                 reverse(s,start,i-1);
                start=i+1;
            }
               
        }
        
        reverse(s,start,s.size()-1);
        
        return s;
        
    }

int main(){
    string s;
    cout<<"Enter your string: ";
    getline(cin,s);
    s=reverseWords(s);

    cout<<"string after reverse: "<<s;
    
    
    return 0;
}