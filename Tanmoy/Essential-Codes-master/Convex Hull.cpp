#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

struct point
{
    int x, y;
    point()
    {
        x = y = 0;
    }
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const   // override less than operator
    {
        if (abs(x-other.x))
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const
    {
        return (abs(x - other.x) ==0 && abs(y - other.y)==0);
    }
};

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec
{
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b)
{
// convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s)
{
    return vec(v.x * s, v.y * s);
}
// nonnegative s = [<1 .. 1 .. >1]
// shorter.same.longer
point translate(point p, vec v)
{
// translate p according to v
    return point(p.x + v.x, p.y + v.y);
}

double cross(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r)
{
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

point pivot(0, 0);

bool angleCmp(point a, point b)
{
// angle-sorting function
    if (collinear(pivot, a, b))
// special case
        return dist(pivot, a) < dist(pivot, b);
// check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}


vector<point> CH(vector<point> P)
{
    int i, j, n = (int)P.size();
    if (n <= 3)
    {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;
    }
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;
    pivot = P[0];

    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2;
    while (i < n)
    {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }

    return S;
}


int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n,l;
    cin>>n>>l;
    vector<point>v;
    for(int i=0; i<n; i++)
    {
        double a,b;
        cin>>a>>b;
        v.pb(point(a,b));
    }

    v=CH(v);

    double ans=2*Pi*(double)l;

//    for(int i=0;i<SZ(v);i++)
//        cout<<v[i].x<<" "<<v[i].y<<endl;

    for(int i=0; i<SZ(v)-1; i++)
    {
        ans+=dist(v[i],v[i+1]);
    }

    cout<<setprecision(0)<<fixed<<ans<<endl;

    return 0;
}

