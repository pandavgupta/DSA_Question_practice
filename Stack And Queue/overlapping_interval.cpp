// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
       if(intervals.size()==1) return intervals;
       int size = intervals.size();
        vector<vector<int>>mydata;
       sort(intervals.begin(),intervals.end());
       int prev={},first=intervals[0][0],second=intervals[0][1], position=0;
       for(int i=1; i<size; i++){
           if(second>=intervals[i][0]){
               second=max(second,intervals[i][1]);
           }
           else{
               mydata.push_back({first,second});
               first=intervals[i][0];
               second=intervals[i][1];
               position++; 
           }
           
       }
       mydata.push_back({first,second});
 
        return mydata;
    }
};

// { Driver Code Starts.
int main(){
    int n;
    cin >> n;
    vector<vector<int>>Intervals(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        Intervals[i].push_back(x);
        Intervals[i].push_back(y);
    }
    Solution obj;
    vector<vector<int>> ans = obj.overlappedInterval(Intervals);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
    }
    cout << "\n";

	return 0;
}  // } Driver Code Ends