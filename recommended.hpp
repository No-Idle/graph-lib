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
    vector<bool> points; //pointofcondensing
    
    Graph(int _n) {
        n = _n;
        g = vector<vector<int>>(n);
        used = vector<int>(n);
        dist = vector<int>(n, INT_MAX);
    }
    Graph(int _n, bool w, bool po, bool br) {
        n = _n;
        g = vector<vector<int>>(n);
        used = vector<int>(n);
        dist = vector<int>(n, INT_MAX);
        if (w) ways = vector<vector<int>>(n);
        if (po) points = vector<bool>(n);
    }
    void clearused() {
        used.clear();
        used = vector<int>(n);
    }
    void cleardist() {
        dist.clear();
        dist = vector<int>(n);
    }
    void addNDir(int v, int u) {
        g[v].push_back(u);
    }
    void addDir(int v, int u) {
        g[v].push_back(u);
        g[u].push_back(v);    
    }
    
    void dfs(int);
    void bfs(int);
    void find_bridges(int);
    void points_con(int);
    void djiksta(int, int);
    void floyd(int, int);
    void condense(int);
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

void readGr(Graph &g) {
    int n, m;
    cin >> n >> m;
    g = Graph(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g.addDir(a, b);
    }
}


int up[100000];
int depth[100000];
vector<pair<int, int>> ans;

void Graph::find_bridges(int v, int pr = -1) {
    used[v] = true;
    up[v] = depth[v];
    for (int c : g[v])
        if (!used[c])
            depth[c] = depth[v] + 1;
    for (int to : g[v]) {
        if (to == pr)
            continue;
        if (!used[to])
            find_bridges(to, v);
        up[v] = min(up[v], up[to]);
    }
    if (up[v] == depth[v] && pr != -1) {
        ans.push_back({v, pr});
    }
}
