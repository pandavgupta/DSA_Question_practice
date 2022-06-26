#include<bits/stdc++.h>
using namespace std;
int calPoints(vector<string>& ops) {
        vector<int>arr(ops.size());
        int size = 0;
        for(auto i:ops){
            if(i[0] == 'C' && size>0) size--;
            else if(i[0] == 'D') {arr[size] =2*arr[size-1]; size++;} 
            else if(i[0] == '+'){arr[size]=arr[size-1]+arr[size-2]; size++;}
            else {arr[size++] = stoi(i);}
        }
        int count{};
        for(int i=0; i<size; i++) count+=arr[i];
        return count;
    }

int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0; i<n; i++)
      cin>>arr[i];
    cout<<calPoints(arr);
    return 0;

}