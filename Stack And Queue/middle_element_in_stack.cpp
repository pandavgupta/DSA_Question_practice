#include<iostream>
#include<vector>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
    Node* prev;
    Node(): data(0),next(nullptr),prev(nullptr){};
    Node(int data):data(data),next(nullptr),prev(nullptr){};
};
class Mystack{
    Node* Top;
    Node* middle;
    int size;
  public:
    Mystack():size(0),Top(nullptr),middle(nullptr){};
    void push(int data){
        Node* newNode = new  Node(data);
        newNode->next = Top;
        if(Top!=nullptr)Top->prev= newNode;
        Top=newNode;
        if((middle==nullptr) )
            middle= newNode;
        else if(size>2 && (size/2!=(size+1)/2))
            middle = middle->prev;
        ++size;
    }
    int pop(){
        if(Top==nullptr) return -1;
        Node* tmp = Top;
        int val =Top->data;
        Top=Top->next;
        if(size>2 && size/2!=(size-1)/2){
            middle=middle->next;
        }
        if(size==1)
          middle=middle->next;
        delete tmp;
        --size;
        return val;
    }
    int peek(){
        if(Top==nullptr) return -1;
        return Top->data;
    }
    bool isEmpty(){
        if(Top==nullptr) return true;
        return false;
    }
    int getMiddle(){
        return middle->data;
    }
    int length(){
        return size;
    }
    int deleteMiddle(){
        int val=middle->data;
        if(middle->next==nullptr){
            if(middle==Top){
                val=middle->data;
                middle= nullptr;
                Top=nullptr;
            }
            else{
                val=middle->data;
                middle=middle->prev;
            }

        }
        else{
            Node* tmp = middle;
            Node* tmp2 = nullptr;
            tmp2 = middle->next;
            val=tmp->data;
            middle->next= middle->prev;
            if(size>2 && size/2!=(size-1)/2){ middle=tmp2; }
            if(size==1)
              middle=tmp2;
            delete tmp;
            
        }
        --size;
        return val;
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

    cout<<mystack.deleteMiddle()<<"\n"; 
    // cout<<mystack.getMiddle()<<"\n";
    while(!mystack.isEmpty()){
       cout<<"middle :"<<mystack.getMiddle();
       cout<<",element: "<<mystack.pop()<<"\n";
    }
    

     
    return 0;
    
    

}