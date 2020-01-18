#define int long long

struct Edge {
    int u, v, weight;
    friend istream &operator >> (istream &is, Edge &e) {
        is >> e.u >> e.v >> e.weight;
        --e.u, --e.v;
        return is;
    }
};

void Ford_Bellman(void) {
    int n, m;
    cin >> n >> m;
    vector<int> dist(n, -1e18);
    vector<int> prev(n);
    vector<Edge> edges(m);
    cin >> edges;
    dist[0] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (auto e : edges)
            if (dist[e.v] < dist[e.u] + e.weight) {
                dist[e.v] = dist[e.u] + e.weight;
                prev[e.v]= e.u;
            }

    /// if we have not got negative cycles then all evaluated
    Vertex *end = nullptr;
    for (auto e : edges)
        if (e.second->dist > e.first->dist + weight[e.first, e.second])
            end = e.second;
    for (int i = 0; i < n; ++i)
        end = end->pred;
    Vertex *p = end;
    while (p != end) {
        cout << p;
        p = p->pred;
    }
}
