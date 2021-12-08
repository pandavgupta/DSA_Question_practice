#include<iostream>
#include<stack>
using namespace std;

void put_in_stack(stack<int> &s,int tmp){
    if( s.empty() || s.top() <= tmp){
        s.push(tmp);
        return;
    }
    int tmp2= s.top();
    s.pop();
    put_in_stack(s,tmp);
    s.push(tmp2);
}

void sort_stack(stack<int> &s){
    if(s.empty())
      return;
    int tmp=s.top();
    s.pop();
    sort_stack(s);
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
    sort_stack(s);
    for (int i = 0; i < size; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}