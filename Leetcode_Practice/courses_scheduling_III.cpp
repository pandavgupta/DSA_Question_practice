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
// method -1 : Recursive + memorization
// bool cmp(vector<int>&a, vector<int>&b){
//     if(a[1] == b[1]) return (a[1]-a[0]) <= (b[1]-b[0]);
//     else return a[1] < b[1];
// } 
// unordered_map<int,unordered_map<int,int>>dp;
//     int helper(vector<vector<int>>& courses, int i, int total_duration){
//         if(i == courses.size()) return 0;
//         if(dp.find(i) != dp.end() && dp[i].find(total_duration) != dp[i].end()) return dp[i][total_duration];
//         int taken{}, not_taken{};
//         if(courses[i][0]+total_duration <= courses[i][1]){
//                     taken = 1+ helper(courses, i+1,total_duration+courses[i][0]);
//             }
//         not_taken = helper(courses, i+1, total_duration);
//         return dp[i][total_duration] = max(taken, not_taken);
//     }
//     int scheduleCourse(vector<vector<int>>& courses) {
//         sort(courses.begin(), courses.end(), cmp);

//         return helper(courses, 0, 0);
//     }
// method -2 greedy:
bool cmp(vector<int>&a, vector<int>&b){
         return a[1] < b[1];
    } 
int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int>pqueue;
        int count{}, total_duration{};
        for(int i = 0; i < courses.size(); i++){
            if(courses[i][0] + total_duration <= courses[i][1]){
                total_duration += courses[i][0];
                pqueue.push(courses[i][0]);
            }
            else if(!pqueue.empty() && pqueue.top() > courses[i][0]){
                    total_duration -= pqueue.top();
                    total_duration += courses[i][0];
                    pqueue.pop();
                    pqueue.push(courses[i][0]); 
                    
            }
        }
        return pqueue.size();

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
    cout<<scheduleCourse(arr);
    return 0;
}