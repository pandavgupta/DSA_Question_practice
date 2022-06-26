#include<bits/stdc++.h>
using namespace std;
    
    //     int solveB(vector<int>& tops, vector<int>& bottoms, int& maxv,int target, int lm){
//         int size=tops.size();
//         int i=0;
//             while(lm!=-1 && i<size){
//                 if(target == bottoms[i]){
//                     i++;
//                     continue;
//                 }
//                 else if(target == tops[i]){
//                     lm++;
//                 }
//                 else lm =-1;
//                 i++;
//             }

        
//         maxv = min(maxv, lm);
//         return lm;
//     }
    
//     int solveT(vector<int>& tops, vector<int>& bottoms, int& maxv,int target, int lm){
//         int size=tops.size();
//         int i=0;
//             while(lm!=-1 && i<size){
//                 if(target == tops[i]){
//                     i++;
//                     continue;
//                 }
//                 else if(target == bottoms[i]){
//                     lm++;
//                 }
//                 else lm =-1;
//                 i++;
//             }

        
//         maxv = min(maxv, lm);
//         return lm;
//     }
    
//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int maxv1 = 1e9, maxv2 = 1e9, lm;
//         lm = solveT(tops, bottoms, maxv1, tops[0], 0);
//         if(lm!=-1)
//         lm = solveB(tops, bottoms, maxv1, tops[0], 0);
        
        
//         lm = solveT(tops, bottoms, maxv2, bottoms[0], 0);
//         if(lm!=-1)
//         lm = solveB(tops, bottoms, maxv2, bottoms[0], 0);
//         // cout<<maxv1<<","<<maxv2<<endl;
//         if(maxv1 == maxv2 && maxv2 == -1) return -1;
//         if(maxv1 !=-1 && maxv2!=-1) return min(maxv1,maxv2);
        
//         return maxv1>0?maxv1:maxv2; 
//     }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>arr1(7),arr2(7),same(7);
        int size =tops.size();
        for(int i =0; i<size; i++){
            arr1[tops[i]]++;
            arr2[bottoms[i]]++;
            if(tops[i]==bottoms[i]) same[tops[i]]++;
        }
        int maxv1=-1, maxv2=-1;
        
        if((size - (arr1[tops[0]]+arr2[tops[0]]-same[tops[0]])) == 0){
            maxv1 = min (size-arr1[tops[0]], size -arr2[tops[0]]);
        }
        
        if((size - (arr1[bottoms[0]]+arr2[bottoms[0]]-same[bottoms[0]])) == 0){
            maxv2 = min (size-arr1[bottoms[0]], size -arr2[bottoms[0]]);
        }
        // cout<<maxv1<<","<<maxv2<<endl;
        if(maxv1 == maxv2 && maxv2 == -1) return -1;
        if(maxv1 !=-1 && maxv2!=-1) return min(maxv1,maxv2);
        
        return maxv1>0?maxv1:maxv2; 
        
    }
int main(){
    int n;
    cin>>n;
    vector<int>arr1(n),arr2(n);
    for(int i=0; i<n; i++)
     cin>>arr1[i];
     for(int i=0; i<n; i++)
     cin>>arr2[i];
     cout<<minDominoRotations(arr1,arr2);
    return 0;
}