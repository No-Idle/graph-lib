typedef vector<vector<pair<int, int>>> graph;
constexpr int INF = INT_MAX;

vector<int> djkstra(graph &g, int s, vector<int> &prev)
/** Complexity: O(n ^ 2 + m)
 */
{
    int n = g.size();
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
            int wg = g[v][j].second;
            if (d[v] + wg < d[to]) {
                d[to] = d[v] + wg;
                prev[to] = v;
            }
        }
    }
    return d;
}


vector<int> djkstra_fast(vector<vector<pair<int, int>>> &g, int s, vector<int> &prev)
/**  Complexity: O(n log(n) + m log(n))
 */
{
    int n = g.size();
    vector<int> d(n, INF);
    d[s] = 0;    
    set<pair<int, int>> unused;
    for (int i = 0; i < n; i++)
        unused.insert({d[i], i}); // (val, index)
    for (int i = 0; i < n; i++) {
        int v = unused.begin()->second; // index of v
        unused.erase(unused.begin());
        for (pair<int, int> &u : g[v]) {
            int to = u.first, wg = u.second;
            if (d[v] + wg < d[to]) {
                unused.erase(unused.find({d[to], to}));
                d[to] = d[v] + wg;
                prev[to] = v;
                unused.insert({d[to], to});
            }
        }
    }
    return d;
}


/**
  n - vertex count
  m - edges count

  What algorithm should you use?
  basic: O(n ^ 2 + m)
  fast: O(n log(n) + m log(n))
  
  So, m <= n(n - 1) if there are not multiple edges 
      (if they are, you should just choose an edge with min weight between each pair of vertexes)

  So, we get an equation:
    n ^ 2 + m = n log(n) + m log(n)
  
  The solution is:
    m = n(n - log(n)) / (log(n) - 1)
  
  So, we have 2 cases:
     * m < n(n - log(n)) / (log(n) - 1)  ==>
         fast algorithm is optimal
     * m > n(n - log(n)) / (log(n) - 1)  ==>
         basic algorithm is optimal    (for example imagine m ~ n ^ 2, then: first (basic) 
                                           algorithm is O(n ^ 2) and second (fast) is O(log(n) n ^ 2)

*/

