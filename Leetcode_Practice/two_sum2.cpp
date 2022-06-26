#include<bits/stdc++.h>
using namespace std;
#define M  1000000009;
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
// method -1 using binary search with time complexity O(NlogN) and space O(1)
// vector<int> twoSum(vector<int>& numbers, int target) {
//        vector<int>res;
//         int start, end, mid, tmp ;
//         for(int i = 0; i < numbers.size()-1; i++){
//             tmp = target - numbers[i];
//             start = i+1;
//             end = numbers.size()-1;
//             while(start <= end){
//                 mid = start + (end - start)/2;
//                 if(numbers[mid] == tmp){
//                     res.push_back(i+1);
//                     res.push_back(mid+1);
//                     return res;
//                 }
//                 else if(numbers[mid] < tmp) start = mid + 1;
//                 else end = mid - 1;
//             }
//         }
//         return res;
        
//     }

// method -2 : using two pointer approach 
vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0, end = numbers.size()-1, sum;
    while( start < end ){
        sum = numbers[start] + numbers[end];
        if(sum == target) return {start+1, end+1};
        else if ( sum < target) start++;
        else end--;
    }
    return {};
}
int main(){
     string s;
     cin>>s;
     int k;
     cin>>k;
     vector<int>arr = getArray(s);
     vector<int>res = twoSum(arr,k);
     cout<<res[0]<<" "<<res[1];
    return 0;
}