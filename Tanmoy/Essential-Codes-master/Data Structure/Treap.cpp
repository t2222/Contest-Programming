/*****************************************************************
 *                         Treap                                 *
 *                                                               *
 *****************************************************************/

#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

#define S scanf
#define P printf

#define  F(i,a,b) for(int i=a;i<b; i++)
#define FF(i,a,b) for(i=a;i<=b;i++)
#define FI(i,a,b) for((typeof(b)) i=a;i<=b;i++)
#define FR(i, a, b,inc) for(  i = (a); i <= (b); i+=inc )
#define RFR(i, a, b,dec) for(  i = (a); i >= (b); i-=dec )
#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;

#define LL long long int
#define ULL unsigned long long int
#define D double

#define Max(a,b)    (a>b?a:b)
#define Min(a,b)    (a<b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SQR(n)      (n*n)
#define PI          2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define X  first
#define Y  second
#define MP make_pair

#define PCC        cout<<"Case "<<cas++<<": ";
#define PC         printf("Case %d:",cas++);
#define PCN        printf("Case %d:\n",cas++);
#define NL         printf("\n");
#define cp         printf("here\n");

#define open       freopen("input.txt","r",stdin)
#define close      freopen ("output.txt","w",stdout)
#define Case(a)    printf("Case %d:",a)
#define caseh(a)   printf("Case #%d: ",a)
#define S1(a)      scanf("%d",&a)
#define S2(a,b)    scanf("%d%d",&a,&b)
#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define SL1(a)     scanf("%lld",&a)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define CHR        getchar()
#define PB(x)      push_back(x)
#define pb         push_back
#define PP         pop_back()
#define PF(x)      push_front(x)
#define PPF(x)     pop_front()
#define PS(x)      push(x)
#define sz()       size()
#define UB         upper_bound
#define LB         lower_bound
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))
#define SUM(a,n)   (accumulate(a,a+n,0))
#define countbit(x) __builtin_popcount(x)
#define DBG(n)      P("Done %d\n",n);

// I/O
#define I(X)                       scanf("%d", &(X))
#define II(X, Y)                   scanf("%d%d", &(X), &(Y))
#define III(X, Y, Z)               scanf("%d%d%d", &(X), &(Y), &(Z))
#define DI(X) int (X);             scanf("%d", &X)
#define DII(X, Y) int X, Y;        scanf("%d%d", &X, &Y)
#define DIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

#define ILL(X)          scanf("%lld", &(X))
#define DILL(X) LL (X); scanf("%lld", &X)

// LOOP
#define repv(i,a) for(int i=0;i<(int)a.size();i++)
#define revv(i,a) for(int i=((int)a.size())-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)

#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)


using namespace std;

template <typename T> T BigMod (T b,T p,T m)
{
    if (p == 0) return 1;
    if (p%2 == 0)
    {
        T s = BigMod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T> T ModInv (T b,T m)
{
    return BigMod(b,m-2,m);
}
template <typename T> T in()
{
    char ch;
    T n = 0;
    bool ng = false;
    while (1)
    {
        ch = getchar();
        if (ch == '-')
        {
            ng = true;
            ch = getchar();
            break;
        }
        if (ch>='0' && ch<='9')     break;
    }
    while (1)
    {
        n = n*10 + (ch - '0');
        ch = getchar();
        if (ch<'0' || ch>'9')   break;
    }
    return (ng?-n:n);
}
template <typename T> T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}
template <typename T> T Bigmod(T b,T p,T m)
{
    if(p==0) return 1;
    else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;
    else return ((b % m) * Bigmod(b,p-1,m)) % m;
}
template <typename T> T Dis(T x1,T y1,T x2, T y2)
{
    return sqrt( SQR(x1-x2) + SQR(y1-y2) );
}
template <typename T> T Angle(T x1,T y1,T x2, T y2)
{
    return atan( double(y1-y2) / double(x1-x2));
}
template <typename T> T DIFF(T a,T b)
{
    T d = a-b;
    if(d<0)return -d;
    else return d;
}
template <typename T> T ABS(T a)
{
    if(a<0)return -a;
    else return a;
}
template <typename T> T gcd(T a,T b)
{
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <typename T> T lcm(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/gcd(a,b));
}
template <typename T> T euclide(T a,T b,T &x,T &y)
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}
template <typename T> void ia (T a[],int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}
template <typename T> void pa (T a[],int n)
{
    for (int i=0; i<n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
}
template <typename T> LL isLeft(T a,T b,T c)
{
    return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);
}

int    Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int  Reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
template< class T, class X > inline T   togglebit(T a, X i)
{
    T t=1;
    return (a^(t<<i));
}

int toInt(string s)
{
    int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}
int toLlint(string s)
{
    long long int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}
int cdigittoint(char ch)
{
    return ch-'0';
}
bool isVowel(char ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;
    return false;
}
bool isConst(char ch)
{
    if (isalpha(ch) && !isVowel(ch)) return true;
    return false;
}

double DEG(double x)
{
    return (180.0*x)/(PI);
}
double RAD(double x)
{
    return (x*(double)PI)/(180.0);
}

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >

///         0123456789
#define MX  200007
#define MOD 1000000007
#define INF (1<<30)-1+(1<<30)
#define eps 1e-9

#define base ((1<<l)-1)
#define lft (idx<<1)
#define rgt (lft|1)
#define mid ((l+r)>>1)

/// Hashing Bases & MOD
///           0123456789
#define Base1 10000019ULL
#define Base2 10000079ULL
#define Base3 10000103ULL
#define MOD1  1000000007ULL
#define MOD2  1000000009ULL
#define MOD3  1000000021ULL
#define LOGX  17

/************************************************************
 *              Treap The best BST I Ever Found             *
 ************************************************************
          *** A Full BST within 100 lines of code ***
          *******************************************
 Functions:
 Treap()                                : Creates an empty BST with NULL root
 Treap(int v, int c)                    : Creates a BST with single node
 Treap(Node* x)                         : Creates a BST whose root is Node* x
 Size(Node* x)                          : Gives the size of the subtree whose root is Node* x
 Size()                                 : Gives the size of the total BST
 Update(Node *x)                        : Update Node* x according to the problem description
 SplitByVal(int v)                      : Splits the BST and returns a pair of Treap
                                          * pair.first contains the nodes having key value less than v
                                          * pair.second contains the rest of the tree
 SplitBySize(int sz)                    : Splits the BST and returns a pair of Treap
                                          * pair.first contains the tree having size equals sz
                                          * pair.second contains the rest of the tree
Join(Treap r)                           : Joins Treap r with this treap, assuming that treap-r is the right part.

 Functional Approaches:
 **Insert:
 During inserting a value v, split the trees into two, one containing
 values less than v, others contains the rest of the nodes. Then join
 left tree, the new node for value v and the right tree.

 **Delete:
 During deletion of value v, approach is like insertion. Split into 3
 trees, middle tree will contain the values equal to v.  Just  ignore
 this during joining. That means, join left most & right most tree.

 **Hints for all operations:
 Just do split & join to perform all the operations.
*/

struct Node
{
    int v,c,s,prior;
    Node *l,*r;

    /*
    ## Description of member variables of Node
    * v = Value, BST is based on this value
    * c = Count of number of values, if you want to insert two element of 6, then you will just have to set v = 6 & c = 2
    * s = Size of subtree
    * prior = Priority of the node
    */

    Node() {}
    Node(int _v,int _c,int _p)
    {
        v = _v;
        prior = _p;
        l = r = NULL;
        s = c = _c;
    }
};

struct Treap
{
    Node* root;

    Treap()
    {
        root = NULL;
    }
    Treap(int v,int c)
    {
        root = new Node(v,c,rand());
    }
    Treap(Node* x)
    {
        root = x;
    }
    int Size(Node *x)
    {
        return x?x->s:0;
    }
    int Size()
    {
        return Size(root);
    }
    void Update(Node *x)
    {
        if (x) x->s = Size(x->l)+Size(x->r)+x->c;
    }


    void Split(Node *idx,Node* &l,Node* &r,int v)
    {
        if (!idx)
        {
            l = r = NULL;
            return;
        }

        if (idx->v < v)
        {
            Split(idx->r,idx->r,r,v);
            l = idx;
        }
        else
        {
            Split(idx->l,l,idx->l,v);
            r = idx;
        }

        Update(idx);
    }

    void SplitSiz(Node *idx,Node* &l,Node* &r,int sz)
    {
        if (idx == NULL)
        {
            l = r = NULL;
            return;
        }

        if (Size(idx) <= sz)
        {
            l = idx;
            r = NULL;
            Update(l);
        }
        else if (Size(idx->l) >= sz)
        {
            r = idx;
            SplitSiz(idx->l,l,r->l,sz);
        }
        else if (Size(idx->l)+idx->c > sz)
        {
            int lSz = sz - Size(idx->l);
            int rSz = idx->c - lSz;

            l = new Node(idx->v,lSz,rand());
            r = new Node(idx->v,rSz,rand());

            l->l = idx->l;
            r->r = idx->r;
        }
        else
        {
            l = idx;
            SplitSiz(idx->r,l->r,r,sz - Size(idx->l) - idx->c);
        }

        Update(l);
        Update(r);
    }

    Node* Join(Node* l,Node *r)
    {
        if (!l || !r)   return l?l:r;

        if (l->prior > r->prior)
        {
            l->r = Join(l->r,r);
            Update(l);
            return l;
        }
        else
        {
            r->l = Join(l,r->l);
            Update(r);
            return r;
        }
    }

    pair< Treap, Treap > SplitByVal(int v)
    {
        Node *l, *r;

        Split(root, l, r, v);

        return make_pair(Treap(l), Treap(r));
    }

    pair< Treap, Treap> SplitBySize(int sz)
    {
        Node *l, *r;

        SplitSiz(root, l, r, sz);

        return make_pair(Treap(l), Treap(r));
    }

    Treap Join(Treap r)
    {
        Node *newRoot = Join(root, r.root);
        return Treap(newRoot);
    }

    void Print()
    {
        Print(root);
        NL;
    }
    void Print(Node* p)
    {
        if (p == NULL)      return ;

        cout << p->v << "(" << p->s <<"," <<p->prior << ") [ ";

        Print(p->l);
        cout << " ][ ";
        Print(p->r);
        cout << " ] ";
    }
};

int main()
{
    int a[] = {4,1,3,5,2};

    Treap bst = Treap();

    for (int i=0; i<5; i++)
    {
        pair< Treap, Treap > splitedTreap = bst.SplitByVal(a[i]);
        Treap singleNodeTreap = Treap(a[i], 1);

        bst = splitedTreap.X.Join(singleNodeTreap);
        bst = bst.Join(splitedTreap.Y);
    }

    bst.Print();
    return 0;
}

