int longestCommonSubsequence(string text1, string text2,vector<vector<int>>&dp) {
        if(dp[text1.size()][text1.size()]!=-1)
         return dp[text1.size()][text1.size()];

        if(text1.size()==0|| text2.size()==0)
             return 0;
          
        int count{};
        
        if(text1[text1.size()-1]==text2[text2.size()-1]){
            count=1+longestCommonSubsequence(text1.substr(0,text1.size()-1),text2.substr(0,text2.size()-1),dp);
        }
        else if(text1.size()!=text2.size()){
               
            count=max(longestCommonSubsequence(text1.substr(0,text1.size()),text2.substr(0,text2.size()-1),dp),
            longestCommonSubsequence(text1.substr(0,text1.size()-1),text2.substr(0,text2.size()),dp));

            count=max(  count  ,  longestCommonSubsequence(text1.substr(0,text1.size()-1),text2.substr(0,text2.size()-1),dp));
            
        }  
        
        
        return dp[text1.size()][text1.size()]=count;
    }
