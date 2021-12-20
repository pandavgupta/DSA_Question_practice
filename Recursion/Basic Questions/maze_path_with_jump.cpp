#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dc, int dr, string psf) {
            if(sr==dr && sc==dc){
         cout<<psf<<endl;
         return ;
     }
    if (sr>dr || sc>dc )
    return ;
    
    for (int i = 1; i+sr<=dr; i++)
    {   string op1=psf;
        op1.push_back('h');
        op1.push_back('0'+i);
        printMazePaths(sr+i,sc,dc,dr,op1);
    }

    for (int i = 1; i+sc<=dc; i++)
    {   string op2=psf;
        op2.push_back('v');
        op2.push_back('0'+i);

        printMazePaths(sr,sc+i,dc,dr,op2);
    }


    for (int i = 1,j=1; i+sr <=dr && i+sc<=dc; i++,j++)
    {
        string op3=psf;
       op3.push_back('d');
       op3.push_back('0'+i);
       printMazePaths(sr+i,sc+i,dc,dr,op3);
    }
    
    return ;
        
    }
    

int main() {
        int n ;
        int m ;
        cout<<"Enter row and columns:";
        cin>>n>>m;
        printMazePaths(1, 1, n , m , "");
        
    }