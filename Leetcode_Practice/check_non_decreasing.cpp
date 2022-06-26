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
bool checkPossibility(vector<int>& nums) {
    int flag = -1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < nums[i-1] ) {
            int tmp = 0;
            if(i+1 < nums.size() && nums[i+1] < nums[i-1]) tmp++;
            if(i-2 >= 0 && nums[i-2] > nums[i] ) tmp++;
            if(tmp == 0 ) flag++;
            else flag += tmp;
        }
        if(flag >= 1) return false;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    if(checkPossibility(arr)) cout<<"true";
    else cout<<"false";
    return 0;
}