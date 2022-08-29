#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    TrieNode* links[26];
    bool End = false;
    public:
    bool contain_key(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch, TrieNode* node){
        links[ch - 'a'] = node;
    }
    
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        End = true;
    }
    bool isEnd(){
        return End;
    }
};
class Trie {
    TrieNode* root;
public:
    
    Trie(){
      root = new TrieNode();  
    }
    
    void insert(string word) {
        if(word.size() == 0) return;
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->contain_key(word[i])) node->put(word[i],new TrieNode());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->contain_key(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->contain_key(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main(){
    string inst, wrd;
    cin>>inst>>wrd;
    inst = inst.substr(1, inst.size()-2);
    vector<string> instruction;
    string tmp;
    stringstream ss(inst);
    while(getline(ss, tmp,',')){
        tmp = tmp.substr(1,tmp.size()-2);
        instruction.push_back(tmp);
    }
    vector<string> words;
    stringstream s2(wrd);
    getline(s2,tmp,']');
    while(getline(s2,tmp,']') && tmp.size() > 3){
        tmp = tmp.substr(3, tmp.size()-4);
        words.push_back(tmp);
    }
    Trie* data = new Trie();
    for(int i = 1; i < instruction.size(); i++){
        if(instruction[i] == "insert"){
            data->insert(words[i-1]);
            cout<<"done ";
        }
        else if(instruction[i] == "search"){
            if(data->search(words[i-1])) cout<<"True ";
            else cout<<"False ";
        }
        else if(instruction[i] == "startsWith"){
            if(data->startsWith(words[i-1])) cout<<"True ";
            else cout<<"False ";
        }
    }
    cout<<endl;
    return 0;
}