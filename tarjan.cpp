int ts[100005];
 curn=n-1;
void dfs(int s)
{
    visited[s]=1;
    rr(adj[s])
    {
        if(!visited[val])
        {
            dfs(val);
        }
    }
    ts[curn]=s+1;
    curn--;
    
}