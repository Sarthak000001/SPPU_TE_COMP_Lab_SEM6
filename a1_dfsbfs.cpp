// Problem Statement :
// Implement depth first search (DFS) algorithm and breadth first search
// (BFS) algorithm. Use an application for undirected graph and develop a
// recursive algorithm for searching all the vertices of a graph or tree data
// structure. Also print the levels as it traverses for both algorithms.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int size;
    vector<int> *adj;
public:
    Graph(int size)
    {
        this->size = size;
        adj = new vector<int>[size];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int start)
    {
        queue<int> q;
        vector<int> visit(size, 0);
        q.push(start);
        visit[start] = 1;
        int depth = 0;
        while (!q.empty())
        {
            int qsize = q.size();
            while (qsize-- > 0)
            {
                int curr = q.front();
                q.pop();
                cout << "Visited " << curr << " at depth " << depth << endl;
                for (int it : adj[curr])
                {
                    if (visit[it] == 0)
                    {
                        q.push(it);
                        visit[it] = 1;
                    }
                }
            }
            depth++;
        }
    }
    void DFS(int node, vector<int> &visit,int depth)
    {
        visit[node] = 1;
        cout << "Visited " << node << " at depth " << depth << endl;
        for(int it : adj[node]){
            if(visit[it] == 0){
                DFS(it,visit,depth+1);
            }
        }
    }
    void DFS_(int start){
        vector<int>visit(size,0);
        DFS(start,visit,0);
    }
   void bfs_recursive(queue<int> &q,vector<int>&visit,int depth)
   {
       if (q.empty()){
            return;
       }

       int qsize = q.size();
       while(qsize-- > 0){
            int curr = q.front();
            q.pop();
           cout << "Visited " << curr << " at depth " << depth << endl;
            for (auto i : adj[curr])
            {
                if (visit[i] == 0)
                {
                    visit[i] = 1;
                    q.push(i);
                }
            }
       }
       depth++;
       bfs_recursive(q,visit,depth);
   }
   void bfs_recursive_(int start){
        queue<int>q;
        vector<int>visit(size,0);
        q.push(start);
        visit[start] = 1;
        cout << "BFS recursive : " << endl;
        bfs_recursive(q,visit,0);
   }

};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    cout << "BFS iterative : \n";
    g.BFS(0);
    cout << "\n\n";
    cout << "DFS : \n";
    g.DFS_(0);
    cout << "\n\n";
    cout << "BFS recursive : ";
    g.bfs_recursive_(0);
}