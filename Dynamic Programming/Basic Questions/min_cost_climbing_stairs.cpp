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
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int i{};
        for(i=2; i<n; i++){
            cost[i]+= min(cost[i-2],cost[i-1]);
        }
        return min(cost[i-2],cost[i-1]);
    }
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    cout<<minCostClimbingStairs(arr);
    return 0;
}