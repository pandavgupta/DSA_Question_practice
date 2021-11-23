// Find	Duplicate	characters	in	a	string
#include<iostream>
using namespace std;

void find_duplicate(char *mystring){
    int arr[128]={0};
    cout<<"Duplicate character are: "<<endl;
    for (int i = 0; mystring[i]!='\0'; i++)
    {
        arr[mystring[i]]++;
        
    }
    for (int i = 0; i < 128; i++)
    {
        if ( arr[i] > 1)
        cout<<char(i)<<endl;
    }
    

    
    return;
}

int main(){
    char my_string[100];
    cout<<"Enter your string: ";
    cin.getline(my_string,100);
    find_duplicate(my_string);
    
    return 0;
}