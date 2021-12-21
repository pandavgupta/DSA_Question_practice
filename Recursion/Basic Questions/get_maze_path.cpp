#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sc==dc && sr==dr){
        vector<string>k;
        k.push_back("");
        return k;
    }
    vector<string>res;
    vector<string>op1;
    vector<string>op2;
    if(sc<dc){
        op1=getMazePaths(sr,sc+1,dr,dc);
        for(auto it:op1)
        res.push_back("h"+it);
    }
    if(sr<dr){
        op2=getMazePaths(sr+1,sc,dr,dc);
        for(auto it:op2)
        res.push_back("v"+it);
    }
    
    return res;

}


void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m;
    cout<<"Enter row and column: ";
     cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}