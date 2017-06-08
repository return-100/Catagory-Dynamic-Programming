/*
UserId: imranRNKENT
Problem: Coin Change (I)
Language: C++
Main Idea: DP
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define maxn 100010
#define i64 long long
#define mod 100000007
 
#define pf(n) printf("%d\n", n)
#define sf(n) scanf("%d", &n)
#define ms(n, m) memset(n, m, sizeof(n))
 
int n, k, ans, arr[2][50], dp[50][1001];
 
int solve(int idx, int cur)
{
    int ret = 0;
 
    if(idx >= n) 
    {
        if(cur == k)
            return 1;
        else
            return 0;
    }
 
    if(dp[idx][cur] != -1)
        return dp[idx][cur];
 
    for(int i = 1; i <= arr[1][idx]; ++i) 
    {
        if(cur + arr[0][idx] * i <= k)
            ret += solve(idx + 1, cur + arr[0][idx] * i) % mod;
        else
            break;
    }
 
    ret += solve(idx + 1, cur) % mod;
 
    dp[idx][cur] = ret % mod;
 
    return dp[idx][cur];
}
 
int main()
{
    int test, cs = 1;
    sf(test);
 
    while(test--) 
    {
        ms(dp, -1);
        sf(n), sf(k);
 
        for(int i = 0; i < n; ++i)
            sf(arr[0][i]);
 
        for(int i = 0; i < n; ++i)
            sf(arr[1][i]);
 
        printf("Case %d: ", cs++);
 
        pf(solve(0, 0) % mod);
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
