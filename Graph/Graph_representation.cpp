#include<iostream>
#include<vector>
/*------------------------------------adjacency matrix:------------------------------*/ 
void print_adj_matrix(std::vector<std::vector<int>>&graph){
    for(int i=1; i<graph.size(); i++){
        std::cout<<i<<" : ";
        for (int j = 0; j <graph.size(); j++)
        {
            if(graph[i][j])
               std::cout<<j<<" "; 
        }
        std::cout<<"\n";
    }
}
void adjacency_matrix(){
    // m: number of edges  , n: number of nodes from 1
    int  m,n,j,k;
    std::cin>>m>>n;
    std::vector<std::vector<int>>graph(n+1, std::vector<int>(n+1));
    // here instead of vector we can use map or unordered_map.
    for(int i=0; i<m;i++){
        std::cin>>j>>k;
        graph[j][k]=1;
        graph[k][j]=1;
    }
    print_adj_matrix(graph);
}
/*------------------------------------adjacency list:------------------------------*/ 
void print_adj_list(std::vector<std::vector<int>>&graph){
    for(int i=1; i<graph.size(); i++){
        std::cout<<i<<" : ";
        for (int j = 0; j <graph[i].size(); j++)
        {
            std::cout<<graph[i][j]<<" "; 
        }
        std::cout<<"\n";
    }
}

void adjacency_list(){
    int m,n,j, k;
    // m: number of edges  , n: number of nodes from 1
    std::cin>>m>>n;
    std::vector<std::vector<int>>graph(n+1);
    // here instead of vector we can use map or unordered_map.
    for(int i=0; i<m;i++){
        std::cin>>j>>k;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }
    print_adj_list(graph);
}
int main(){
    // adjacency_matrix();
    adjacency_list();
    
}