/*
UserId: imranRNKENT
Problem: The Specials Menu
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
 
char str[100];
intl dp[100][100];
 
intl solve(int i, int j)
{
    if(i > j)
        return 0;
 
    if(i == j)
        return 1;
 
    if(dp[i][j] != -1)
        return dp[i][j];
 
    intl ret = 0;
 
    if(str[i] == str[j])
        ret = 1 + solve(i + 1, j - 1);
 
    dp[i][j] = ret + solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
 
    return dp[i][j];
}
 
int main()
{
    int test, cs = 1;
    sf(test);
 
    while(test--)
    {
        ss(str), ms(dp, -1);
 
        int sz = strlen(str);
 
        printf("Case %d: %lld\n", cs++, solve(0, sz - 1));
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
