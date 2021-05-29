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
#include <typeinfo>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;
typedef unsigned long long int ulld;

using namespace std;

// https://www.hackerrank.com/challenges/lonely-integer/problem
void lonelyInteger()
{
	/*
	a^b = b^a
	a^a = 0
	a^0 = 0^a = a
	a^(b^c) = a^(b^c)
	(a^b^c^b^a) = (a^a)^(b^b)^c = 0^0^c = c
	*/

	int n;
	int res = 0;
	cin >> n;
	while (n--)
	{
		int input;
		cin >> input;
		res = res ^ input;
	}
	cout << res << endl;
}

// https://www.hackerrank.com/challenges/maximizing-xor/problem
void maximizingXOR()
{
	int xor_res = -1;
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		for (int j = l; j <= r; j++)
		{
			int temp_res = i ^ j;
			if (temp_res > xor_res)
				xor_res = temp_res;
		}
	}
	cout << xor_res << endl;
}

void flippingBits() {
	int tc;
	cin >> tc;
	while (tc--)
	{
		lld n;
		cin >> n;
		lld ans = n ^ 4294967295;
		cout << ans << endl;
	}

}

int main()
{
	lonelyInteger();
	return 0;
}
