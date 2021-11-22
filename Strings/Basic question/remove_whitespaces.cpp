// a	program	to	count	the	number	of	occurrences	of	each	character	
// in	the	string	and	print	it.	

#include<iostream>
using namespace std;


void remove_whitespaces(char *value){
    char arr[100];
    int i=0;
    for (int j=0; value[j] != '\0'; j++)
    {    
        if(value[j] !=' '){
         arr[i]=value[j];
         i++;
        }
        
    }
    arr[i]='\0';
    for (int i = 0; arr[i] !='\0'; i++)
    cout<<arr[i];
    return ;
}

int main(){
    int max_length=100;
    char value[max_length];
    cout<<"Enter the string: ";
    cin.getline(value, max_length);
    remove_whitespaces(value);

    
    
    
    
    return 0;
}