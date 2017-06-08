/*
UserId: imranRNKENT
Problem: Marriage Ceremonies
Language: C++
Main Idea: DP
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
 
int n, arr[16][16], dp[16][1 << 16];
 
int solve(int i, int mask)
{
    if(i >= n)
        return 0;
 
    if(dp[i][mask] != -1)
        return dp[i][mask];
 
    for(int cur = 0; cur < n; ++cur)
    {
        if(!(mask & (1 << cur)))
            dp[i][mask] = max(dp[i][mask], arr[i][cur] + solve(i + 1, mask | (1 << cur)));
    }
 
    return dp[i][mask];
}
 
int main()
{
    int test, cs = 1;
    sf(test);
 
    while(test--)
    {
        ms(dp, -1);
 
        sf(n);
 
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                sf(arr[i][j]);
        }
 
        printf("Case %d: %d\n", cs++, solve(0, 0));
    }
 
    return 0;
}
