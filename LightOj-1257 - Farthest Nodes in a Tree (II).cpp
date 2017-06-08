/*
UserId: imranRNKENT
Problem: Farthest Nodes in a Tree (II)
Language: C++
Main Idea: DFS, DP
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define i64 long long
#define endl "\n"
#define maxn 30005
#define mod 1000000007
 
vector < pair<int, int> > adj[maxn], dist[maxn];
int arr[maxn];
bool visited[maxn];
 
int dfs1(int u, int w)
{
    int temp = 0, var;
 
    visited[u] = true;
 
    for(int i = 0; i < (int) adj[u].size(); ++i)
    {
        var = w + adj[u][i].second;
 
        if(!visited[adj[u][i].first])
            dist[u].push_back({ adj[u][i].first, dfs1(adj[u][i].first, var) + adj[u][i].second });
    }
 
    for(int i = 0; i < (int) dist[u].size(); ++i)
        temp = max(temp, dist[u][i].second);
 
    arr[u] = max(temp, w);
 
    return temp;
}
 
void dfs2(int u, int p, int w)
{
    int mx = 0;
    visited[u] = true;
 
    for(int i = 0; i < (int) dist[p].size(); ++i)
    {
        if(dist[p][i].first != u)
            mx = max(mx, dist[p][i].second + w);
    }
 
    if(p != u)
        dist[u].push_back({ p, mx });
 
    for(int i = 0; i < (int) adj[u].size(); ++i)
    {
        if(!visited[adj[u][i].first])
            dfs2(adj[u][i].first, u, adj[u][i].second);
    }
 
    arr[u] = max(arr[u], mx);
}
 
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
 
    memset(visited, false, sizeof(visited));
    memset(arr, 0, sizeof(arr));
 
    int t, cnt = 1;
    scanf("%d", &t);
 
    while(t--)
    {
        int n, u, v, w;
        scanf("%d", &n);
        for(int i = 0; i < n - 1; ++i)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
 
        dfs1(0, 0);
       
        memset(visited, false, sizeof(visited));
 
        dfs2(0, 0, 0);
 
        printf("Case %d:\n", cnt++);
 
        for(int i = 0; i < n; ++i)
        {
            printf("%d\n", arr[i]);
            adj[i].clear(), dist[i].clear();
            visited[i] = false, arr[i] = 0;
        }
    }
 
    /*cin.clear();
    cin.ignore();
    cin.get();*/
    return 0;
}
