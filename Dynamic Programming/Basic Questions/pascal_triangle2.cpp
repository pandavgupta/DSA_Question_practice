#include<iostream>
#include<vector>
using namespace std;
 void getRow(int rowIndex) {
               vector<int>curr(rowIndex+1,1);
         vector<int>prev(rowIndex+1,1);
     
        
        for(int i=0; i<=rowIndex; i++){
           if(i>1)
             prev=curr;
            for(int j=1; j<i; j++){
                curr[j]=prev[j-1]+prev[j];
            }
            
         }
    
    for (int i = 0; i <=rowIndex; i++)
    {
        cout<<curr[i]<<" ";
    }
    
    }
int main(){
    int n;
    cin>>n;
    getRow(n);
    return 0;
}