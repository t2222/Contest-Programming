#define mx 1005

vector<int>g[mx];
int h[mx],low[mx],dfsnum;
vector<pii>bridges;

void dfs(int u, int par)
{
    h[u]=low[u]=++dfsnum;

    for(int i=0;i<SZ(g[u]);i++)
    {
        int v=g[u][i];
        if(v==par) continue;
        if(h[v])
            low[u]=min(low[u],h[v]);
        else
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>h[u])
                bridges.pb(pii(min(u,v),max(u,v)));
        }
    }
}

void allclear(int n)
{
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        h[i]=low[i]=0;
    }
    bridges.clear();
    dfsnum=0;
}
