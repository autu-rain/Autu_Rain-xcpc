template<u32 P = 131>
struct StringHash {
    vector<u32> p, h;
    int n;
    StringHash(int n_ = 1) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
        }
    }

    void setString(string s) {
        if (s.size() > n) {
            n = s.size();
            init(n);
        }
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s[i - 1];
        }
    }

    u32 operator()(int l, int r) {
        return h[r + 1] - h[l] * p[r - l + 1];
    }
};