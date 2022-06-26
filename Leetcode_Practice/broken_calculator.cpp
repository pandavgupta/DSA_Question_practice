#include<bits/stdc++.h>
using namespace std;
 int brokenCalc(int startValue, int target) {
        int count{};
        
        while(startValue<target){
           
           if(target > startValue && target%2==0 ){
               target = target/2;
           }
            else target++;
            count++;
            
        }
        if(target < startValue){
               count+=(startValue -target);
           }
        return count;
    }
int main(){
    int a, b;
    cin>>a>>b;
    cout<<brokenCalc(a,b);
    return 0;
}