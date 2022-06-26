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
    int maxScore(vector<int>& cardPoints, int k) {
        int sum{}, maxv{}, j = cardPoints.size()-1;
        for(int i = 0; i < k; i++) sum += cardPoints[i];
        maxv = sum;
        while(k){
            sum  = sum - cardPoints[k-- - 1] + cardPoints[j--];
            if(sum > maxv) maxv = sum;
        }
        return maxv;
    }
};
int main(){
    string s;
    int n;
    cin>>s>>n;
    vector<int>arr = getArray(s);
    Solution obj;
    cout<<obj.maxScore(arr,n)<<"\n";
    return 0;
}