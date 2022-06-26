#include<bits/stdc++.h>
using namespace std;
  int numRescueBoats(vector<int>& people, int limit) {
        int start{}, end{}, count{};
        end = people.size()-1;
        sort(people.begin(), people.end());
        while(start<=end){
            while(start<end && people[start]+people[end]>limit)
               { end--;
                 count++;}
            start++;
            end--;
            count++;
        }
        return count;
    }
int main(){
    int n,limit;
    cin>>n;
    vector<int>arr(n);
    for(int i  =0; i<n; i++)
      cin>>arr[i];
      cin>>limit;
    cout<<numRescueBoats(arr,limit);
    return 0;
}