#include<iostream>
#include<stack>
using namespace std;



void delete_middle(stack<int> &s,int pos){
    if(s.size()-1==pos){
     s.pop();
     return;
    }
      
    int tmp=s.top();
    s.pop();
    delete_middle(s,pos);
    s.push(tmp);
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
    delete_middle(s,s.size()/2);
    for (int i = 0; i < size; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}