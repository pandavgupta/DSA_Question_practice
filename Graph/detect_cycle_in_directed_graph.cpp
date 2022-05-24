#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isCyclic(int V, std::vector<int> adj[]) {
    vector<int>in_degree(V);
    queue<int>myqueue;
    int count{};
    for(int i=0; i<V; i++){
        for(auto j:adj[i]) in_degree[j]++;
    }
    for(int i=0; i<V; i++){
        if(in_degree[i]==0) myqueue.push(i);
    }
    while(!myqueue.empty()){
        count++;
        for(int i:adj[myqueue.front()]){
            in_degree[i]--;
            if(in_degree[i]==0) myqueue.push(i);
        }
        myqueue.pop();
    }
    if(count==V) return false;
    return true;
} 

// dfs solution ,TLE
//    std::vector<bool>g_check;
//     bool helper(std::vector<int> adj[], std::vector<bool>check,int val){
//     if(check[val]) return true;
//     check[val]=true;
//     g_check[val]= true;
//     for(auto i:adj[val]){
//         if(!g_check[i]){
//             if(helper(adj,check, i)) return true;
//         }
//         else if(check[i]) return true ;
       
       
//     }
//     return false;
// }
// bool isCyclic(int V, std::vector<int> adj[]) {
//     // check=std::vector<bool>(V);
//     std::vector<bool>check(V);
//     g_check = std::vector<bool>(V);
//     bool res = false;
//     for(int i=0; i<V; i++){
//         if( !g_check[i] && helper(adj,check,i)) return true;
//     }
//     return false;
// }

int main(){
    int n,m,u,v;
    std::cin>>n>>m;
    std::vector<int>adj[n];
    for(int i=0; i<m; i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
    }
    std::cout<<isCyclic(n,adj);
   
    return 0;
}