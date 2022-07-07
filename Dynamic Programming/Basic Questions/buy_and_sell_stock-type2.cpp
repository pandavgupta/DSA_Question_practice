#include<bits/stdc++.h>
using namespace std;
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
class Solution {
public:
   //     valley peak method
    int maxProfit(vector<int>& prices) {
        int res{}, size = prices.size();
         for(int i=1; i<size; i++){
             if(prices[i] > prices[i-1]){
                 res+=prices[i]-prices[i-1];
             }
         }
        return res;
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.maxProfit(arr)<<endl;
    return 0;
}