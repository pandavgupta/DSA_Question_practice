#include<iostream>
#include<vector>
// #include<pair>

using namespace std;

// int count_subsqeuence(string s,string op,vector<pair<string,string>>){
//     if(s.size()==0){
//      if(op[0]=='a' && op[op.size()-1]=='c'){
//          auto found=op.find('b');
//          if(found!=string::npos){
//           return 1;
//          }
//      }
//     return 0;
//     }
     

//      string op1=op;
//      int count{};
//      if(op1[op1.size()-1]<=s[0]){
//          op1.push_back(s[0]);
//      count=count_subsqeuence(s.substr(1),op1);
//      }

//      count+=count_subsqeuence(s.substr(1),op);

//      return count;
// }


int count_subsqeuence(string s){
    // vector<vector<int>>dp(3,vector<int>(6));
    // for(int i=0; i<3; i++)
    // for(int j=0; j<6; j++){
    //     if(i==j)
    //     dp[i][j]+=1;
    // }
    int a{},ab{},abc{};
    auto found=s.find('a');
    if(found==string::npos)
    return 0;
    s=s.substr(found);
    for(int i=0; i<s.size(); i++){
        
           if(s[i]=='a' )
                a=2*a+1;
                else if(s[i]=='b' )
                     ab=2*ab+a;
                    else
                     abc=2*abc+ab;
    } 
    return abc;
}


int main(){

    string s;
    cin>>s;
    vector<pair<int,string>>dp(s.size());
    // cout<<count_subsqeuence(s,"");
    cout<<count_subsqeuence(s);
    return 0;

}