#define WHITE 0
#define GRAY  1
#define BLACK 2
using namespace std;
constexpr size_t MAIN_SIZE = 64;

struct basic_vertex {
    int x;
    int used;
    vector<Vertex *> neibh;
    basic_vertex(int a) : x(a), used(WHITE)
        { neibh.reserve(MAIN_SIZE); }
};

class Vertex : public basic_vertex {
    Vertex(int a) : basic_vertex(a)
        {}
    vector<int> weight;
    Vertex *parent;
};

void bind(basic_vertex *a, basic_vertex *b) {
    a->neibh.push_back(b);
    b->neibh.push_back(a);
}

void dfs(basic_vertex *v) {
    v->used = BLACK;
    for (Vertex * &u : v->neibh)
        if (u->used = WHITE)
            dfs(u);
}
