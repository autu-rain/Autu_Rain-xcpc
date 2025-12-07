template<class Info, class Tag>
struct Splay {
    struct Node {
        array<int, 2> ch;
        int p;
        Info val;
        Tag v;
    };
    int root, idx;
    vector<Node> t;
    void pull(int x) {
        t[x].val = t[t[x].ch[0]].val + t[t[x].ch[1]].val;
    }
    void apply(int x, const Tag &v) {
        t[x].val.apply(v);
        t[x].v.apply(v);
    }
    void push(int x) {
        apply(t[x].ch[0], t[x].v);
        apply(t[x].ch[1], t[x].v);
        t[x].v = Tag();
    }
    void rotate(int x) {
        int y = t[x].p, z = t[y].p;
        int k = t[y].ch[1] == x;  // k=0表示x是y的左儿子；k=1表示x是y的右儿子
        t[z].ch[t[z].ch[1] == y] = x;
        t[x].p = z;
        t[y].ch[k] = t[x].ch[k ^ 1];
        t[t[x].ch[k ^ 1]].p = y;
        t[x].ch[k ^ 1] = y;
        t[y].p = x;
        pull(y);
        pull(x);
    }
    void splay(int x, int k) { //x转到k的子节点
        while (t[x].p != k) {
            int y = t[x].p, z = t[y].p;
            if (z != k) {
                if ((t[y].ch[1] == x) ^ (t[z].ch[1] == y)) {
                    rotate(x);
                } else {
                    rotate(y);
                }
            }
            rotate(x);
        }
        if (!k) {
            root = x;
        }
    }
    int find(int k) {
        int u = root;
        while (u) {
            push(u);
            if (t[t[u].ch[0]].val.sz >= k) {
                u = t[u].ch[0];
            } else if (t[t[u].ch[0]].val.sz + 1 == k) {
                return u;
            } else {
                k -= t[t[u].ch[0]].val.sz + 1;
                u = t[u].ch[1];
            }
        }
        return -1;
    }
};
struct Tag {
    int cnt;
    void apply(Tag t) {
        cnt += t.cnt;
    }
};
struct Info {
    int sum, sz, sz1;
    void apply(Tag t) {
        sz += t.cnt;
    }
};
Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sz = a.sz + b.sz + 1;
    c.sz1 = a.sz1 + b.sz1 + 1;
    c.sum = a.sum + b.sum;
    return c;
}