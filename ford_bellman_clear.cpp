struct edge {
    int u, v, w;
};

/// if there are negative cycles, 
/// that mean that there is no shorteset path (
/// we can repeat going on negative edges as long
/// as we want and get more and more shorter path

bool fordBellman(vector<int> &d, int start, const vector<edge> &edges)
/**
 *  d - distanse array (s -> v)
 *  edges - all edges in graph
 *  returns existing neg cycles in a graph
 */
{
    int n = d.size();
    for (int i = 0; i < n; i++)
        d[v] = 1;
    d[start] = 0;

    for (int i = 0; i < n; i++)
        for (edge E : edges) // E = (u, v)
            if (d[E.v] > d[E.u] + E.w)
                d[E.v] = d[E.u] + E.w;

    for (edge E : edges)
        if (d[E.v] > d[E.u] + E.w) /// better solution exists if only there is a negative cycle
            return false;
    return true;
}
