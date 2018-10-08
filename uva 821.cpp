#include <iostream>
#include <cstring>
#include <set>
const int INF = 99999;
const int n = 101;
int g[n][n];
int tc;
using namespace std;
int main()
{

    int u, v;
    while (scanf("%d %d",&u, &v)&&(u|v))
    {
        ++tc;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                g[i][j] = INF;
            }
        }

        for (int i = 0 ; i < n ; i++)
            g[i][i] = 0;

        g[u-1][v-1] = 1;

        set<int> vec;
        vec.insert(u);
        vec.insert(v);

        while (scanf("%d %d",&u, &v)&&(u|v))
        {
            g[u-1][v-1] = 1;
        vec.insert(u);
        vec.insert(v);
        }

        ///floyd - warshall

        int i,j,k;
        for (k = 0 ; k < n ; k++)
        {
            for ( i = 0 ; i < n ; i++)
            {
                for (j = 0 ; j < n ; j++)
                {
                    if (g[i][j]>g[i][k]+g[k][j])
                    {
                        g[i][j] = g[i][k]+g[k][j];
                    }
                }
            }
        }

        float sum = 0;

        for (i = 0 ; i < n ; i++)
        {
            for (j = 0 ; j < n ; j++)
            {
                {
                    if (g[i][j]!=INF && g[i][j]!=0)
                        sum += g[i][j];
                }
            }
        }


        int setSize = vec.size();
        printf("Case %d: average length between pages = %.3f clicks\n", tc, float(sum/(setSize*(setSize-1))));

        vec.clear();
    }
}
