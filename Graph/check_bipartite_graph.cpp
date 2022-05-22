#include<iostream>
#include<vector>
#include<queue>
// DFS solution with time complexity O(N+E), space complexity O(N+E)+O(N)+O(N) , first for storing graph
// second for storing color and third is for recursive stack;
bool helper(std::vector<int>adj[], std::vector<int>color, int val ){
    if(color[val]==-1) color[val]=0;
    for(auto i:adj[val]){
        if(color[i]==-1){
            color[i]=1-color[val];
            if(helper(adj, color,i)) return true;
        }
        else if(color[i]==color[val]) return true;
    }
    return false;
}
bool isBipartite(int V, std::vector<int>adj[]){
    std::vector<int>color(V+1,-1);
    for(int i=0; i<V; i++){
        if(color[i]==-1){
            if(helper(adj,color,i)) return false;
        }
    }
    return true;
}
//  BFS solution , time complexity O(N+E) for travelling whole graph, space complexity O(N+E)+O(N)+O(N)
// O(N+E ) for storing graph, O(N) for queue, O(N) for storing color;
// 	bool isBipartite(int V, vector<int>adj[]){
// 	    std::vector<int>check(V,-1);
// 	    std::queue<int>myqueue;
// 	    for(int i=0; i<V; i++){
// 	        if(check[i]==-1){
// 	            myqueue.push(i);
//         	    check[i]=0;
//         	    while(!myqueue.empty()){
//         	        for(auto i:adj[myqueue.front()]){
//         	            if(check[i]!=-1){
//         	                if(check[myqueue.front()]==check[i]) return false;
//         	            } 
//         	            else {
//         	                myqueue.push(i);
//         	                check[i]=1-check[myqueue.front()];
//         	           } 
//         	        }
//         	        myqueue.pop();
//         	    }
//     	     }
// 	        }
	    
// 	    return true;
// 	}
int main(){
    int n,m,u,v;
    std::cin>>n>>m;
    std::vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::cout<<isBipartite(n,adj);
   
    return 0;
}