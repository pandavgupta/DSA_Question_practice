#include<iostream>
using namespace std;
bool backspaceCompare(string s, string t) {
        int i = s.size(), j = t.size();
        int skipS = 0, skipT = 0;
        while( i >=0 || j>=0 ){
            while( i>=0 ){
                if(s[i]=='#'){ skipS++; i--;}
                else if( skipS > 0 ){skipS--; i--;}
                else break;
            }
            while( j>=0 ){
                if(t[j]=='#'){ skipT++; j--;}
                else if( skipT > 0 ){skipT--; j--;}
                else break;
            }
            
            if( i>=0 && j>=0 && s[i]==t[j] ){
                    i--;
                    j--; 
                    continue;
            }
            else if( i<0 && j<0) continue;
            else return false;
        }
        return true;
    }
int main(){
    string s,t;
    cin>>s>>t;
    if(backspaceCompare(s, t)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}