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
typedef unsigned long long int ulld;

using namespace std;
int main()
{
	int n;
	vector<int> candles;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		candles.push_back(val);
	}

	int max = candles[0];
	for (int i = 1; i < candles.size(); i++)
	{
		if (max < candles[i])
		{
			max = candles[i];
		}
	}

	int counter_max = 0;
	for (int i = 0; i < candles.size(); i++)
	{
		if (max == candles[i])
			++counter_max;
	}
	cout << counter_max << endl;

	return 0;
}

