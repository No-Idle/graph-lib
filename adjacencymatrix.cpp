void floyd(int **, int);

class AdjMatrix {
    private:
        void operator = (const AdjMatrix &)
            {}
    public:
        int **g;
        int n;
        AgjMatrix(int _n) {
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
