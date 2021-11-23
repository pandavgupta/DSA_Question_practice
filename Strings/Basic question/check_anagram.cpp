// Write	a	program	to	check	whether	given	two	strings	are	anagram	or	
// not.
#include<iostream>
using namespace std;

int find_size(char *mystring){
  int size=0;
  for (int i = 0; mystring[i]!=0; i++)
  size++;

  return size;
}
bool isAnagram(char *a, char *b)
    {
        
        if(find_size(a) == find_size(b)){
          int arr[128]={0};
          for(int i=0; a[i]!='\0'; i++)
            arr[a[i]]++;
        
          for(int i=0; b[i]!='\0'; i++)
            arr[b[i]]--;
        
          for(int i =0; i<128; i++)
           {
              if(arr[i] < 0)
              return false;
           }
           return true;
            
        }
        
        return false;
   
    }


int main(){
    char mystring1[100],mystring2[100];
    bool status;
    cout<<"Enter your first string: ";
    cin.getline(mystring1,100);

    cout<<"Enter your second string: ";
    cin.getline(mystring2,100);
    
    status= isAnagram(mystring1, mystring2);
    
    if ( status)
    cout<<"yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}