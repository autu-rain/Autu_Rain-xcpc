struct DSU {
	std::vector<std::pair<int &, int>> his;

	int n;
	std::vector<int> f, g;

	DSU(int n_) : n(n_), f(n, -1), g(n) {}

	std::pair<int, int> find(int x) {
		if (f[x] < 0) {
			return {x, 0};
		}
		auto [u, v] = find(f[x]);
		return {u, v ^ g[x]};
	}

	void set(int &a, int b) {
		his.emplace_back(a, a);
		a = b;
	}

	void merge(int a, int b, int &ans) {
		auto [u, xa] = find(a);
		auto [v, xb] = find(b);
		int w = xa ^ xb ^ 1;
		if (u == v) {
			return;
		}
		if (f[u] > f[v]) {
			std::swap(u, v);
		}
		set(f[u], f[u] + f[v]);
		set(f[v], u);
		set(g[v], w);
	}

	int timeStamp() {
		return his.size();
	}

	void rollback(int t, int &ans) {
		while (his.size() > t) {
			auto [x, y] = his.back();
			x = y;
			his.pop_back();
		}
	}
};