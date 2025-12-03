#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;  // (neighbor, weight)

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected)
            adj[v].push_back({u, w});
    }
};
void BFS(Graph &g, int start) {
    vector<bool> visited(g.V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto &p : g.adj[node]) {
            int neighbor = p.first;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
void DFSUtil(int node, vector<bool>& visited, Graph &g) {
    visited[node] = true;
    cout << node << " ";

    for (auto &p : g.adj[node]) {
        int neighbor = p.first;
        if (!visited[neighbor])
            DFSUtil(neighbor, visited, g);
    }
}

void DFS(Graph &g, int start) {
    vector<bool> visited(g.V, false);
    cout << "DFS: ";
    DFSUtil(start, visited, g);
    cout << endl;
}
struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (rankv[x] < rankv[y])
                parent[x] = y;
            else if (rankv[x] > rankv[y])
                parent[y] = x;
            else {
                parent[y] = x;
                rankv[x]++;
            }
        }
    }
};

void Kruskal(Graph &g) {
    vector<Edge> edges;

    for (int u = 0; u < g.V; u++)
        for (auto &p : g.adj[u]) {
            int v = p.first, w = p.second;
            if (u < v)
                edges.push_back({u, v, w});
        }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    DSU dsu(g.V);

    cout << "Kruskal MST edges:\n";
    int totalWeight = 0;

    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unionSet(e.u, e.v);
            cout << e.u << " -- " << e.v << " (weight " << e.w << ")\n";
            totalWeight += e.w;
        }
    }

    cout << "Total Weight of MST = " << totalWeight << "\n\n";
}
void Prim(Graph &g, int start) {
    vector<int> key(g.V, INT_MAX);
    vector<bool> inMST(g.V, false);
    vector<int> parent(g.V, -1);

    key[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});   // (weight, node)

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto &p : g.adj[u]) {
            int v = p.first;
            int wt = p.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({wt, v});
            }
        }
    }

    cout << "Prim MST edges:\n";
    int totalWeight = 0;

    for (int i = 0; i < g.V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " -- " << i 
                 << " (weight " << key[i] << ")\n";
            totalWeight += key[i];
        }
    }

    cout << "Total Weight of MST = " << totalWeight << "\n\n";
}
void Dijkstra(Graph &g, int src) {
    vector<int> dist(g.V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});   // (distance, node)

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &p : g.adj[u]) {
            int v = p.first;
            int wt = p.second;

            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra shortest distances from " << src << ":\n";
    for (int i = 0; i < g.V; i++)
        cout << "Node " << i << " = " << dist[i] << endl;
    cout << endl;
}
int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    BFS(g, 0);
    DFS(g, 0);

    Kruskal(g);
    Prim(g, 0);

    Dijkstra(g, 0);

    return 0;
}
