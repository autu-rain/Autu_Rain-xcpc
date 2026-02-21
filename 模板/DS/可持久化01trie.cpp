template <class Info, size_t V = 30>
struct Persistent01Trie {
    struct Node {
        array<int, 2> ch;
        Info info =Info{};
    };
    int n, idx;
    vector<Node> tr;
    vector<int> root;
    void init(int n_) {
        idx = 0;
        tr.assign(V * n_ * 2, Node{});
        root.assign(n_ + 1, 0);
    }
    Persistent01Trie(int n_) : n(n_) {
        init(n_);
    }
    void pull(int q) {
        tr[q] = tr[tr[q].ch[0]].info + tr[tr[q].ch[1]].info;
    }
    void insert(int k, int p, int &q, int x, const Info &v) {
        q = ++ idx;
        tr[q] = tr[p];
        if (k < 0) {
            tr[q].info.apply(v);
            return;
        }
        int u = x >> k & 1;
        tr[q].ch[u ^ 1] = tr[p].ch[u ^ 1];
        insert(k - 1, tr[p].ch[u], tr[q].ch[u], x, v);
        pull(q);
    }
    void insert(int i, int x, const Info &v = Info{}) {
        insert(V, root[i], root[i + 1], x, v);
    }
    template <class F>
    i64 find(int k, int p, int q, int x, F pred) {
        if (k < 0) {
            return 0ll;
        }
        int u = x >> k & 1;
        if (pred(tr[tr[p].ch[u ^ 1]].info, tr[tr[q].ch[u ^ 1]].info)) {
            return find(k - 1, tr[p].ch[u ^ 1], tr[q].ch[u ^ 1], x, pred) + (1ll << k);
        } else {
            return find(k - 1, tr[p].ch[u], tr[q].ch[u], x, pred);
        }
    }
    template <class F>
    i64 find(int l, int r, int x, F pred) {
        return find(V, root[l + 1], root[r + 1], x, pred);
    }
};

struct Info {
    int val;
    void apply(const Info &v) {

    }
};

Info operator+(const Info &a, const Info &b) {

}