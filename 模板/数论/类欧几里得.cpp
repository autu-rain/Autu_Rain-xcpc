template<class T>
struct EuclideanLike {
    struct Data {
        T f = T(), g = T(), h = T();
    };
    // Z i2 = Z(1) / 2, i6 = Z(1) / 6;
    Data work(i64 a, i64 b, i64 c, i64 n) {
        Data ans;
        i64 m = (a * n + b) / c, ac = a / c, bc = b / c;

        if (!a) {
            ans.f = T(n + 1) * bc;
            ans.g = T(n) * (n + 1) / 2 * bc;
            ans.h = T(n + 1) * bc * bc;
            return ans;
        }

        if (a >= c || b >= c) {
            ans.f = T(n) * (n + 1) / 2 * ac + T(n + 1) * bc;
            ans.g = T(n) * (n + 1) * (2 * n + 1) / 6 * ac + T(n) * (n + 1) / 2 * bc;
            ans.h = T(n) * (n + 1) * (2 * n + 1) / 6 * ac * ac + T(n + 1) * bc * bc + T(n) * (n + 1) * ac * bc;

            Data d = work(a % c, b % c, c, n);

            ans.f += d.f;
            ans.g += d.g;
            ans.h += d.h + 2 * bc * d.f + 2 * ac * d.g;
            return ans;
        }

        Data d = work(c, c - b - 1, a, m - 1);
        ans.f = T(n) * m - d.f;
        ans.g = T(n) * m * (n + 1) / 2 - (d.h + d.f) / 2;
        ans.h = T(n) * m * (m + 1) - 2 * d.g - 2 * d.f - ans.f;
        return ans;
    }
};