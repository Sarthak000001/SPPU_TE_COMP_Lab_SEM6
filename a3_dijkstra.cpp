/*
Dijkstra's algorithm is a single-source shortest path algorithm. It computes the shortest
path from a given start (or source) node to all other nodes in a weighted graph with
non-negative edge weights. The algorithm is widely used because it efficiently finds
the shortest path tree from the starting node, providing the minimum distance to every 
other reachable node in the graph.
*/
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> dist, int src)
{
    cout << "Distance of vertex from source  " << src << " : ";
    cout << "Vertex"
         << "\t\t"
         << "distance" << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(V, INT_MAX);

    ans[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currNodeMinDist = pq.top().first;
        pq.pop();
        for (auto edge : adj[currNode])
        {
            int node = edge[0];
            int newDist = currNodeMinDist + edge[1];
            if (newDist < ans[node])
            {
                ans[node] = newDist;
                pq.push({newDist, node});
            }
        }
    }

    return ans;
}

int main()
{

    int V;
    cout << "Enter no. of vertices : ";
    cin >> V;

    vector<vector<int>> adj[V];
    for (int i = 0; i < V; i++)
    {
        int k, v, wt;
        cout << "No. of adjacent node to " << i << " : ";
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cout << "Enter V : ";
            cin >> v;
            cout << "Enter weight of (" << i << "," << v << ") : ";
            cin >> wt;
            adj[i].push_back({v, wt});
        }
    }
    vector<int> ans = dijkstra(V, adj, 0);
    print(ans, 0);
    return 0;
}