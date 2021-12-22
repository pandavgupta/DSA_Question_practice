#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  
  if(sos == tar && idx == arr.size()){  //idx == arr.size() after getting result if there is zero element then we can include that .
      cout<<set<<"."<<endl;
      return;
  }
  
  if(sos>tar || idx == arr.size())
  return;
  
  string op1=set;
  op1=op1+to_string(arr[idx]);
  op1.push_back(',');
  op1.push_back(' ');
  printTargetSumSubsets(arr,idx+1,op1,sos+arr[idx],tar);
  printTargetSumSubsets(arr,idx+1,set,sos,tar);
  

}



int main() {
  int n,m;
  cout<<"Enter no of element in array: ";
  cin>>n;
 vector<int>arr(n);
 cout<<"enter elements :";
 for(int i=0; i<n ;i++)
 cin>>arr[i];
 cout<<"enter target sum: ";
 cin>>m;
 
  printTargetSumSubsets(arr,0,"",0,m);
  
  return 0;
}