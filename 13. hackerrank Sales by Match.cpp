#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring> // needed for memsets
#include<cstdio>
#include <cmath>
#include<stack>
#include<utility> // needed for pair
#include<queue>
#include<set>
#include<map>
#include<set>
#include<numeric> // used accumulate
#include <bitset>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;
typedef unsigned long long int ulld;

using namespace std;

void saleByMatch()
{
	int n, val;
	cin >> n;
	int a[101] = { 0 };
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> val; // input
		a[val]++; // increase the position of input by 1
		// if a[val] == 2, then a pair is formed, so increment cntand reset a[val] to 0 
		//to start looking for pairs again
		if (a[val] == 2)
		{
			a[val] = 0;
			++cnt;
		}
	}
	cout << cnt;
}

int main()
{
	saleByMatch();
}
