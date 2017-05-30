/*
UserId: imranRNKENT
Problem: Neighbor House
Language: C++
Catagory: DP
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
 
int n, arr[30][3], dp[30][3];
 
int solve(int i, int j)
{
    if(i == n - 1)
        return arr[i][j];
 
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
 
    if(j == 0)
        dp[i][j] = arr[i][j] + min(solve(i + 1, 1), solve(i + 1, 2));
    else if(j == 1)
        dp[i][j] = arr[i][j] + min(solve(i + 1, 2), solve(i + 1, 0));
    else
        dp[i][j] = arr[i][j] + min(solve(i + 1, 0), solve(i + 1, 1));
 
    return dp[i][j];
}
 
int main()
{
    int test, cs = 1;
    sf(test);
 
    while(test--)
    {
        for(int i = 0; i < 30; ++i)
            dp[i][0] = dp[i][1] = dp[i][2] = INT_MAX;
 
        sf(n);
 
        for(int i = 0; i < n; ++i)
            sf(arr[i][0]), sf(arr[i][1]), sf(arr[i][2]);
 
        int ans = min(solve(0, 0), min(solve(0, 1), solve(0, 2)));
 
        printf("Case %d: %d\n", cs++, ans);
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
