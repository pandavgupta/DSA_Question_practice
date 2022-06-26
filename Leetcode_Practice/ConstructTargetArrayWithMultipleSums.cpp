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
bool isPossible(vector<int>& target) {
    priority_queue<int>pqueue(target.begin(), target.end());
    long long total_sum{};
    int size = target.size(), largest{},elem{};
    for(int i = 0; i < size; i++) total_sum += target[i];
    while(true){
        largest = pqueue.top();
        pqueue.pop();
        total_sum -= largest;
        if(largest == 1 || total_sum == 1) return true;
        if(largest <= total_sum || total_sum == 0 || largest % total_sum == 0) return false;
        elem = largest  % total_sum;
        total_sum += elem;
        pqueue.push(elem);  
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    vector<int>arr = getArray(s);
    if(isPossible(arr)) cout<<true;
    else cout<<false;
    return 0;

}