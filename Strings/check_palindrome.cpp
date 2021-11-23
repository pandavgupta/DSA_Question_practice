// Write check palindrome

#include<iostream>
using namespace std;


bool isPalindrome(char *mystring){
    char *mystring2;
    int size=0;
    char tmp;
    for (int i = 0; mystring[i]!='\0'; i++)
    size++;
    
    for (int i = 0; i < size/2; i++)
    {   if(mystring[i]!=mystring[size-1-i])
        return false;
        
    }
    
    
    return true;
    
    

}

int main(){
    char mystring[100],*mystring2;
    bool status;
    cout<<"Enter your string: ";
    cin.getline(mystring,100);
    
    status= isPalindrome(mystring);
    
    
    if(status)
    cout<<"Yes";
    else
    cout<<"No";
    
    
    return 0;
}