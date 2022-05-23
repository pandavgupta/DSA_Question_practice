#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// BFS solution (Kahn's algorithm) time complexity O(N+E), space O(N)+O(N)
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int>result;
    vector<int>in_degree(V,0);
    queue<int>myqueue;
    for(int i=0; i<V ; i++){
        for(auto j:adj[i]) in_degree[j]++;
    }
    for(int i=0; i<V; i++){
        if(in_degree[i]==0) myqueue.push(i);
    }
    while(!myqueue.empty()){
        result.push_back(myqueue.front());
        for(auto i:adj[myqueue.front()]){
            if(in_degree[i]>0) in_degree[i]--;
            if(in_degree[i]==0) myqueue.push(i);

        }
        myqueue.pop();
    }
    return result;
}
// dfs solution
// vector<int>res;
// vector<int>visited;
// void dfs(vector<int>adj[], int val ,int &index){
//     if(visited[val]) return ;
//     visited[val]=1;
//     for(auto i:adj[val]){
//         dfs(adj,i,index);
//     }
//     res[index--]=val;
// }
// vector<int> topoSort(int V, vector<int> adj[]) 
// {
//     res = vector<int>(V);
//     visited = vector<int>(V);
//     int index = V-1;
//     for(int i=0; i<V; i++){
//         if(!visited[i]){
//             dfs(adj,i,index);
//         }
//     }
//     return res;
// }
int main(){
    int n,m,u,v;
    std::cin>>n>>m;
    std::vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>result = topoSort(n,adj);
    for(auto i:result){
        std::cout<<i<<" ";
    }
    std::cout<<'\n';
   
    return 0;
}