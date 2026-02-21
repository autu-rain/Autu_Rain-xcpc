auto Lagrange = [&](int k) {
    Z ans = 0;
    for (int i = 0; i < n; i++) {
        Z res = y[i];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            res *= (k - x[j]) / (x[i] - x[j]);
        }
        ans += res;
    }
    return ans;
};