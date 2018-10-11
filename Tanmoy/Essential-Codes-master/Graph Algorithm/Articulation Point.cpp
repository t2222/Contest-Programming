vector<int>g[105];
bool vis[105];
int h[105],low[105];
int dfstime;
bool artpoint[105];

void dfs(int u, int par)
{
    vis[u]=1;
    h[u]=low[u]=++dfstime;
    int child=0;
    for(int i=0; i<SZ(g[u]); i++)
    {
        int v=g[u][i];
        if(v==par) continue;
        if(vis[v])
            low[u]=min(low[u],h[v]);
        else
        {
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=h[u])
                artpoint[u]=1;
        }
    }
    if(u==par) artpoint[u]=(child>1);

}

void allclear()
{
    for(int i=0;i<105;i++)
    {
        g[i].clear();
        vis[i]=h[i]=low[i]=artpoint[i]=0;
    }
    dfstime=0;
}
