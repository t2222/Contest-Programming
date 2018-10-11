#define mx 3004

int lps[mx];

void Phi(string P)
{
    int k=0;
    lps[k]=0;
    for(int i=1; i<SZ(P); i++)
    {
        while(k>0 && P[k]!=P[i]) k=lps[k-1];
        if(P[i]==P[k]) k++;
        lps[i]=k;
    }
}

void KMP(string T, string P, vector<int> &pos)
{
    int k=0;
    for(int i=0; i<SZ(T); i++)
    {
        while(k>0 && T[i]!=P[k]) k=lps[k-1];
        if(T[i]==P[k]) k++;
        if(k==SZ(P))
        {
            pos.pb(i-SZ(P)+1);
//            cout<<i-SZ(P)+1<<endl;
            k=lps[k-1];
        }
    }
}

