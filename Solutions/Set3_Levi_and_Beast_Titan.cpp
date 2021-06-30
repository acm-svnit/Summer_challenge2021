#include <iostream>
#include <algorithm>
using namespace std;
 
int n, k, s, t, l, r = 2e9, ans = 2e9, m, c[200100], v[200100], a[200100];
 
bool check(int x) {
    int y, z = 0;
    for (int i = 1; i <= k; ++i) {
        y = a[i] - a[i - 1];
        if (x < y)return 0;
        z += y * 2 - min(y, x - y);
    }
    return z <= t;
}
 
int main() {
    cin >> n >> k >> s >> t;
    for (int i = 0; i < n; ++i)
        scanf("%d%d", c + i, v + i);
    for (int i = 1; i <= k; ++i)
        scanf("%d", a + i);
    a[++k] = s;
    sort(a, a + k + 1);
    while (l < r) {
        m = l + (r - l) / 2;
        if (check(m))r = m;
        else l = m + 1;
    }
    for (int i = 0; i < n; ++i)
        if (v[i] >= l && c[i] < ans)ans = c[i];
    if (ans == 2e9)return cout << -1, 0;
    cout << ans;
}