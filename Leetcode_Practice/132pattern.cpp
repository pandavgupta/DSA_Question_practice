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
    bool find132pattern(vector<int>& nums) {
       int last = nums[nums.size()-1];
        stack<int>mystack;
        mystack.push(nums[nums.size()-1]);
        for(int i =nums.size()-2; i>=0; i--){
            if(nums[i] > mystack.top()){
                if(mystack.top()==last){
                    mystack.push(nums[i]);
                }
                else{
                    last = mystack.top();
                    mystack.push(nums[i]);
                }
            }
            else if(nums[i] < last && mystack.size()>1) return true;
        }
        return false;
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.find132pattern(arr)<<endl;
    return 0;
}