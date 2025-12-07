// 第一关键字满足中序遍历按cmp1序, 第二关键字满足小根堆(less)/大根堆(greater)
struct Node {
    int l = -1, r = -1;
};
template<class T1, class T2, class Cmp1 = less<T1>, class Cmp2 = less<T2>>
struct CartesianTree {
    vector<T1> a;
    vector<T2> b;
    vector<int> p;
    vector<Node> t;
    int n;

    void init(const vector<pair<T1, T2>> &q) {
        n = q.size();
        for (auto [x, y] : q) {
            a.push_back(x);
            b.push_back(y);
        }
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        Cmp1 cmp1;
        sort(p.begin(), p.end(), [&](int i, int j) {
            return cmp1(a[i], a[j]);
        });
        t.assign(n, Node{});
        vector<int> stk;
        Cmp2 cmp2;
        for (int i = 0; i < n; i++) {
            int x = p[i], lst = -1;
            while (stk.size() && cmp2(b[x], b[stk.back()])) {
                lst = stk.back();
                stk.pop_back();
            }
            if (stk.size()) {
                t[stk.back()].r = x;
            }
            t[x].l = lst;
            stk.push_back(x);
        }
    }

    CartesianTree(const vector<pair<T1, T2>> &q) {
        init(q);
    }

    vector<Node> work() {
        return t;
    }
};