/*
What​ ​ is​ ​ centroid​ ​ decomposition?

Centroid​ ​ decomposition​ ​ is​ ​ a ​ ​ divide​ ​ and​ ​ conquer​ ​ algorithm​ ​ using​ ​ which​ ​ we​ ​ split​ ​ a ​ ​ given​ ​ tree​ ​ by
selecting​ ​ its​ ​ centroid,​ ​ and​ ​ then​ ​ recursively​ ​ further​ ​ split​ ​ the​ ​ children​ ​ forest.​

What’s​ ​ a ​ ​ centroid?​ ​

A centroid​ ​ is​ ​ a ​ ​ node​ ​ whose​ ​ removal​ ​ splits​ ​ the​ ​ tree​ ​ into​ ​ forest​ ​ where​ ​ no​ ​ child​ ​ tree​ ​ has​ ​ more​ ​ than​ ​ N/2
nodes.

Lemma​ ​ 1:​ ​ A ​ ​ node​ ​ can​ ​ never​ ​ have​ ​ more​ ​ than​ ​ 1 ​ ​ child​ ​ with​ ​ size​ ​ greater​ ​ than​ ​ N/2.
Lemma​ ​ 2:​ ​ LCA​ ​ of​ ​ a ​ ​ node​ ​ pair​ ​ in​ ​ Centroid​ ​ Tree​ ​ falls​ ​ between​ ​ path​ ​ of​ ​ same​ ​ pair​ ​ in​ ​ original​ ​ tree.
*/

#define Size 100005

int sz[Size], n, uu, vv;
int blocked[Size];
vector<int> v[Size];

void getSize(int pos, int par)
{
    sz[pos] = 1;
    for (int i=0; i<v[pos].size(); i++)
    {
        int j = v[pos][i];
        if (j == par) continue;
        if (blocked[j]) continue;
        getSize(j,pos);
        sz[pos] += sz[j];
    }
    return;
}

int getCenter(int pos, int par, int szz)
{
    for (int i=0; i<v[pos].size(); i++)
    {
        int j = v[pos][i];
        if (j == par) continue;
        if (blocked[j]) continue;
        if (sz[j]+sz[j] > szz) return getCenter(j,pos,szz);
    }
    return pos;
}

int center(int pos)
{
    getSize(pos,0);
    return getCenter(pos,0, sz[pos]);
}

void decompose(int pos)
{
    int newCenter = center(pos);
    // Do your work here. Tree getting decomposed at newCenter
    blocked[newCenter] = 1;
    for (int i=0; i<v[newCenter].size(); i++)
    {
        int j = v[newCenter][i];
        if (blocked[j]) continue;
        decompose(j,nxt);
    }
    return;
}

int main ()
{
    scanf("%d", &n);
    for (int i=0; i<n-1; i++)
    {
        scanf("%d %d", &uu, &vv);
        v[uu].pb(vv);
        v[vv].pb(uu);
    }
    decompose(1,'A');
    return 0;
}

