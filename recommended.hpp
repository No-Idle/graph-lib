#include <bits/stdc++.h>
using namespace std;
#define BLACK 2
#define GRAY  1
#define WHITE 0

#define vertex first
#define weight second
struct Graph {
    int n;
    vector<vector<int>> g;
    vector<vector< pair<int, int> >> gw;
    vector<int> used;

    vector<int> dist;
    vector<vector<int>> ways;
    vector<bool> points; //pointofcondensing;
    vector<bool> bridges;

    Graph(int _n) {
        n = _n;
        g = vector<vector<int>>(n);
        used = vector<int>(n);
        dist = vector<int>(n);
    }
    Graph(int _n, bool w, bool po, bool br) {
        n = _n;
        g = vector<vector<int>>(n);
        used = vector<int>(n);
        dist = vector<int>(n);
        if (w) ways = vector<vector<int>>(n);
        if (po) points = vector<bool>(n);
        if (br) bridges = vector<bool>(n);
    }
    void clearused() {
        used.clear();
        used = vector<int>(n);
    }
    void addNDir(int v, int u) {
        g[v].push_back(u);
    }
    void addDir(int v, int u) {
        g[v].push_back(u);
        g[u].push_back(v);    
    }
    
    void dfs(int v);
    void bfs(int s);
    void find_bridges(int s);
    void points_con(int v);
    void djiksta(int v, int u);
    void floyd(int v, int u);
    void condense(int v);
    bool hascycle();
    int  shortestcycle();
};

void Graph::dfs(int v) {
    used[v] = BLACK;
    for (int u : g[v])
        if (used[u] == WHITE)
            dfs(u);
}

void Graph::bfs(int s) {
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v])
            if (dist[u] == INT_MAX) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }        
}

