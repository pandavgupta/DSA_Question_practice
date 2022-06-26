// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int>>sub(vector<int>& A,  vector<int>arr, int index){
        if(index >= A.size()) return {};
        vector<int>tmp2 ;
        tmp2 = arr;
        arr.push_back(A[index]);
        vector<vector<int>> yes = sub(A,arr, index+1);
        vector<vector<int>> no = sub(A,tmp2, index+1);
        
        int size {};
        if(!yes.empty()) size+=yes.size();
        if(!no.empty()) size+=no.size();
        vector<vector<int>>res(1+size);
        res[0].push_back( A[index]);
        int k=1;
        if(!yes.empty())
        for(int i = 0; i<yes.size(); i++,k++){
            for( int j=0; j<yes[i].size(); j++){
                res[k].push_back( yes[i][j]);
            }
        }
        if(!no.empty())
        for(int i = 0; i<no.size(); i++,k++){
            for( int j=0; j<no[i].size(); j++){
                res[k].push_back(no[i][j]);
            }
        }
    
        return res;
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        return sub(A,{},0);
        
    }
};

// { Driver Code Starts.

int main()
{
	int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

	return 0;
}  // } Driver Code Ends