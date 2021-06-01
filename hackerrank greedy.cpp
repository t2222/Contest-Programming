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

// https://www.hackerrank.com/challenges/2d-array/problem
void Two_dimensional_array()
{
    const int ROW = 6, COL = 6;
    int a[ROW + 1][COL + 1];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int val;
            cin >> val;
            a[i][j] = val;
        }
    }

    int hourglass_sum = 0;
    int max_val = -9999999;
    for (int i = 0; i <= ROW - 3; i++)
    {
        for (int j = 0; j <= COL - 3; j++)
        {
            hourglass_sum += a[i][j] + a[i][j + 1] + a[i][j + 2]
                + a[i + 1][j + 1]
                + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
            //cout << hourglass_sum << " ";
            if (hourglass_sum > max_val)
                max_val = hourglass_sum;
        }
        //cout << "\n";
    }

    cout << max_val << endl;

}

// https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
void min_absolute_diff()
{
    int n;
    cin >> n;
    vector<lld> arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    int min = 999999;
    for (int i = 0; i < n - 1; i++)
    {
        lld dif = abs(arr[i + 1] - arr[i]);
        if (min > dif)
            min = dif;
    }
    cout << min << endl;
}

// https://www.hackerrank.com/challenges/marcs-cakewalk/problem?h_r=next-challenge&h_v=zen
bool comparator(int v1, int v2)
{
    return v1 > v2;
}

void cakewalk()
{
    int n;
    vector<lld> arr;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end(), comparator); // sort by descending order, to minimize the result
    //cout << arr[0];
    lld res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res += pow(2, i) * arr[i];
    }

    cout << res << endl;
}

// hacckerrank find median
void find_median()
{
    int n;
    vector<lld> arr;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    int median_pos = arr.size() / 2; // as even number of elements, so median is at size/2
    cout << arr[median_pos];
}

// https://www.hackerrank.com/challenges/closest-numbers/problem
void closest_Numbers()
{
    int n;
    cin >> n;
    vector<lld> arr;
    //input
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    // find min difference
    int min = 999999;
    for (int i = 0; i < n - 1; i++)
    {
        lld dif = abs(arr[i + 1] - arr[i]);
        if (min > dif)
        {
            min = dif;
        }
    }

    // find arrays that have this min difference
    for (int i = 0; i < n - 1; i++)
    {
        lld dif = abs(arr[i + 1] - arr[i]);
        if (min == dif)
        {
            cout << arr[i] << " " << arr[i + 1] << " ";
        }
    }
}

// https://www.hackerrank.com/challenges/mark-and-toys/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=sorting
void maximumToys() {
    vector<ulld> prices;
    ulld k, n;
    cin >> n >> k;
    while (n--)
    {
        ulld val;
        cin >> val;
        prices.push_back(val);
    }
    sort(prices.begin(), prices.end());
    int count = 0, sum = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (sum > k)
            break;
        else
        {
            sum += prices[i];
            count++;
        }
    }

    cout << count - 1 << endl;

    return;
}

int main()
{
    closest_Numbers();
    return 0;
}
