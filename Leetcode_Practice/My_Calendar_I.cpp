#include<bits/stdc++.h>
using namespace std;
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;
    if(s[i] == ',') i++;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
class MyCalendar {
public:
// instead of set of pair we can use map
    set<pair<int,int>>myset;
    MyCalendar() {
        myset = set<pair<int,int>>();
    }
    
    bool book(int start, int end) {
        auto it = myset.lower_bound({start,end});
        if(it != myset.end() && it->first < end) return false;
        if(it != myset.begin() && start < (--it)->second) return false;
        // implementing own binary search and checking any overlapping without using lower_bound
        // int low = 0, high = myset.size()-1, mid = 0;
        // set<pair<int,int>>::iterator it = myset.begin();
        // while(low <= high){
        //     mid = (low + high)/2;
        //     it = next(myset.begin(), mid);
        //     if(end <= it->first ) high = mid-1;
        //     else if(start >= it->second) low = mid+1;
        //     else return false;
        // }
        myset.insert({start, end});
        return true;
    }
};

int main(){
    string s, s2;
    cin>>s>>s2;
    stringstream instruction(s.substr(1,s.size()-2)), data_array(s2.substr(1,s2.size()-2));
    string inst, data;
    getline(instruction,inst,',');
    getline(data_array, data,']');
    MyCalendar obj;

    while(getline(instruction, inst, ',')){
        getline(data_array, data, ']');
        vector<int>tmp = getArray(data);
        if(obj.book(tmp[0], tmp[1])) cout<<"True ";
        else cout<<"False ";
    }
    cout<<endl;
    return 0;

    return 0;
}