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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>heap;
        int count{}, index{}, maxReach = startFuel;
        while(index < stations.size()){
            while(index < stations.size() && stations[index][0] <= maxReach)
                heap.push(stations[index++][1]);
            if(heap.empty() || maxReach >= target) break;
            maxReach += heap.top();
            heap.pop();
            count++;
        }
        while(maxReach < target && !heap.empty()) maxReach += heap.top(), heap.pop(), count++;
        return maxReach >= target ? count : -1;
    }
};
int main(){
    int target, startFuel;
    string s;
    cin>>target>>startFuel;
    cin>>s;
    vector<vector<int>>stations;
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp,']')){
    if(tmp.size()==1 || tmp.size()==0) continue;
    tmp = tmp.substr(2);
    vector<int>a = getArray(tmp);
    stations.push_back(a);
    }
    Solution obj;
    cout<<obj.minRefuelStops(target, startFuel, stations);
    cout<<endl;
    return 0;
}