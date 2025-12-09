template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
        };
        build(1, 0, n);
    }
    void modify(int p, int l, int r, int x, int v1, int v2) {
        auto &S = info[p].s;
        if (S.find(v1) != S.end()) {
            S.erase(v1);
        }
        S.insert(v2);
        if (r - l == 1) {
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v1, v2);
        } else {
            modify(2 * p + 1, m, r, x, v1, v2);
        }
    }
    void modify(int p, int v1, int v2) {
        modify(1, 0, n, p, v1, v2);
    }
    pair<int, int> rangeQuery(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return {0, 0};
        }
        if (l >= x && r <= y) {
            auto &S = info[p].s;
            int res1 = 0, res2 = 0;
            auto it = S.lower_bound(v);
            res1 = distance(S.begin(), it);
            it = S.upper_bound(v);
            if (it != S.end()) {
                res2 = distance(it, S.end());
            }
            return {res1, res2};
        }
        int m = (l + r) / 2;
        auto [x1, y1] = rangeQuery(2 * p, l, m, x, y, v);
        auto [x2, y2] = rangeQuery(2 * p + 1, m, r, x, y, v);
        return {x1 + x2, y1 + y2};
    }
    pair<int, int> rangeQuery(int l, int r, int v) {
        return rangeQuery(1, 0, n, l, r, v);
    }
};
struct Info {
    set<int> s;
};