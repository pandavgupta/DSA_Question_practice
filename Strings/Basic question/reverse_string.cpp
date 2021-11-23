// Write	a	program	to	reverse	the	string	in	place.	

#include<iostream>
using namespace std;

void reverse_string(char *mystring){
    int size=0;
    char tmp;
    for (int i = 0; mystring[i]!='\0'; i++)
    size++;
    
    for (int i = 0; i < size/2; i++)
    {
        tmp=mystring[i];
        mystring[i]=mystring[size-1-i];
        mystring[size-1-i]=tmp;
        
    }
    
    
    return;
}

int main(){
    char mystring[100];
    cout<<"Enter your string: ";
    cin.getline(mystring,100);
    reverse_string(mystring);

    cout<<"string after reverse: "<<mystring;
    
    
    return 0;
}