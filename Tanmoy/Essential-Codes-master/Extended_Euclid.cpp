ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll x1,y1;
    ll ret=extended_euclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return ret;
}
