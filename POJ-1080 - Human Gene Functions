#include <iostream>
#include <string>

using namespace std;

const int maxn = 101010;

int arr[5][5] = {
                    5, -1, -2, -1, -3,
                    -1, 5, -3, -2, -4,
                    -2, -3, 5, -2, -2,
                    -1, -2, -2, 5, -1,
                    -3, -4, -2, -1, 0
};

string str, ptr;
bool mark[111][111][5][5];
int test, n, m, dp[111][111][5][5];

int get(char ch)
{
    if (ch == 'A')
        return 0;
    else if (ch == 'C')
        return 1;
    else if (ch == 'G')
        return 2;
    else if (ch == 'T')
        return 3;
    else
        return 4;
}

int solve(int i, int j, int k, int l)
{
    if (i == n && j == m)
        return 0;
    
    if ((i == n && j < m) || (i < n && j == m))
        return -maxn;
    
    if (mark[i][j][k][l])
        return dp[i][j][k][l];
    
    mark[i][j][k][l] = true;
    
    int ret = -maxn, idx = get(str[i]), jdx = get(ptr[j]);
    
    ret = max(ret, arr[4][jdx] + solve(i, j + 1, 4, jdx));
    ret = max(ret, arr[idx][4] + solve(i + 1, j, idx, 4));
    ret = max(ret, arr[idx][jdx] + solve(i + 1, j + 1, idx, jdx));
    
    return dp[i][j][k][l] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> test;
    
    while (test--)
    {
        memset(mark, false, sizeof(mark));
        
        cin >> n >> str;
        cin >> m >> ptr;
        
        cout << solve(0, 0, 0, 0) << endl;
        
    }
    
    return 0;
}
