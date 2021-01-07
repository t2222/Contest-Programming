#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring> // needed for memsets
#include<stack>
#include<utility> // needed for pair
#include<queue>
#include<set>
#include<map>
#include<set>
#include<numeric> // used accumulate
#include <bitset>
#include <cmath>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;

using namespace std;
int main()
{
    unsigned long long int a[5], sumArray[5], sum = 0;
    bool check[5] = { false };
    for (int i = 0; i < 5; i++)
    {
        int val;
        cin >> val;
        a[i] = val;
    }

    // find sum of all elements except i th one and store to sumArray for later comparison
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == i)
            {
                continue;
            }
            else
            {
                sum += a[j];
            }
        }
        sumArray[i] = sum;
        sum = 0;
    }

    // find min
    unsigned long long int min = sumArray[0];
    for (int i = 1; i < 5; i++)
    {
        if (min > sumArray[i])
        {
            min = sumArray[i];
        }
    }
    cout << min << " ";

    // find max
    unsigned long long int max = sumArray[0];
    for (int i = 1; i < 5; i++)
    {
        if (max < sumArray[i])
        {
            max = sumArray[i];
        }
    }
    cout << max << endl;
}

// 1 2 3 4 5