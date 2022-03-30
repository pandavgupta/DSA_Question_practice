// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int, int>>data(n);
       for(int i=0; i<n; i++){
           data[i].first = end[i];
           data[i].second = start[i];
       }
       sort(data.begin(),data.end());
       int last =data[0].first;
       int count=1;
       for(int i=1; i<n; i++){
           if( data[i].second > last) {
               count++;
               last = data[i].first;
           }
       }
     
     return count;  
    }
};

// { Driver Code Starts.
int main() {

        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    return 0;
}  // } Driver Code Ends