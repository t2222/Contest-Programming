#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 31;
int g[N][N];
int main()
{
    int tc = 0;
    int i,j,k,u,v,n,m;
    while(scanf("%d",&m)!=EOF)
    {
        for (i = 0 ; i < N ; i++)
        {
            for (j = 0 ; j < N ; j++)
                g[i][j] = 0;
        }

        n = 0; ///finding the max val of row and cols of adj. matrix
        while (m--)
        {
            cin >> u >> v;
            g[u][v] += 1;
            n = max(n,max(u,v));
        }
        ++n; ///matrix end to row n
        for (k = 0 ; k < n; k++)
        {
            for (i = 0 ; i < n ; i++)
            {
                for (j = 0 ; j < n ; j++)
                {
                    if (g[i][k]!=0&&g[k][j]!=0)
                        g[i][j] += g[i][k]*g[k][j];
                }
            }
        }
        for (k = 0 ; k < n ; k++)
        {
            if (g[k][k])
            {
                for (i = 0 ; i < n ; i++)
                {
                    for (j = 0 ; j < n ; j++)
                    {
                        if(g[i][k]!=0&&g[k][j]!=0)
                        {
                            g[i][j] = -1;
                        }
                    }
                }
            }
        }
        cout << "matrix for city " << tc++ << "\n";
        for (i = 0 ; i < n ; i++)
        {
            for (j = 0 ; j < n ; j++)
            {
                cout << g[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
