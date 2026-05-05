#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int n) {
        this->n = n;
        adj.resize(n);
        visited.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void resetVisited() {
        for (int i = 0; i < n; i++)
            visited[i] = false;
    }

    // DFS
    void dfs(int v) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u);
        }
    }

    // BFS
    void bfs(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int ch, start;

    do {
        cout << "\n--- GRAPH MENU ---\n";
        cout << "1. DFS\n";
        cout << "2. BFS\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter start vertex: ";
                cin >> start;
                g.resetVisited();
                cout << "DFS: ";
                g.dfs(start);
                cout << endl;
                break;

            case 2:
                cout << "Enter start vertex: ";
                cin >> start;
                g.resetVisited();
                cout << "BFS: ";
                g.bfs(start);
                cout << endl;
                break;
        }

    } while (ch != 0);

    return 0;
}
