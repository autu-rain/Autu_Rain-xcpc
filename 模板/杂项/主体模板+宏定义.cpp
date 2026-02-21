#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int>>,
           __gnu_pbds::rb_tree_tag,
           __gnu_pbds::tree_order_statistics_node_update>
           rbt;
// order_of_key(x) 返回严格小于x的元素的个数
// find_by_order(x) 返回排名为x的元素的迭代器

// c++位操作内置函数
// __builtin_ffs(x), 与__lg(lowbit(x)) + 1的值相等
// __builtin_clz(x), 返回前缀0的个数
// __builtin_ctz(x), 返回后缀0的个数
// __builtin_popcount(x), x的二进制表示中1的个数
// __builtin_parity(x), x的二进制表示中1的个数的奇偶

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

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using i128 = __int128;

std::mt19937 rnd (std::chrono::steady_clock().now().time_since_epoch().count());

void solve() {
}

signed main() {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    int t = 1;
    // cin >> t;
    while (t -- ) {
        solve();
    }
    return 0;
}