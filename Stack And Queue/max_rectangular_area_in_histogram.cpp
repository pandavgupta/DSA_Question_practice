// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    // using stack
    long long getMaxArea(long long arr[], int n)
    {
        long long maxv{};
        int left, right,length,curr;
        stack<long long>mystack;
        int i=0;
        for(i=0; i<n; i++){
            while(!mystack.empty() && arr[i]<arr[mystack.top()]){
              curr= mystack.top();
              mystack.pop();
              if(mystack.empty()) left=0;
              else left=mystack.top()+1;
              
               right = i;
              
              length= right-left;
              
              maxv=max(maxv,length*arr[curr]);
               
            }
            mystack.push(i);
        }
        while(!mystack.empty()){
              curr= mystack.top();
              mystack.pop();
              if(mystack.empty()) left=0;
              else left=mystack.top()+1;
              
              right = i;
              
              length= right-left;
              
              maxv=max(maxv,length*arr[curr]);
               
            }
        
        return maxv;
        
    }

    // brute force  
    // long long getMaxArea(long long arr[], int n)
    // {
    //     long long maxv{};
    //     int occur,j;
    //     for(int i=0; i<n;i++){
    //         occur=0;
    //         j=i+1;
    //         while( j<n && arr[i]<arr[j]){
    //             j++;
    //             occur++;
    //         }
    //         j=i;
    //         while( j>=0 &&  arr[i]<=arr[j]){
    //             j--;
    //             occur++;
    //         }
    //         maxv=max(maxv,arr[i]*occur);
    //     } 
    //     return maxv;
    // }
};


// { Driver Code Starts.

int main()
 {

    int n;
    cin>>n;
    
    long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Solution ob;
    cout<<ob.getMaxArea(arr, n)<<endl;
    

	return 0;
}
  // } Driver Code Ends