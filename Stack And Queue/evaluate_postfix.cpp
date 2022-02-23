#include<iostream>
#include<stack>
#include<string>
using namespace std;

int postfix_evaluation(string input){
    stack<int>mystack;
    int a,b,j,size=input.length(),data;
    for(int i =0; i<size; i++){
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%'){
            b = mystack.top();
             mystack.pop();
            a =mystack.top();
             mystack.pop();
            switch (input[i])
            {
            case '+':  mystack.push(a+b);
                
                break;
            case '-':  mystack.push(a-b);
                
                break;
            case '*': mystack.push(a*b);
                
                break;
            case '/':  mystack.push(a/b);
                
                break;
            case '%':  mystack.push(a%b);
                
                break;
            default:
                break;
            }
            j=i+1;
            while (j<size && input[j]==' ')
            j++;
            i=j-1;
        }
        else{
            j=i;
        while (input[j]!=' ' && j< size)
        {
            j++;
        }
        data= stoi(input.substr(i,j-i));
        mystack.push(data);
        while (j<size && input[j]==' ')
           j++;
        
        i=j-1;
        }
        
    }
    if(!mystack.empty())
    return mystack.top();
    return -1;
}

int main(){
    int size;
    string expression;
    getline(cin,expression);
    cout<<postfix_evaluation(expression);
    return 0;
}