#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define eb emplace_back
#define printv(a, x) for (int i = x; i < a.size(); i ++ ) \
                      cout << a[i] << " \n"[i == (int)a.size() - 1]
#define printvv(a, x) for (int i = x; i < a.size(); i ++ ) \
                      for (int j = x; j < a[i].size(); j ++ ) \
                        cout << a[i][j] << " \n"[j == (int)a[i].size() - 1]
#define all(x) (x).begin(), (x).end()
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define printd(x, d) cout << fixed << setprecision(d) << (x) << '\n'
#define ne_per(a) next_permutation((a).begin(), (a).end())

template <typename T>
void base_dbg (const std::string& key, const T& value) {
    std::cerr << key << " = " << value;
}
template <typename... Args>
void dbg_args (const std::string& keys, Args... args) {
    size_t pos{ 0 }; ( (base_dbg (keys.substr (pos, keys.find (',', pos) - pos), args),
                        pos = keys.find (',', pos) + 1), ...);
}
#define dbg(...) { \
    std::cerr << ""; \
    dbg_args(#__VA_ARGS__, __VA_ARGS__); \
    std::cerr << '\n'; \
}
template <typename T>
void base_print (const T& value) {
    std::cout << value << ' ';
}
template <typename... Args>
void print_args (Args... args) {
    size_t pos{ 0 }; ( (base_print (args) ), ...);
}
#define print(...) { \
    std::cout << ""; \
    print_args(__VA_ARGS__); \
    std::cout << '\n'; \
}

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using i128 = __int128;

std::mt19937 rnd (std::chrono::steady_clock().now().time_since_epoch().count() );

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

void solve() {
}

signed main() {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    int t;
    cin >> t;
    // t = 1;
    while (t -- ) solve();
    return 0;
}