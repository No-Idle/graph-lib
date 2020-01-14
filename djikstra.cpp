typedef vector<vector<pair<int, int>>> graph;
constexpr int INF = INT_MAX;

vector<int> djkstra(graph g, int s, vector<int> prev = {})
{
    int n = d.size();
    vector<int> d(n, INF);    
    vector<bool> used(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        used[v] = true;
 
        for (int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first;
            int len = g[v][j].second;
            if (d[v] + wg < d[to]) {
                d[to] = d[v] + wg;
                if (prev.size())
                    prev[to] = v;
            }
        }
    }
    return d;
}
