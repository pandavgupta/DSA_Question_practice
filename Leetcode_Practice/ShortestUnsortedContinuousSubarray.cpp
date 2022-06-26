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
    int findUnsortedSubarray(vector<int>& nums) {
        int i=1, size = nums.size(), second, start=-1, smallest=-1, largest=-1;
        while(i<size){
            if(nums[i-1] > nums[i]) {
                if(start==-1){
                    start =i-1;
                    smallest = i;
                    largest = i-1;
                }
                else if(nums[smallest] > nums[i]) smallest =i;
                
                if(nums[i-1] > nums[largest]) largest = i-1;
                second = i-1;
            }
            i++;
        }
        if(start==-1) return 0;
        start=smallest;
        i = start;
        while(start>0 && nums[start-1]>nums[i]) start--;
        i =second+1;
        while(i<size){
            if(nums[i] >= nums[largest]) {
                i--;
                break;
            }
            i++;
        }
        if(i == size) i--;
        return i-start+1;
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.findUnsortedSubarray(arr)<<endl;
    return 0;
}