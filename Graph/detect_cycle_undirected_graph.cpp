// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
// dfs solution
// bool helper(std::vector<int> adj[], std::vector<bool>&check,int val, int prev){
//     if(check[val]) return true;
//     check[val]=true;
//     for(auto i:adj[val]){
//         if(!check[i]){
//             if( helper(adj,check, i,val)) return true; 
//         }
        
//         else if(i!=prev) return true;
       
//     }
//     return false;
// }
// bool isCycle(int V, std::vector<int> adj[]) {
//     std::vector<bool>check(V+1);
//     for(int i=0; i<V; i++){
//         if(!check[i]){
//             if(helper(adj,check,0,-1))return true;
//         }
//     }
//     return false;
// }


// bfs solution
bool isCycle(int V,  std::vector<std::vector<int>>&adj) {
    std::vector<bool>check(V+1);
    std::queue<std::pair<int,int>>myqueue;
    int prev;
    for(int i=0; i<V; i++){
        if(!check[i]){
            check[i] = true;
            myqueue.push({i,-1});
            prev = i;
            while(!myqueue.empty()){
                prev = myqueue.front().first;
                for(auto j:adj[myqueue.front().first]){
                    if(j==myqueue.front().second) continue;
                    if(check[j]) return true;
                    myqueue.push({j,prev});
                    check[j]=true;
                }
                
                myqueue.pop();
            }
        }
        
    }
    return false;
}
int main(){
    int n,m,u,v;
    std::cin>>n>>m;
    std::vector<std::vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::cout<<isCycle(n,adj);
   
    return 0;
}