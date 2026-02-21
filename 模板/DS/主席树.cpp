constexpr int inf = 1E9;
template <class Info>
struct PersistentSegmentTree {
    int n, idx;
    struct Node {
        int l = 0, r = 0;
        Info info = Info{};
    };
    vector<Node> tr;
    vector<int> root;
    void init(int n_) {
        idx = 0;
        n = n_;
        tr.assign(n_ << 5, Node{});
        root.assign(n_ + 1, 0);
    }
    PersistentSegmentTree(int n_) {
        init (n_);
    }
    void insert(int p, int &q, int l, int r, int x, const Info &v) {
        q = ++idx;
        tr[q] = tr[p];
        if (r - l == 1) {
            tr[q].info.apply(x, v);
            return;
        }
        int m = l + r >> 1;
        if (x < m) {
            insert(tr[p].l, tr[q].l, l, m, x, v);
        } else {
            insert(tr[p].r, tr[q].r, m, r, x, v);
        }
        pull(q);
    }
    void insert(int i, int x, const Info &v = Info{}) {
        insert(root[i], root[i + 1], -inf, inf + 1, x, v);
    }
    void pull(int q) {
        tr[q].info = tr[tr[q].l].info + tr[tr[q].r].info;
    }
    Info rangeQuery(int p, int q, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info{};
        }
        if (l >= x && r <= y) {
            return tr[q].info - tr[p].info;
        }
        int m = l + r >> 1;
        return rangequery(tr[p].l, tr[q].l, l, m, x, y) + rangequery(tr[p].r, tr[q].r, m, r, x, y);
    }
    Info rangeQuery(int l, int r, int x, int y) {
        return rangeQuery(root[l + 1], root[r + 1], -inf, inf + 1, x, y);
    }
    template <class F>
    int findFirst(int p, int q, int l, int r, int x, F pred) {
        if (r - l == 1) {
            return l;
        }
        int m = l + r >> 1;
        if (pred(tr[tr[p].l].info, tr[tr[q].l].info, x)) {
            return findFirst(tr[p].l, tr[q].l, l, m, x, pred);
        } else {
            return findFirst(tr[p].r, tr[q].r, m, r, x, pred);
        }
    }
    template <class F>
    int findFirst(int l, int r, int x, F pred) {
        return findFirst(root[l + 1], root[r + 1], -inf, inf + 1, x, pred);
    }
    template <class F>
    int findLast(int p, int q, int l, int r, int x, F pred) {
        if (r - l == 1) {
            return l;
        }
        int m = l + r >> 1;
        if (pred(tr[tr[p].r].info, tr[tr[q].r].info, x)) {
            return findFirst(tr[p].r, tr[q].r, m, r, x, pred);
        } else {
            return findFirst(tr[p].l, tr[q].l, l, m, x, pred);
        }
    }
    template <class F>
    int findLast(int l, int r, int x, F pred) {
        return findLast(root[l + 1], root[r + 1], -inf, inf + 1, x, pred);
    }
};
struct Info {
    int val = 0;
    void apply (int x, const Info &v) {
        val += v.val;
    }
};
Info operator+ (const Info &a, const Info &b) {
    return {a.val + b.val};
}
Info operator- (const Info &a, const Info &b) {

}