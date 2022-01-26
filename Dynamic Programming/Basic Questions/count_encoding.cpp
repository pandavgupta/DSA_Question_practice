#include<iostream>
#include<vector>
#include<assert.h>
#include<math.h>
#include<time.h>
using namespace std;

// recursive approach

// int count_binaryp(string s){

//   if(s.size()<=1){
//     if(s.size()==1 && s[0]=='0')
//           return 0;
//     else
//           return 1;
    

//   }
  
//   int count{};
//   string s1,s2;


//   if(stoi(s.substr(s.size()-1))!=0){
//         s1=s.substr(0,s.size()-1);
//         count+=count_binary(s1);
//   }

//   else{
//       if(stoi(s.substr(s.size()-2))>26 )
//           return 0;
//       }

//   if(stoi(s.substr(s.size()-2))<=26 && stoi(s.substr(s.size()-2))>9){
//       s2=s.substr(0,s.size()-2);
//       count+=count_binary(s2);

//       }

//   return count;   
// }

int printEncoding(string str, string asf){
   
   if(str.size()==0){
    //   cout<<asf<<endl;
       return 1;
   }
   if(str[0]=='0')
     return 0;
    int i=1;
    int count{};
    while (i<=str.size() && stoi(str.substr(0,i)) <= 26)
    {
        string ip=str;
        string op=asf;
        char t=stoi(str.substr(0,i)) +96;
        op.push_back(t);
        ip=str.substr(i);
        count+=printEncoding(ip,op);
        i++;    }
        return count;
}
int count_binary(string s){
  vector<int>dp(s.size()+1);
  if(s[0]=='0')
  return 0;
  dp[1]=1;
 
  for(int i=2; i<=s.size(); i++){
   if(s[i-1]=='0' ){
       if(stoi(s.substr(i-2,2))>26)
       return 0;
       else{
           if(i==2)
            dp[i]=1;
          else
           dp[i]=dp[i-2];
       }
        
   }
   
   else{
       dp[i]=dp[i-1];
       if(stoi(s.substr(i-2,2))<=26 && stoi(s.substr(i-2,2))>9){
        if(i==2)
          dp[i]+=1;
          else
          dp[i]+=dp[i-2];
       }
        
    
   }
  }
  return dp[s.size()];
}

void test() {
    srand(time(NULL));
    int x = 100;
    while (x--) {
        int rand_num = rand() % 10000;
        string s = to_string(rand_num);
        int ans1=count_binary(s);
        int ans2=printEncoding(s,"");
        cout<<rand_num<<" "<<"dp:"<<ans1<<" recursive:"<<ans2<<endl;
        assert( ans1==ans2);
    }
}

int main(){
//    string s;
//    cin>>s;
//    cout<<count_binary(s);
test();

    return 0;

}