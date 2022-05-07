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
int getMaxLen(vector<int>& nums) {
        int res{}, pos{}, neg{}, size = nums.size();
       for(int i=0; i<size; i++){
           if(nums[i]<0){
               int tmp = neg>0?neg+1:0;
               neg = pos+1;
               pos = tmp;
           }
           else if(nums[i]>0){
               pos++;
               neg = neg>0?neg+1:0;
           }
           else{
               pos=0;
               neg=0;
           }
           if(pos > res ) res = pos;
       }
        
        return res;
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.getMaxLen(arr)<<endl;
    return 0;
}