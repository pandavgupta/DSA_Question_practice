// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>arr2(n,-1);
        stack<long long >mystack;
        for(int i=0; i<n; i++){
                while( !mystack.empty() && arr[i]>arr[mystack.top()]){
                    arr2[mystack.top()]=arr[i];
                    mystack.pop();
                }
            mystack.push(i);
        }
        
        return arr2;
    }
};

// { Driver Code Starts.

int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    Solution obj;
    vector <long long> res = obj.nextLargerElement(arr, n);
    for (long long i : res) cout << i << " ";
    cout<<endl;

	return 0;
}  // } Driver Code Ends