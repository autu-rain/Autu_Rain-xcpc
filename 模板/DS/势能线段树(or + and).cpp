template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeAnd(int p, int l, int r, int x, int y, const Info &v) {
        i64 vor = info[p].vor, vand = info[p].vand;
        if (r <= x || l >= y || (vor & v.vor) == vor) {
            return;
        }
        i64 mask = vor ^ vand;
        if (l >= x && r <= y && (mask | v.vor) == v.vor) {
            i64 val = (vand & v.vor) - vand;
            apply(p, {val});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeAnd(2 * p, l, m, x, y, v);
        rangeAnd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeAnd(int l, int r, const Info &v) {
        rangeAnd(1, 0, n, l, r, v);
    }
    void rangeOr(int p, int l, int r, int x, int y, const Info &v) {
        i64 vor = info[p].vor, vand = info[p].vand;
        if (r <= x || l >= y || (vand | v.vor) == vand) {
            return;
        }
        i64 mask = vor ^ vand;
        if (l >= x && r <= y && !(mask & v.vor)) {
            i64 val = (vand | v.vor) - vand;
            apply(p, {val});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeOr(2 * p, l, m, x, y, v);
        rangeOr(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeOr(int l, int r, const Info &v) {
        rangeOr(1, 0, n, l, r, v);
    }
};

struct Tag {
    i64 x = 0;
    void apply(Tag t) {
        x += t.x;
    }
};

struct Info {
    i64 vor = 0, vand = 0;
    void apply(Tag t) {
        vor += t.x;
        vand += t.x;
    }
};
Info operator+(Info a, Info b) {
    Info c;
    c.vor  = a.vor | b.vor;
    c.vand = a.vand & b.vand;
    return c;
}