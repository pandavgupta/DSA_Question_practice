// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        
    stack<int>mystack;
    int size=s.size();
    int upper,maxv{},start{},length;
    for(int i=0; i<size; i++){
        if(s[i]==')' ){
            if(!mystack.empty() && s[mystack.top()]=='('){
            while(!mystack.empty() && s[mystack.top()]=='('){
                 mystack.pop();
                 break;
            }
            }
            else mystack.push(i);
        }
        else mystack.push(i);
    }
    upper=size;
    while(!mystack.empty()){
        length=upper-mystack.top()-1;
        maxv= max(maxv,length);
        upper=mystack.top();
        mystack.pop();
    }
    length=upper-0;
     maxv= max(maxv,length);
    
    return maxv;
    
    }
};

// { Driver Code Starts.
int main() {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;

    return 0;
}
  // } Driver Code Ends