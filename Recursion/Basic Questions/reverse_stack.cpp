#include<iostream>
#include<stack>
using namespace std;

void put_in_stack(stack<int> &s,int tmp){
    if( s.size()==0){
        s.push(tmp);
        return;
    }
    int temp2=s.top();
    s.pop();
    put_in_stack(s,tmp);
    s.push(temp2);
    
}

void reverse(stack<int> &s){
    if(s.size()==1)
     return ;

    int tmp=s.top();
    s.pop();
    reverse(s);
    put_in_stack(s,tmp);
    
}

int main(){
    stack<int> s;
    int size,tmp;
    cout<<"ENter the size of stack : ";
    cin>>size;
    cout<<"enter elements: ";
    for (int i = 0; i <size; i++){
    cin>>tmp;
    s.push(tmp);
    }
    reverse(s);
    for (int i = 0; i < size; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}