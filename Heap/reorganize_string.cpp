#include<bits/stdc++.h>
using namespace std;

void heapify(vector<pair<char,int>>& arr,int n , int i){
        int largest=i;
        int leftchild=2*i+1;
        int rightchild = 2*i+2;
        if(leftchild<n && arr[largest].second<arr[leftchild].second) largest=leftchild;
        if(rightchild<n && arr[largest].second<arr[rightchild].second) largest=rightchild;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        return;
    }
    void build_heap(vector<pair<char,int>>&arr,int n){
        for(int i=(n/2)-1; i>=0; i--){
            heapify(arr,n,i);
        }
        
    }
    
    string reorganizeString(string s) {
       vector<pair<char,int>>arr;
       vector<int>hash(26);
        int size = s.size();
        string result="";
        for(int j=0; j<size;j++ )
                hash[s[j]-97]++;
        for(int i=0; i<26; i++){
            if(hash[i]){
                arr.push_back(make_pair(char(i+97),hash[i]));
            }
        }
        int heap_size=arr.size();
        build_heap(arr,heap_size);
        int flag=0;
        int largest,leftchild,rightchild;
        while(heap_size>1){
                while(arr[0].second==0){
                   swap(arr[0],arr[heap_size-1]);
                       heap_size--;
                   heapify(arr,heap_size,0);
                   if(heap_size==1) {
                       flag=1;
                       break;
                       };
                }
                if(flag)
                  break;
                largest=0;
                 
                if(2<heap_size &&arr[2].second>arr[1].second ) largest=2;
                else largest=1;
            
                
                result.push_back(arr[0].first);
                arr[0].second-=1;
                swap(arr[largest],arr[0]);
                heapify(arr,heap_size,largest);

        }
        if(arr[0].second>=1) return "";
        if(result[result.size()-1]==result[result.size()-2]) return "";
    
      return result; 
    } 

int main(){
    string s;
    cin>>s;
    cout<<reorganizeString(s);
    return 0;
}