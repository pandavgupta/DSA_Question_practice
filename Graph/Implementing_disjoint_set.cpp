#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
    public:
        void makeSet(vector<int>&universe){
            for(int element : universe){
                parent[element] = element;
                rank[element] = 0;
            }
        }
        int Find_parent(int node){
            if(parent[node] == node) return node;
            
            return parent[node] = Find_parent(parent[node]); // finding parent and performing path compression
        }
        void Union(int A, int B){
            int parent_A = Find_parent(A);
            int parent_B = Find_parent(B);
            if(parent_A == parent_B) return;
            if(rank[parent_A] < rank[parent_B]) parent[parent_A] = parent_B;
            else if(rank[parent_A] > rank[parent_B]) parent[parent_B] = parent_A;
            else{
                parent[parent_A] = parent_B;
                rank[parent_B]++;
            }
        }
};
void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i: universe) {
        cout << ds.Find_parent(i) << ' ';
    }
    cout << endl;
}
int main(){
   // universe of items
    vector<int> universe = {1,2,3,4,5};
    // initialize `DisjointSet` class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);
 
    ds.Union(4, 3);        // 4 and 3 are in the same set
    printSets(universe, ds);
 
    ds.Union(2, 1);        // 1 and 2 are in the same set
    printSets(universe, ds);
 
    ds.Union(1, 3);        // 1, 2, 3, 4 are in the same set
    printSets(universe, ds);

    return 0;
}