/*
UserId: imranRNKENT
Problem: Brush (III)
Language: C++
Main Idea: DP, Sorting
*/

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define maxn 100010
#define ints size_t
#define pbk push_back
#define intl long long
#define mod 1000000007
#define pi 2 * acos(0.0)

#define sf(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define sl(n) scanf("%lld", &n)
#define sc(c) scanf(" %c", &c)
#define ss(str) scanf("%s", str)
#define pc(c) printf("%c\n", c)
#define pf(n) printf("%d\n", n)
#define pd(n) printf("%lf\n", n)
#define pl(n) printf("%lld\n", n)
#define ps(str) printf("%s\n", str)
#define ms(n, m) memset(n, m, sizeof(n))

vector < pair<int, int> > vec;

int n, w, k, dp[105][105];

int solve(int idx, int cur)
{
    if(idx >= n || !cur)
        return 0;

    if(dp[idx][cur] != -1)
        return dp[idx][cur];

    int got = 0, nextIdx = n;

    for(int i = 0; i < n; ++i)
    {
        if(vec[idx].x <= vec[i].x && vec[i].x <= vec[idx].x + w)
            ++got, nextIdx = i + 1;
    }

    dp[idx][cur] = max(got + solve(nextIdx, cur - 1), solve(idx + 1, cur));

    return dp[idx][cur];
}

int main()
{
    int test, cs = 1;
    sf(test);

    while(test--)
    {
        ms(dp, -1);

        sf(n), sf(w), sf(k);

        for(int i = 0; i < n; ++i)
        {
            int x, y;
            sf(x), sf(y);
            vec.pbk({y, x});
        }

        sort(vec.begin(), vec.end());

        printf("Case %d: %d\n", cs++, solve(0, k));

        vec.clear();
    }

    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
