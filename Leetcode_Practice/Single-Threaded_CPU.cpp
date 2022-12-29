#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>order_tasks(tasks.size());
        for(int i = 0; i < tasks.size(); i++) order_tasks[i] = {tasks[i][0], i};
        sort(order_tasks.begin(), order_tasks.end());
        auto compare = [&](int &a, int &b){
        if(tasks[a][1] == tasks[b][1]) return a > b;
        return tasks[a][1] > tasks[b][1];
       };
        priority_queue<int, vector<int>,decltype(compare)>pq(compare);
        vector<int>res;
        int i = 0;
        long long upper = order_tasks[0][0];
        while(i < order_tasks.size() || !pq.empty()){
            while( i < order_tasks.size() && order_tasks[i][0] <= upper){
                pq.push(order_tasks[i++][1]);
            }
            if(!pq.empty()){
                upper += tasks[pq.top()][1];
                res.push_back(pq.top());
                pq.pop();
            }
            else upper = order_tasks[i][0];
        }
        return res;
    }
};
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

int main(){
    string s;
    cin>>s;
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
    auto res = obj.getOrder(arr);
    
    for(auto i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}