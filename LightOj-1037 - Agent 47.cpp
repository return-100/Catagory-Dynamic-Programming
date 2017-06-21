#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
#define maxn 100010
#define ints size_t
#define pbk push_back
#define intl long long
#define mod 1000000007
#define inf 1000000000
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
 
char str[20];
int n, arr[15][15], brr[15], crr[15], cost[15][10], dp[15][1 << 16];
 
void load(int idx)
{
    for(int i = 0; i < n; ++i)
    {
        if(arr[idx][i])
        {
            ++cost[i][arr[idx][i]];
            brr[i] = max(brr[i], arr[idx][i]);
        }
    }
}
 
void reload(int idx)
{
    for(int i = 0; i < n; ++i)
    {
        if(cost[i][arr[idx][i]])
        {
            --cost[i][arr[idx][i]];
 
            for(int j = 9; j > 0; --j)
            {
                if(cost[i][j])
                {
                    brr[i] = j;
                    break;
                }
 
                j == 1 ? brr[i] = 1 : brr[i] = brr[i];
            }
        }
    }
}
 
void clr()
{
    for(int j = 0; j < 15; ++j)
    {
        brr[j] = 1;
 
        for(int k = 0; k < 10; ++k)
            cost[j][k] = 0;
    }
}
 
int solve(int idx, int mask, int num)
{
    if(num == 1)
        return 0;
 
    if(dp[idx][mask] != -1)
        return dp[idx][mask];
 
    load(idx);
 
    int ret = inf;
 
    for(int i = 0; i < n; ++i)
    {
        if(i != idx && !(mask & 1 << i))
        {
            int cur = (int) ceil((double) crr[i] / brr[i]);
 
            ret = min(ret, cur + solve(i, mask | 1 << idx, num - 1));
        }
    }
 
    reload(idx);
 
    return dp[idx][mask] = ret;
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
            sf(crr[i]);
 
        for(int i = 0; i < n; ++i)
        {
            ss(str);
 
            for(int j = 0; j < n; ++j)
                arr[i][j] = str[j] - '0';
        }
 
        int ans = inf;
 
        for(int i = 0; i < n; ++i)
        {
            clr();
 
            ans = min(ans, crr[i] + solve(i, 0, n));
        }
 
        printf("Case %d: %d\n", cs++, ans);
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
