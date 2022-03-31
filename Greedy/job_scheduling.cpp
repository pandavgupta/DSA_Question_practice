// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool comp(const Job a, const Job b){
     return a.profit > b.profit;
 }
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       vector<int> res(2,0);
       vector<bool>extra(n,false);
       sort(arr, arr+n, comp);
       for(int i=0; i<n; i++){
           for(int j= min(n,arr[i].dead)-1; j>=0; j--){
               if(extra[j]==false){
                   res[0]++;
                   res[1]+= arr[i].profit;
                   extra[j]=true;
                   break;
               }
           }
       }
    //   for(int i=0; i < n; i++ ){
    //       if(extra[i]!=-1){
    //           res[0]++;
    //           res[1]+=arr[extra[i]].profit;
    //       }
    //   }
       
       return res;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
   
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0; 
}


  // } Driver Code Ends