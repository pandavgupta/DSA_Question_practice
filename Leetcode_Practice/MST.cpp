#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

    bool detect_cycle(Node* root, int val){
        int data = root->data;
        Node* it = root;
        // root = root->prev;
        while(root!=nullptr){
            // if(root->data == data) break;
            if(root->data == val) return true;
            root = root->prev;
        }
        root = it;
        root = root->next;
        while(root!=nullptr){
            // if(root->data == data) break;
            if(root->data == val) return true;
            root = root->next;
        }
        return false;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>MST;
        vector<Node*> graph;
        int dist;
        int size = points.size();
        for(int i=0; i<size; i++){
            Node* newNode = new Node(i);
            graph.push_back(newNode);
        }
        for(int i=0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                dist = abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]);
                MST.push_back({dist,i,j});
            }
        }
        sort(MST.begin(), MST.end());
        int count{};
        int res{};
        for(int i=0; i<MST.size(); i++){
            if(count==size-1) return res;
            if(!detect_cycle(graph[MST[i][1]], MST[i][2])){
                res+=MST[i][0];
                if(graph[MST[i][1]]->next == nullptr)
                {
                    graph[MST[i][1]]->next = graph[MST[i][2]];
                    graph[MST[i][2]]->prev = graph[MST[i][1]];
                }
                else{
                      graph[MST[i][1]]->prev = graph[MST[i][2]];
                      graph[MST[i][2]]->next = graph[MST[i][1]];
                      }
                count++;
            }
        }
        return res;
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr;
    vector<int>tmp;
    for(int i=0; i<n;  i++){
        tmp = vector<int>(2);
        for(int j=0; j<2; j++) cin>>tmp[j];
        arr.push_back(tmp);
    }
    cout<<minCostConnectPoints(arr);
    return 0;
}