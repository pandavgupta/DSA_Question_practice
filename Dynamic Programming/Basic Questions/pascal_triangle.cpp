#include<iostream>
#include<vector>
using namespace std;
void generate(int numRows) {
        vector<vector<int>>dp(numRows);
        for(int i=0; i<numRows; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i)
                    dp[i].push_back(1);
                else
                    dp[i].push_back(dp[i-1][j-1]+dp[i-1][j]);
                
            }
        }
       for (int i = 0; i <numRows ; i++)
       {
           for (int j = 0; j < dp[i].size(); j++)
           {
              cout<<dp[i][j]<<" ";
           }
           cout<<endl; 
       }
      
       
    }
int main(){
    int n;
    cin>>n;
    generate(n);
    return 0;
}