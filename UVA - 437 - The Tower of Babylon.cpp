#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n, x, y, z, dp[200][200];
vector < pair<int, pair<int, int> > > vec;

int solve(int p, int q, int pre, int idx)
{
    if (idx == n * 6)
        return 0;

    if (dp[pre][idx] != -1)
        return dp[pre][idx];

    int ans1 = INT_MIN, ans2 = INT_MIN;

    if (p > vec[idx].first && q > vec[idx].second.first)
        ans1 = vec[idx].second.second + solve(vec[idx].first, vec[idx].second.first, idx, idx + 1);

    if (pre != idx)
        ans2 = solve(p, q, pre, idx + 1);
    else
        ans2 = solve(p, q, idx + 1, idx + 1);

    return dp[pre][idx] = max(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cs = 1;

    while (1)
    {
        memset(dp, -1, sizeof(dp));

        cin >> n;

        if (!n)
            break;

        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y >> z;
            vec.push_back({ x,{ y, z } }), vec.push_back({ x,{ z, y } });
            vec.push_back({ y,{ x, z } }), vec.push_back({ y,{ z, x } });
            vec.push_back({ z,{ x, y } }), vec.push_back({ z,{ y, x } });
        }

        sort(vec.rbegin(), vec.rend());

        cout << "Case " << cs++ << ": maximum height = " << solve(INT_MAX, INT_MAX, 0, 0) << endl;

        vec.clear();
    }

    return 0;
}
