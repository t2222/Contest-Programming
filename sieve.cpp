#include <iostream>
#include <vector>
#include <cstdlib>
#include <bitset> ///tried to use this, most efficient stuff
#include <cmath>
const int N = 30;
using namespace std;
int cnt; ///counter for no. of primes
bool mark[1000002] = {0}; ///marks prime or not
int prime[300000]; ///takes prime , size = mark/6

void sieve(int n)
{
    cnt = 0;
    int i,j,limit = sqrt(n*1.)+2; ///set limit for safety
    mark[1] = 1; ///1 not prime
    for (i = 4 ; i <= n ; i+=2)
    {
        mark[i] = 1; ///canceling even number
    }
    prime[cnt++] = 2; ///1st prime, cnt+=1

    ///loop for odd
    for (i = 3 ; i <= n ; i+=2)
    {
        ///if not prime no need to do multiple cutting
        if (!mark[i])
        {
            prime[cnt++] = i;
            if (i<=limit)
            {
                for (j = i*i ; j <= n ; j += 2*i)
                {
                    mark[j] = 1;
                }
            }
        }

    }
}
int main()
{
    sieve(20);
    cout << cnt << endl;
    for (int i = 0 ; i < cnt ; i++)
        cout << prime[i] << " " ;
    cout << "\n";
    for (int i = 0 ; i < cnt ; i++)
        cout << mark[i] << " ";
}
