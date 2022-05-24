#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int shortest_distance(int n, vector<int>adj[], int start, int dest){
    queue<int>bfs_queue;
    vector<int>distance(n,1e9);
    bfs_queue.push(start);
    distance[start]=0;
    while(!bfs_queue.empty()){
        for(auto i:adj[bfs_queue.front()]){
            if(distance[i]==1e9) 
            if(distance[bfs_queue.front()]+1 < distance[i]) {
                distance[i] = 1+distance[distance[bfs_queue.front()]];
                bfs_queue.push(i);
            }
        }
        bfs_queue.pop();
    }


    return distance[dest];
}
int main(){
    int vertex,edge,u,v,d,source, dest;
    std::cin>>vertex>>edge;
    std::vector<int>adj[vertex];
    for(int i=0; i<edge; i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"enter source: ";
    cin>>source;
    cout<<"enter destination: ";
    cin>>dest;
    std::cout<<shortest_distance(vertex,adj,source,dest);
   
    return 0;
}