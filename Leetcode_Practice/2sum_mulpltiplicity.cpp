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
int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        long count{};
        int second =0;
        int third  =0;
        // long M = 1e9+7;
        for(int i=0; i<size; i++){
            int tmp = target-arr[i];
            int j=i+1, l = size-1;
            
            while(j<l){
                if(arr[j]+arr[l] < tmp) j++;
                else if(arr[j]+arr[l] > tmp) l--;
                else if(arr[l]!=arr[j]){
                    second=1;
                    third=1;
                    while( j+1<l && arr[j]==arr[j+1]){second++; j++;}
                    while(j<l-1 && arr[l]==arr[l-1]){third++; l--;}
                    count+=(second*third);
                    count = count%M;
                    j++;
                    l--;
                }
                else{
                    count+= (l-j+1)*(l-j)/2;
                    count = count%M;
                    break;
                }
            }
        }
        return count;
    }
int main(){
     string s;
     cin>>s;
     int k;
     cin>>k;
     vector<int>arr = getArray(s);
     cout<<threeSumMulti(arr,k);
    return 0;
}