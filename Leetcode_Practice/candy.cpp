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
// method-1: Brute force,   time complexity O(N^2) and space O(N) , give TLE
    // int candy(vector<int>& ratings) {
    //     vector<int>candy(ratings.size(),1);
    //     int j{};
    //     int sum = ratings.size();
    //     for(int i = 1; i < ratings.size(); i++){
    //         if(ratings[i] > ratings[i-1]){
    //             sum -= candy[i];
    //             candy[i] = candy[i-1]+1;
    //             sum += candy[i] ;
    //         }
    //         else if(ratings[i-1] > ratings[i] ){
    //            j = i-1;
    //             while(j >=0 && ratings[j] >= ratings[j+1]  ){
    //                 if(ratings[j] != ratings[j+1] && candy[j] <= candy[j+1])
    //                 {
    //                     sum -= candy[j];
    //                     candy[j] = candy[j+1]+1;
    //                     sum += candy[j];
    //                 }
    //                 else break;
    //                  j--;
    //             }
    //         }
    //     }
        
    //     return sum;
    // }
// Mehtod-2: my own using sorting, time complexity O(Nlogn) and space O(N); 
    // int candy(vector<int>& ratings) {
    //     vector<pair<int,int>>group(ratings.size());
    //     vector<int>hash(ratings.size());
    //     int index{}, value, sum{};
    //     for(int i = 0;  i < ratings.size(); i++){
    //         group[i] = {ratings[i],i};
    //     }
    //     sort(group.begin(), group.end());
    //     for(int i = 0; i < ratings.size(); i++){
    //        index = group[i].second;
    //         value = 1;
    //         if(index-1 >=0 && ratings[index] > ratings[index-1]){
    //             value = hash[index-1]+1;
    //         }
    //         if(index+1 < ratings.size() && ratings[index] > ratings[index+1])
    //             value = max(value, hash[index+1]+1);
    //         hash[index] = value;
    //         sum += value;
    //     }
    //     return sum;
    // }
// Method-3: time complexity O(N), O(N) 
     int candy(vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        vector<int>candy(ratings.size(),1);
        int sum{};
        for(int i = 1; i < ratings.size(); i++){
           if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1]+1; 
        }
        sum = candy[ratings.size()-1];
        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i], candy[i+1]+1);
            }
            sum += candy[i];
        }
        return sum;
    }
};
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.candy(arr);
    return 0;
}