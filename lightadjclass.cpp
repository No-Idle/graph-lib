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

void bind_or(basic_vertex *a, basic_vertex *b) {
    a->neibh.push_back(b);
}

void remove(basic_vertex *a, basic_vertex *b) {
    auto i1 = find(a->neibh.begin(), a->neibh.end(), b);
    auto i2 = find(b->neibh.begin(), b->neibh.end(), a);
    a->neibh.erase(i1);
    b->neibh.erase(i2);
}

void remove_or(basic_vertex *a, basic_vertex *b) {
    a->neibh.erase(find(a->neibh.begin(), a->neibh.end(), b));
}

bool has_cycle(basic_vertex *v)
{
    v->used = GRAY;
    for (auto &u : v->neibh) {
        if (u->used == WHITE) {
            if (dfs(u)) return true;
        } else if (u->used == GRAY)
            return true;
    }
    v->used = BLACK;
    return false;
}
