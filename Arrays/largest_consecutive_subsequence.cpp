#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// using set    time complexity O(N) and space O(N)
int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_set<int>s;
      int max=arr[0],min=arr[0],count=0,max_count=0;
      for(int i=0; i<N; i++){
        if(arr[i]>max)
        max=arr[i];
        if(arr[i]<min)
        min=arr[i];
        s.insert(arr[i]);
        
      }
      for(int i=min; i<=max; i++){
          if(s.find(i)!=s.end()){
              count++;
          }
          else{
              count=0;
          }
          
          if(max_count<count)
          max_count=count;
      }
      
      return max_count;
    }

//using set    time complexity O(N) and space O(N)
/*
int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_map<int,int>m;
      int count,j,flag,max_count=1;
      for(int i=0; i<N; i++){
          m[arr[i]]=1;
      }
      for(int i=0; i<N; i++){
          count=1;
          j=1;
          flag=0;
          if(m[arr[i]]){
              
                  if( m.find(arr[i]-1) != m.end() ){
                         m[arr[i]-1]=0;
                         count++;
                         while(m.find(arr[i]-count)!=m.end()){
                           m[arr[i]-count]=0;
                           count++;
                         }
                         m[arr[i]]=0;
                  
                  }
              
                 if( m.find(arr[i]+1)!=m.end() ){
                         m[arr[i]+1]=0;
                         j++;
                         while(m.find(arr[i]+j)!=m.end()){
                               m[arr[i]+j]=0;
                               j++;
                               
                          }
                          m[arr[i]]=0;
                          
                          if(count>1)
                          count+=j-1;
                          else
                          count=j;
                 }
                 
                 if(count>max_count)
                 max_count=count;
          }
          
      }
      
      return max_count;
    }


*/
int main(){
    
   int size,*arr,result;
   cout<<"Enter the size of array : ";
   cin>>size;
   arr=new int[size];
   cout<<"Enter the array's element: ";
   for (int i = 0; i < size; i++)
   {
    cin>>arr[i];
   }
   
   result =  findLongestConseqSubseq(arr, size);

   cout<<"largest consecutive subsequence :"<<result;
    
    return  0;

}