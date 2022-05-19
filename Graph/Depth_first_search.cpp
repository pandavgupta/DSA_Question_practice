#include<iostream>
#include<vector>
std::vector<int>res;
std::vector<bool>check;
void helper(std::vector<int>adj[], int val){
        if(check[val]) return ;
        res.push_back(val);
        check[val]=true;
        for(auto i:adj[val])  helper(adj,i);
        return ;
    }
    std::vector<int> dfsOfGraph(int V, std::vector<int> adj[]) {
        check = std::vector<bool>(V+1);
        helper(adj,0);
        return res;
    }
int main(){
    int n,m,u,v;
    std::cin>>n>>m;
    std::vector<int>adj[n];
    for(int i=0; i<m; i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int>ans = dfsOfGraph(n,adj);
    for(auto i:ans) std::cout<<i<<" ";
    std::cout<<std::endl;
    return 0;
}