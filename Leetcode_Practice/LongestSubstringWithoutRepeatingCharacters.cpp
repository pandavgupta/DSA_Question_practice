#include<bits/stdc++.h>
using namespace std;
//     two pointer approach:
    // int lengthOfLongestSubstring(string s) {
    //     if(!s.size()) return 0;
    //     vector<int>counter(128,-1);
    //     int maxv{};
    //     int i = 0, j = 0;
    //     while(j < s.size()){
    //         while(counter[s[j]] != -1)  counter[s[i++]] = -1;
    //         counter[s[j]] = j;
    //         j += 1;
    //         if(j-i > maxv) maxv = j-i;
    //     }
    //     return maxv;
    // }
//    Optimized two pointer approach:
int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        vector<int>counter(128,-1);
        int maxv{};
        int i = 0, j = 0;
        while(j < s.size()){
            if(counter[s[j]] >= i) i = counter[s[j]] + 1;
            counter[s[j]] = j;
            j += 1;
            if(j-i > maxv) maxv = j-i;
        }
        return maxv;
    }
int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}