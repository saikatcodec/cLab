#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on

int main() {
    FIO;

    ll n, m;
    cin >> n >> m;

    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll low = 0, high = 1e18;
    while (low < high) {
        ll mid = (low + high + 1) / 2;

        ll dif = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= mid) {
                dif = (arr[i] - mid) + dif;
            }
        }

        if (dif >= m) {
            low = mid;
        } else if (dif < m) {
            high = mid - 1;
        }
    }

    cout << low << nl;

    return 0;
}

/**
 * low = 7 high = 8
 * mid is always 7 so we use (mid = (low + high + 1) / 2)
 *
 * t t t t f f f f - binary search format
 * 20 25 30 -  20
 * low = 0 high = 100
 *
 *
 * t t t f f f
    * for Maximum
    * low = mid (for true)
    * high = mid - 1;
    * low = 7 high = 8
    * mid = (low + high) / 2
    * mid = 7
    * if condition is true, low = 7
    * else, high = 6
    * 
    * so, mid = (low + high + 1) / 2  --> correct
    * mid = 8
    * if codition is true, low = 8
    * else, high = 7
 *
 * f f f t t t
    * for minimum
    * low = mid + 1
    * high = mid (for true)
    * mid = (low + high) / 2 --> correct
    * low = 7 high = 8
    * mid = 7
    * if condition is true, high = 7
    * else, low = 8
 */
