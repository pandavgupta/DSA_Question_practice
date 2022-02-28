// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 100

class Solution{
    public:
    void heapify( vector<pair<int,int>>&arr,int KSortedArray[][N], int n,int i ){
        int largest = i ;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;
        if( leftchild < n && KSortedArray[arr[largest].first][arr[largest].second]  > KSortedArray[arr[leftchild].first][arr[leftchild].second] ) 
            largest = leftchild;
        if( rightchild < n && KSortedArray[arr[largest].first][arr[largest].second]  > KSortedArray[arr[rightchild].first][arr[rightchild].second] )
        largest = rightchild;
        if( largest != i ){
            swap( arr[largest], arr[i] );
            heapify( arr, KSortedArray,n,largest );
        }
        
        return;
    }
    void build_heap(vector<pair<int,int>>&arr,int KSortedArray[][N], int size){
        int i=size/2-1;
        while(i>=0){
            heapify(arr,KSortedArray ,size, i);
            i--;
        }
        return;
    } 
     
     
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        pair<int,int> result;
        vector<pair<int,int>> res;
        result.first = result.second =  KSortedArray[0][0];
        for(int i=0; i<k; i++ ){
            result.first = min(result.first,KSortedArray[i][0]);
            result.second = max(result.second,KSortedArray[i][0]);
            res.push_back(make_pair(i,0));
        }
        int heap_size=k;
        build_heap(res,KSortedArray,heap_size);
        int i=1;
        int minv=result.first,maxv=result.second,diff;
        while(res[0].second<n-1){
            res[0].second++;
            maxv = max(maxv,KSortedArray[res[0].first][res[0].second]);
            heapify(res,KSortedArray ,heap_size, 0);
            minv = KSortedArray[res[0].first][res[0].second];
            if( abs(maxv - minv) < abs(result.second - result.first)  ){
            result.first = minv;
            result.second = maxv;
            }
            else if(abs(maxv - minv) == abs(result.second - result.first)  && minv < result.first ){
                        result.first = minv;
                        result.second = maxv;
                    
                }
            i++;
        }
        return result;  
    }
};

int main()
{
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
	return 0;
}
