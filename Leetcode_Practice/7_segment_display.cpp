// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
//   int getSegments(char c) {
//         switch(c) {
//             case '8': return 7;
//             case '0': 
//             case '6': return 6;
//             case '2':
//             case '3':
//             case '5': 
//             case '9': return 5;
//             case '4': return 4;
//             case '7': return 3;
//             case '1': return 2;
//         }
//     }
//  char getNumber(int c){
//      switch(c) {
//             case  6: return '0';
//             case  2: return '1'; 
//             case  5: return '2';
//             case  4: return '4';
//             case  3: return '7';
//             case  7: return '8'; 
//         }
//  }
    string sevenSegments(string S, int N) {
        unordered_map<char,int>getSegments;
        unordered_map<int,int>getNumber;
        vector<int>arr;
        string res = "";
        getSegments.insert({'0',6});
        getSegments.insert({'1',2});
        getSegments.insert({'2',5});
        getSegments.insert({'3',5});
        getSegments.insert({'4',4});
        getSegments.insert({'5',5});
        getSegments.insert({'6',6});
        getSegments.insert({'7',3});
        getSegments.insert({'8',7});
        getSegments.insert({'9',5});
        
        getNumber.insert({6,0});
        getNumber.insert({2,1});
        getNumber.insert({5,2});
        getNumber.insert({4,4});
        getNumber.insert({3,7});
        getNumber.insert({7,8});
        
        arr.push_back(6);
        arr.push_back(2);
        arr.push_back(5);
        arr.push_back(4);
        arr.push_back(3);
        arr.push_back(7);
        
        int total_segment {};
        for(int i =0; i<N; i++){
            total_segment+=getSegments[S[i]];
        }
        int data, range, count;
        while(N>0){
            range = 2*N;
            if(range >7){
                for(int i=0; i<6; i++){
                    if(range%arr[i]==0){
                        data = arr[i];
                        break;
                    }
                }
                count = total_segment/data;
                total_segment = total_segment%data;
            }
            else{
                data = range/N;
                count = 1;
                total_segment = total_segment - data;
            }
            N = N-count;
            while(count!=0){
                res+=to_string(getNumber[data]);
                count--;
            }
            
        }
        return res;
        
    }
};

// { Driver Code Starts.
int main() {

        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    return 0;
}  // } Driver Code Ends