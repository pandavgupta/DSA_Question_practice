#include<bits/stdc++.h>
using namespace std;
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
class Solution {
public:
    int ans;
    void helper(vector<int>&cookies, vector<int>& person, int index, int local_max){
        if(index == cookies.size()){
            ans = min(ans,local_max);
            return;
        }
        if( local_max > ans) return;
        for(int i = 0; i < person.size(); i++){
            if(i > 0 && person[i-1] == person[i]) continue;
            person[i] += cookies[index];
            helper(cookies, person, index+1, max(local_max,person[i]));
            person[i] -= cookies[index];
        }
        return ;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>person(k, 0);
        ans = 1e9;
        helper(cookies, person, 0, -1e9);
        return ans;
    }
};
int main(){
    string s;
    int n;
    cin>>s>>n;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.distributeCookies(arr, n);
    return 0;
}