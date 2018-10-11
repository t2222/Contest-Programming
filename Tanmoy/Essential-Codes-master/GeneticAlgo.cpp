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
#define D(x)             cerr<<#x " = "<<(x)<<endl
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


/*-----------------------Bitmask------------------*/
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

vector<pii>v;

int number_bit,num;
int current_best=INT_MIN;
int max_x;
int ara[100][30];

int func(int x)
{
    return -(x*x)+5;
}

void gen_num()
{
    v.clear();
    for(int i=0; i<num; i++)
    {
        int x=0;
        int signn=1;
        if(ara[i][0]==1) signn=-1;
        for(int j=1; j<number_bit; j++)
            if(ara[i][j]==1)
                x=Set(x,number_bit-j-1);
        x*=signn;
        v.push_back(pii(x,i));
    }
}

bool cmp(pii a, pii b)
{
    return func(a.first)>func(b.first);
}

void initialization()
{
//    srand(time(NULL));
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<number_bit; j++)
        {
            ara[i][j]=rand()%2;
        }
    }
    gen_num();
}

void calculate_fitness()
{
    sort(all(v),cmp);
}

int get_best()
{
    calculate_fitness();
    return func(v[0].ff);
}

void cross_over(int i, int j)
{
    int pos=rand()%number_bit;

    int a=v[2].ss,b=v[3].ss;

    for(int k=0;k<number_bit;k++)
    {
        ara[a][k]=ara[i][k];
        ara[b][k]=ara[j][k];
    }
    for(int k=pos; k<number_bit; k++)
    {
        swap(ara[i][k],ara[j][k]);
    }
    gen_num();
    calculate_fitness();
}

void mutation()
{
    int r=rand()%50;
    if(r==10)
    {
        int a=rand()%num;
        int b=rand()%number_bit;
        ara[a][b]^=1;
    }
    gen_num();
    calculate_fitness();
}

void print_soln(int id)
{
    cout<<"Iteration : "<<id<<endl;
    for(int i=0;i<num;i++)
    {
        int x=v[i].ss;
        for(int j=0;j<number_bit;j++)
            cout<<ara[x][j];

        cout<<" x= "<<v[i].ff<<"   "<<"f(x)= "<<func(v[i].ff)<<endl;

    }
    cout<<endl;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    srand(time(NULL));

    cin>>num>>number_bit;

    initialization();
    calculate_fitness();
    current_best=get_best();
    max_x=v[0].ff;
    int iteration=0;
    while(iteration<=10000)
    {

//    print_soln(iteration);
        int i=v[0].ss;
        int j=v[1].ss;
        cross_over(i,j);
        mutation();
        if(get_best()>current_best)
        {
            current_best=get_best();
            max_x=v[0].ff;
        }
        iteration++;
    }
    cout<<current_best<<" "<<max_x<<endl;


    return 0;
}
