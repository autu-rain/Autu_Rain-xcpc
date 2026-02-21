constexpr int N = 5005;
template<class T>
struct List {
    int e[N], l[N], r[N];
    int idx;

    void init() {
        idx = 2;
        r[0] = 1;
        l[1] = 0;
    }

    List() {
        init();
    }

    void insert(int k, const T& x) {
        e[idx] = x;
        l[idx] = k;
        r[idx] = r[k];
        l[r[k]] = idx;
        r[k] = idx++;
    }

    void remove(int k) {
        l[r[k]] = l[k];
        r[l[k]] = r[k];
    }
};