#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>res;
        int start = 0, end = 0;
        int turn_stamp = -1, total_stamp{};
        while(turn_stamp){
            turn_stamp = 0;
            for(start = 0, end = stamp.size()-1; end < target.size(); start++, end++){
                int no_axt{};
                bool flag = true;
                for(int i = start, j= 0 ; i <=end; i++, j++){
                    if(stamp[j]!= target[i] && target[i] != '?'){
                        flag = false;
                        break;
                    }
                    else if(target[i] == '?') no_axt++;
                }
                if(no_axt != stamp.size() && flag){
                    res.push_back(start);
                    for(int i = start; i <= end; i++){
                        if(target[i] != '?'){
                            target[i] = '?';
                            turn_stamp++;
                        }
                    }
                    start += stamp.size()-1;
                    end += stamp.size()-1;
                    
                    }
            }
            total_stamp += turn_stamp;
        }
        if(total_stamp != target.size()) return {};
        int size = res.size(), last_index = size-1;
        for(int i = 0; i < size/2; i++){
            swap(res[i], res[last_index-i]);
        }
        return res;
    }
};

int main(){
    string s1, s2;
    cin>>s1>>s2;
    s1 = s1.substr(1,s1.size()-2);
    s2 = s2.substr(1, s2.size()-2);
    Solution obj;
    vector<int>arr = obj.movesToStamp(s1, s2);
    for(auto i:arr) cout<<i<<" ";
    cout<<"\n";
    return 0;
}