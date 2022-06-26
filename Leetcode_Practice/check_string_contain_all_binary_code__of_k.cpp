#include<iostream>
#include<unordered_set>
using namespace std;
bool helper(unordered_set<string>& myset, string output, int i){
    if(i == output.size()) return true;
    
    string output2 = output;
    output2[i] = '1';
    if(myset.find(output2) == myset.end()) return false;
    
    return helper(myset, output2, i+1) && helper(myset, output, i+1);
}
bool hasAllCodes(string s, int k) {
    if( k > s.size()) return false;
    unordered_set<string> myset;
    int i = 0;
    while( i <= s.size()-k ){
        myset.insert(s.substr(i,k));
        i++;
    }
    string output(k,'0');
    if(myset.find(output) == myset.end()) return false;
    return helper(myset, output, 0 );
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    if(hasAllCodes(s,k)) cout<<"True";
    else cout<<"False";
    return 0;
}
