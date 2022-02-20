#include<iostream>
#include<vector>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
    Node(): data(0),next(nullptr){};
    Node(int data):data(data),next(nullptr){};
};
class Mystack{
  public:
    Node* Top;
    int size;
    Mystack():size(0),Top(nullptr){};
    void push(int data){
        Node* newNode = new  Node(data);
        newNode->next = Top;
        Top=newNode;
        ++size;
    }
    void pop(){
        Node* tmp = Top;
        Top=Top->next;
        delete tmp;
        --size;
    }
    int peek(){
        if(Top==nullptr) return -1;
        return Top->data;
    }
    bool isEmpty(){
        if(Top==nullptr) return true;
        return false;
    }
    
};



int main(){
    int size,tmp;
    Mystack mystack;
    cin>>size;
    for (int i = 0; i < size; i++){
       cin>>tmp;
       mystack.push(tmp);
    }
    cout<<mystack.peek()<<" "<<mystack.isEmpty()<<" "<<mystack.size;

     
    return 0;
    
    

}