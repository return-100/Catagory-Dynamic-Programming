/*
UserId: imranRNKENT
Problem: Coin Change (II)
Language: C++
Main Idea: DP
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define i64 long long
#define endl "\n"
#define maxn 100005
#define mod 100000007
 
int dp[2][10001];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t, cnt = 1;
    cin >> t;
 
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
 
        int n, m, arr[101];
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            cin >> arr[i];
 
        for(int i = 0, k = 0; i <= n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                if(!i)
                    dp[k][j] = 0;
                else if(!j)
                    dp[k][j] = 1;
                else if(j < arr[i])
                    dp[k][j] = dp[k - 1][j];
                else if(dp[k][j - arr[i]])
                    dp[k][j] = (dp[k - 1][j] + dp[k][j - arr[i]]) % mod;
                else
                    dp[k][j] = dp[k - 1][j];
 
                if(i)
                    dp[k - 1][j] = dp[k][j];
            }
           
            if(!i)
                ++k;
        }
 
        cout << "Case " << cnt++ << ": " << dp[1][m] << endl;
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
