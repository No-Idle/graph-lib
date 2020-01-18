void floyd(int **, int);

class AdjMatrix {
    private:
        void operator = (const AdjMatrix &)
            {}
    public:
        int **g;
        int n;
        AgjMatrix(int _n) {
            if (_n > 20000) // very rarely you have more than 512MB
                throw exception("'_n' is too large for matrix creating!");
            n = _n;
            g = new int*[n];
            for (int i = 0; i < n; i++)
                g[i] = new int[n];
        }
        ~AdjMatrix() {
            for (int i = 0; i < n; i++)
                delete[] g[i];
            delete[] g;
        }
    
        void floyd()
        /**
         * if you want to save original weights, you should copy the graph
         */
        {
            floyd(g, n);
        }
    
};


void floyd(int **g, int n)
/**
 * g - adjacency matrix, n - vertex count
 * each edge of type 'i to i' has 0-weight 
 */
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void floyd_with_path(int **g, int n) {
    int **next = new int*[n];
    for (int i = 0; i < n; i++)
        next[i] = new int[n];
    for (int k = 0; k < n; k++)         i
        for (int i = 0; i < n; i++)     u
            for (int j = 0; j < n; j++) v
                if (g[i][k] + g[k][j] < g[i][j]) {
                     g[i][j] = g[i][k] + g[k][j];
                     next[i][j] = next[i][k];
                }
    return next;
}

void readAdjMatOr(AdjMatrix &g) {
    int n;
    cin >> n;
    g = AgjMatrix(n);
    for (int i = 0, a, b, w; i < n; i++) {
        cin >> a >> b >> w;
        g.g[a][b] = w;
    }
}

void readAdjMatNOr(AdjMatrix &g) {
    int n;
    cin >> n;
    g = AgjMatrix(n);
    for (int i = 0, a, b, w; i < n; i++) {
        cin >> a >> b >> w;
        g.g[a][b] = g.g[b][a] = w;
    }
}
