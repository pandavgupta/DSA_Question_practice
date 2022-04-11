#include<iostream>
#include<vector>
using namespace std;
string countAndSay(int n) {
    if(n==1) return "1";
    string s = countAndSay(n-1);
    string res="";
    for(int i=0; i<s.size(); i++){
        int count{0};
        int k=i;
        while(i<s.size() && s[k]==s[i] ){count++; i++;}
        i--;
        res+=count+'0';
        res+=s[k];
    }
    return res;
}
// string countAndSay(int n) {
//     if(n == 1) return "1";
//     string s = "11";
//     for(int i=3; i<=n; i++){
//         vector<string>arr;
//         for(int j=0; j<s.size(); j++){
//             int k=j;
//             int count{0};
//             while(s[k]==s[j]){count++; j++;}
//             string tmp="";
//             tmp=to_string(count)+s[k];
//             arr.push_back(tmp);
//             j--;
//         }
//             s ="";
//         for(auto k:arr){
//             s+=k;
//         }
//     }
//     return s;
//  }
int main(){
    int n;
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}