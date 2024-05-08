/*
Spanning tree is a tree in which we have N nodes and N-1 edges and all the nodes
are reachable from each other. A graph may have multiple spanning trees.

Minimum spanning tree is a spanning tree which has minimum sum of weights. There
may be multiple mst.
*/
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){   
    
    /* 
    Here adj[i] contains vectors of size 2, where the first integer in that vector denotes 
    the end of the edge and the second integer denotes the edge weight.

    Each element in pq is (weight, node, parent)
    */
   //  priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> visited(V, false);
    vector<vector<int>> mst;
    int sum = 0;

    pq.push({0, {0, -1}});
    while (!pq.empty()){
        int currWeight = pq.top().first;
        int currNode = pq.top().second.first;
        int currParent = pq.top().second.second;
        pq.pop();
        if (!visited[currNode]){
            visited[currNode] = true;
            sum += currWeight;
            mst.push_back({currParent, currNode});
            for (auto node : adj[currNode]){
                int adjNode = node[0];
                int adjWt = node[1];
                int adjParent = currNode;
                if (!visited[adjNode]){
                    pq.push({adjWt, {adjNode, adjParent}});
                }
            }
        }
    }

    for (auto edge : mst){
        if(edge[0] == -1)continue;
        cout<<edge[0]<<"-"<<edge[1]<<endl;
    }

    return sum;
}
int main() {  
// you can take user input 
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V]; // Adjacency list representation of the graph

    adj[0].push_back({1,2});
    adj[1].push_back({0,2});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});
    adj[2].push_back({4, 2});
    adj[4].push_back({2, 2});
    adj[3].push_back({4, 1});
    adj[4].push_back({3, 1});

    // Adding edges to the graph
    // For each edge, adj[u] contains {v, weight}
    // adj[0].push_back({1, 2}); // Edge from vertex 0 to vertex 1 with weight 4
    // adj[1].push_back({0, 2}); // Edge from vertex 1 to vertex 0 with weight 4

    // adj[1].push_back({2, 5}); // Edge from vertex 0 to vertex 2 with weight 8
    // adj[2].push_back({1, 5}); // Edge from vertex 2 to vertex 0 with weight 8

    // adj[2].push_back({3, 2}); // Edge from vertex 1 to vertex 3 with weight 7
    // adj[3].push_back({2, 2}); // Edge from vertex 3 to vertex 1 with weight 7

    // adj[0].push_back({3, 1});
    // adj[3].push_back({0, 1});
    
    // adj[0].push_back({4, 4}); // Edge from vertex 1 to vertex 4 with weight 9
    // adj[4].push_back({0, 4}); // Edge from vertex 4 to vertex 1 with weight 9

    // adj[4].push_back({5, 3}); // Edge from vertex 2 to vertex 3 with weight 6
    // adj[5].push_back({4, 3}); // Edge from vertex 3 to vertex 2 with weight 6

    // adj[2].push_back({5, 4}); // Edge from vertex 2 to vertex 5 with weight 10
    // adj[5].push_back({2, 4}); // Edge from vertex 5 to vertex 2 with weight 10

    // adj[6].push_back({4, 6}); // Edge from vertex 3 to vertex 4 with weight 5
    // adj[4].push_back({6, 6}); // Edge from vertex 4 to vertex 3 with weight 5
    
    // adj[6].push_back({5, 2}); // Edge from vertex 3 to vertex 4 with weight 5
    // adj[5].push_back({6, 2});
    int totalWeight = spanningTree(V, adj); // Finding the total weight of the MST and printing the MST edges
    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;

    return 0;
}