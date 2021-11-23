// Write	a	program	to	reverse	each	word	in	the	given	string
#include<iostream>
using namespace std;

void reverse_string(char *mystring, int start, int last){
    char tmp;
    int condition=start+(last-start)/2;
    for (int i = start; i <= condition; i++)
    {
        tmp=mystring[i];
        mystring[i]=mystring[start+last-i];
        mystring[start+last-i]=tmp;
        
    } 
    return;
}

void reverse_word(char *mystring){
    int start=0,last=0,size=0;
    for (int i = 0; mystring[i]!='\0'; i++)
    {
       if(mystring[i]==' ')
       {   last=i;
           reverse_string(mystring,start,last-1);
           start=i+1;
       }
    }
    
    for (int i = 0; mystring[i]!='\0'; i++)
    size++;
    

    reverse_string(mystring,start,size-1);

    
    
    return;
}

int main(){
    char mystring[100];
    cout<<"Enter your string: ";
    cin.getline(mystring,100);
    reverse_word(mystring);

    cout<<"string after reverse: "<<mystring;
    
    
    return 0;
}