#include<iostream>
#include<vector>
using namespace std;

    bool isSubSequence(string A, string B) 
    {
        if(A.size()>B.size())
          return false;
        else if(A.size()==B.size()){
            if(A==B)
              return true;
            else
              return false;
        }
        int index=-1;
        int count=0;
        for(int i=0; i<A.size(); i++)
          for(int j=index+1; j<B.size();j++){
              if(A[i]==B[j]){
                  count++;
                  index=j;
                  break;
              }
          }
        
        if(count==A.size())
         return true;
         else
          return false;
    }

int main()
{
   string text1,text2;
   cout<<"enter string: ";
   cin>>text1>>text2;
   cout<<isSubSequence(text1,text2);
    return 0;
}
