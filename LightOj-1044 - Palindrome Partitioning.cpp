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
 
char str[1010];
int sz, arr[1010];
bool dp[1001][1001];
 
int solve(int idx)
{
    if(idx > sz)
        return 0;
 
    if(arr[idx] != -1)
        return arr[idx];
 
    int ret = INT_MAX;
 
    for(int i = idx; i <= sz; ++i)
    {
        if(dp[idx][i])
            ret = min(ret, 1 + solve(i + 1));
    }
 
    return arr[idx] = ret;
}
 
int main()
{
    int test, cs = 1;
    sf(test);
 
    while(test--)
    {
        ms(arr, -1);
 
        ss(str), sz = strlen(str) - 1;
 
        for(int i = 0; i <= sz; ++i)
        {
            for(int j = 0; j <= sz; ++j)
            {
                if(i >= j)
                {
                    if(i - j <= 1 && str[i] == str[j])
                        dp[j][i] = true;
                    else if(i - j > 1 && str[i] == str[j] && dp[j + 1][i - 1])
                        dp[j][i] = true;
                    else
                        dp[j][i] = false;
                }
                else
                    break;
            }
        }
 
        printf("Case %d: %d\n", cs++, solve(0));
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
