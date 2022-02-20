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
class Myqueue{
  public:
    Node* front;
    Node* rear;
    int size;
    Myqueue():size(0),front(nullptr),rear(nullptr){};
    void enqueue(int data){
        Node* newNode = new  Node(data);
        if(front==nullptr){
            front=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear = rear->next;
        ++size;
    }
    int dequeue(){
        Node* tmp = front;
        if(rear==front)
         rear = rear->next;
        int val= front->data;
        front = front->next;
        delete tmp;
        --size;
        return val;
    }
   
    bool isEmpty(){
        if(size==0) return true;
        return false;
    }
    
};



int main(){
    int size,tmp;
    Myqueue myqueue;
    cin>>size;
    for (int i = 0; i < size; i++){
       cin>>tmp;
       myqueue.enqueue(tmp);
    }
    // cout<<myqueue.front->data<<"\n";
    for (int i = 0; i < size; i++)
    {
        cout<<myqueue.dequeue()<<" ";
    }

     
    return 0;
    
    

}