/*
UserId: imranRNKENT
Problem: Monkey Banana Problem
Language: C++
Mian Idea: DP
*/

#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int a[201][201], dp[201][201], n;
 
int f(int i, int j)
{
    if(i==2*n-2) 
        return a[i][0];
    
    if(i<0 || j<0) 
        return 0;
    
    if(dp[i][j]) 
        return dp[i][j];
    
    if(i >= n-1) 
        dp[i][j] = a[i][j] + (f(i + 1, j - 1) > f(i + 1,j) ? f(i + 1, j - 1) : f(i + 1,j));
    else 
        dp[i][j] = a[i][j] + (f(i+1, j) > f(i + 1, j + 1) ? f(i + 1, j) : f(i + 1, j + 1));
    
    return dp[i][j];
}
 
int main()
{
    int t, cnt=1;
    cin >> t;
    
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        
        cin >> n;
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=i; ++j)
                cin >> a[i][j];
        }
        
        for(int i=n; i<2*n-1; ++i)
        {
            for(int j=0; j<(2*n-1-i); ++j)
                cin >> a[i][j];
        }
        
        cout << "Case " << cnt++ << ": " << f(0,0) << endl;
    }
    return 0;
}
