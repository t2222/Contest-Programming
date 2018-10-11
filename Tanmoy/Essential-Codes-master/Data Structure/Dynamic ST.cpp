/* *********************************************************************
   *                      Dynamic Segment Tree                         *
   ********************************************************************* */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <iterator>
/* ********************
   *     Defines      *
   ******************** */
#define max(a,b) ((a>b)?a:b)                        //finding max
#define min(a,b) ((a<b)?a:b)                        //finding min
#define Max(a,b,c) max(a,max(b,c))                  //finding max between 3 numbers
#define Min(a,b,c) min(a,min(b,c))                  //finding min between 3 numbers
#define FOR(i,s,e) for(i=s;i<=e;i++)                //for loop with 1 increment
#define For(i,s,e,d) for(i=s;i<=e;i+=d)             //for loop with manual increment
#define _For(i,s,e,d) for(i=s;i>=e;i-=d)             //for loop with manual increment
#define Pi acos(-1.0)                               //defining Pi for mathematical uses
#define Clear(a) memset(a,0,sizeof(a))              //clearing memory of an array
#define setfalse(a) memset(a,false,sizeof(a))       //setting the array into false
#define settrue(a) memset(a,true,sizeof(a))         //setting the array into true
#define clrstr(a) memset(a,'\0',sizeof(a))          //setting string array to null
#define open freopen("input.txt","r",stdin)         //opening input file
#define close freopen ("output.txt","w",stdout)     //opening output file
#define Case(a) printf("Case %d:\n",a)               //printing case number
#define caseh(a) printf("Case #%d: ",a)             //printing case number having '#'
#define getcase(a) scanf("%d",&a)                   //scanning case number
#define S1(a) scanf("%d",&a)                        //scan one int
#define S2(a,b) scanf("%d%d",&a,&b)                 //scan two int
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)          //scan three int
#define SL1(a) scanf("%lld",&a)                     //scanf one long long
#define SL2(a,b) scanf("%lld%lld",&a,&b)            //scanf two long long
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)   //scanf two long long
#define CHR getchar()                               //avoid the newline character problem
#define caseloop(a,b) for(a=1;a<=b;a++)             //making case loop
#define EPS 1e-9                                    //small value for avoiding preccesion error
#define LL long long                                //long long short form
#define ULL unsigned long long                      //unsigned long long sort form
#define MX 100000000                                //MAX size/value
#define PB(x) push_back(x)                          //push in vector/string
#define PP pop_back()                               //pop from vector
#define PF(x) push_front(x)                         //push in vector/string/deque from front
#define PPF(x) pop_front()                          //pop from vector/deque from front
#define IN(x) insert(x)                             //insert element in set
#define PS(x) push(x)                               //push element in stack/queue
#define P() pop()                                   //pop element from stack/queue
#define SZ() size()                                 //return size
#define MOD 1000000007                              //mod value
#define INF (1<<28)                                 //infinity value
#define Y 1                                         //true value
#define N 0                                         //false value

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
template <typename T> void ia (T a[],int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}
template <typename T> void pa (T a[],int n)
{
    for (int i=0; i<n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
}
template <typename T> T gcd(T a,T b)
{
    if (!b) return a;
    return gcd(b,a%b);
}
template <typename T> T POW(T b,T p)
{
    if (p == 0) return 1;
    if (p%2 == 0)
    {
        T s = POW(b,p/2);
        return s*s;
    }
    return b*POW(b,p-1);
}

struct node
{
    int l,r,cnt;
    node *lft,*rgt;

    node(int a,int b)
    {
        l = a;
        r = b;

        cnt = 0;

        lft = rgt = NULL;
    }
};

void update(node *seg,int st,int ed)
{
    if (st<=seg->l && ed>=seg->r)
    {
        seg->cnt++;

        return;
    }

    int mid = (seg->l+seg->r)>>1;

    if (ed<=mid)
    {
        if (seg->lft == NULL)
            seg->lft = new node(seg->l,mid);

        update(seg->lft,st,ed);
    }

    else if (st>mid)
    {
        if (seg->rgt == NULL)
            seg->rgt = new node(mid+1,seg->r);

        update(seg->rgt,st,ed);
    }

    else
    {
        if (seg->lft == NULL)
            seg->lft = new node(seg->l,mid);

        if (seg->rgt == NULL)
            seg->rgt = new node(mid+1,seg->r);

        update(seg->lft,st,ed);
        update(seg->rgt,st,ed);
    }
}

int query(node *seg, int pos)
{
    if (seg->l == seg->r)
        return seg->cnt;

    int mid = (seg->l+seg->r)>>1;

    if (pos<=mid)
    {
        if (seg->lft == NULL)
            return seg->cnt;

        return seg->cnt + query(seg->lft,pos);
    }

    else
    {
        if (seg->rgt == NULL)
            return seg->cnt;

        return seg->cnt + query(seg->rgt,pos);
    }
}

void del(node *ob)
{
    if(ob->lft!=NULL)del(ob->lft);
    if(ob->rgt!=NULL)del(ob->rgt);

    //ob = NULL;

    delete(ob);
}

int main ()
{
    int t,c,n,k,x,y;

    getcase(t);
    caseloop(c,t)
    {
        scanf ("%d%d",&n,&k);

        node *root = new node(0,MX);

        for (int i=0; i<n; i++)
        {
            scanf ("%d%d",&x,&y);

            update(root,x,y);
        }

        Case(c);

        for (int i=0; i<k; i++)
        {
            scanf ("%d",&x);

            printf ("%d\n",query(root,x));
        }

        del(root);
    }
    return (0);
}

