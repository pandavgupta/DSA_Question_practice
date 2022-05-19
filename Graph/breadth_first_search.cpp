#include<iostream>
#include<vector>
#include<queue>

std::vector<int> bfsOfGraph(int V, std::vector<std::vector<int>> adj) {
        std::vector<bool>check(V);
        std::vector<int>res;
        std::queue<int>myqueue;
        // here we have only one component of graph that is starting from 0.
        myqueue.push(0);
        check[0]=true;
        while(!myqueue.empty()){
            res.push_back(myqueue.front());
                for(auto j:adj[myqueue.front()]){
                    if(!check[j]){
                        myqueue.push(j);
                        check[j]=true;
                    }
                }
            myqueue.pop();
            
        }
        
        return res;
    }
int main(){
    int n, m,j,k;
    std::cin>>n>>m;
    std::vector<std::vector<int>>graph(n);
    for(int i=0; i<m; i++){
        std::cin>>j>>k;
        graph[j].push_back(k);
    }
    std::vector<int>res = bfsOfGraph(n,graph);
    for(auto i:res) std::cout<<i<<" ";
    std::cout<<std::endl;
}