#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<vector<int>>> adj)
    {
       vector<int>  key(V, 1e9);
       vector<bool> visited(V,false);
       vector<int> parent(V,-1);
       key[0] = 0;
       int element=0;
       int value = 1e9;
       for(int j = 0; j < V; j++){
           value = 1e9;
           for(int i = 0; i < V; i++){
               if(!visited[i] && key[i] < value) {
                   value = key[i];
                   element =i;
                   }
           }
           if(!visited[element]){
               visited[element] = true;
               for(auto i:adj[element]){
                   int v = i[0];
                   int w = i[1];
                   if(!visited[v] && w < key[v]) {
                      key[v] = w;
                      parent[v] = element;
                  }
               }
           }
           
       
       }
       int sum{};
       for(auto i:key) sum+=i;
        return sum;
    }
};



int main()
{
        int V, E;
        cin >> V >> E;
        vector<vector<vector<int>>> adj(V);
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
    return 0;
}
