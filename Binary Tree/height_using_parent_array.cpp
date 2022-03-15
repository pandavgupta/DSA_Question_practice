#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findHeight(int N, int arr[]){
       vector<int>ar1(N+1);
       int maxh=0;
       int h,tmp;
       for(int i=0; i<N; i++){
          if(ar1[i]!=0) continue;
          else if(arr[i]!=-1 && ar1[arr[i]]!=0){
              ar1[i]= ar1[arr[i]]+1;
              maxh = max(maxh,ar1[i]);
          }
          else {
            h=1;
            tmp = i;
            while(arr[tmp]!=-1){
                h++;
                tmp = arr[tmp];
            }
            
            maxh = max(maxh,h);
            tmp = i;
            while(true) 
            {
              ar1[tmp]= h;
              if(arr[tmp]==-1) break;
              tmp = arr[tmp];
              h--;
            } 
          }
           
       }
       return maxh-1;
    }
};


int main(){
 
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    return 0;
} 