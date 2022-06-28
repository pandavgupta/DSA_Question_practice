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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long >connection(n,0);
        for(int i = 0; i < roads.size(); i++){
            connection[roads[i][0]] += 1;
            connection[roads[i][1]] += 1;
        }
        sort(connection.begin(), connection.end());
        long long int sum{};
        long long  k = n;
        while(n){
            sum += connection[n-1]*n;
            n--;
        }
        return sum;
    }
};
int main(){
    string s;
    int n;
    cin>>n>>s;
    vector<vector<int>>arr;
     for(int i = 0 ; i < s.size(); i++){
        if(s[i]=='['){
            i++;
            if(s[i] == ',') i++;
            string tmp ;
            while(s[i] != ']') tmp.push_back(s[i++]);
            tmp.push_back(s[i]);
            arr.push_back(getArray(tmp));
            if(s[i+1] == ']') break;
            s[i] = '[';
            i--;
        }
    }
    Solution obj;
    cout<<obj.maximumImportance(n,arr);
    return 0;
}