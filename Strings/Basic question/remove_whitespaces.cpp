// a	program	to	count	the	number	of	occurrences	of	each	character	
// in	the	string	and	print	it.	

/* // remove whitespaces in normal char array
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
*/
//remove white spaces for string object
#include<iostream>
using namespace std;
  
    string removeWhitespaces(string s) {
        int start=0,last=0;
        while (s[start]==' ')
        start++;

        for(int j=start; j<s.size(); j++){
            if(s[j]==' ' && s[j+1]==' ' )
            continue;
                char tmp=s[last];
                s[last]=s[j];
                s[j]=tmp;
                last++; 
        }

        if(s[last-1]==' ')
        last--;
        s.resize(last);
        
        return s;
        
    }
int main(){
    string s;
    cout<<"Enter your string :"<<endl;
    getline(cin,s);
    s=removeWhitespaces(s);

    cout<<"string after reverse:"<<s;
    
    
    return 0;
}