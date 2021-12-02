int main(){
    string s;
    cout<<"enter the string :";
    getline(cin,s);
    removeDuplicate(s);
    cout<<"string after removal of duplicate element :"<<s;
    return 0;
}