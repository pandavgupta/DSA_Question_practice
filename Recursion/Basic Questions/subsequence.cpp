#include<iostream>
#include<vector>
using namespace std;


//returning the value of subsequence
//using Induction base Hypothesis method
vector<string> subsequence(string s){
   if(s.length()==0){
       vector<string>k;
       k.push_back("");
       return k;
   }
   
   char ch=s[0];
   string s1=s.substr(1);
   vector<string>res,tmp;
   tmp=subsequence(s1);
   for(auto it:tmp)
       res.push_back(""+it);

   for(auto it:tmp)
       res.push_back(ch+it);
    
    return res;
}


/*
//returning the value of subsequence
//using input-output method/ resursion tree method
vector<string> subsequence(string s1, string s2=""){
    if(s1.length()==0){
      vector<string> k;
      k.push_back(s2);
     return k;
    }
    vector<string> res,tmp;
    string op1=s2;
    string op2=s2;
    op2.push_back(s1[0]);
    s1.erase(s1.begin()+0);
    tmp=subsequence(s1,op2);
    for(auto it:tmp)
     res.push_back(it);
     
    tmp=subsequence(s1,op1);
    for(auto it:tmp)
     res.push_back(it);
    
    return res;
    
}

*/



int main(){
    string s1;
    vector<string>v;
    cout<<"Enter the string:";
    cin>>s1;
    v= subsequence(s1);
    cout<<"[";
    for(auto it:v)
    cout<<it<<",";
    cout<<"]";
    return 0;
}



/* printing subsequence
void subsequence(string s1, string s2){
    if(s1.length()==0){
     cout<<"["<<s2<<"]"<<",";
     return;
    }
    string op1=s2;
    string op2=s2;
    op2.push_back(s1[0]);
    s1.erase(s1.begin()+0);
    subsequence(s1,op2);
    subsequence(s1,op1);
    
    return;
    
}
int main(){
    string s1;
    cout<<"Enter the string:";
    cin>>s1;
    subsequence(s1,"");

    return 0;
}
*/

