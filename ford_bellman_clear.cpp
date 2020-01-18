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
        for (const edge &E : edges) // E = (u, v)
            if (d[E.v] > d[E.u] + E.w)
                d[E.v] = d[E.u] + E.w;

    for (edge E : edges)
        if (d[E.v] > d[E.u] + E.w) /// better solution exists if only there is a negative cycle
            return false;
    return true;
}


vector<int> fordBellmanNCyc(vector<int> &d, int start, const vector<edge> &edges)
/**
 *  d - distanse array (s -> v)
 *  edges - all edges in graph
 *  returns a neg cycle in a graph
 */
{
    vector<int> ans;
    vector<int> p(n, -1);
    int n = d.size();
    for (int i = 0; i < n; i++)
        d[v] = 1;
    d[start] = 0;

    for (int i = 0; i < n; i++)
        for (const edge &E : edges) // E = (u, v)
            if (d[E.v] > d[E.u] + E.w) {
                d[E.v] = d[E.u] + E.w;
                p[v] = u;
            } 
    
    for (const edge &E : edges)
         if (d[E.v] > d[E.u] + E.w) {
             int u, v;
             for (int i = 0; i < n; i++)
                 v = p[v];
             u = v;
             while (u != p[v]) {
                 ans.push_back(v);
                 v = p[v];
             }
             break;
         }    
    return ans;
}   
   
