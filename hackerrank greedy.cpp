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

// https://www.hackerrank.com/challenges/priyanka-and-toys/problem
void priyanka_and_toys()
{
    unsigned int n, min_range, max_range;
    cin >> n;
    vector<unsigned int> toys;
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int val;
        cin >> val;
        toys.push_back(val);
    }
    sort(toys.begin(), toys.end()); // sort data
    int count = 0, i = 0;
    while (i < n)
    {
        min_range = toys[i];
        max_range = min_range + 4;
        while (i < n)
        {
            if (toys[i] > max_range) //out of range , so break as we have found 1 group. so increment count
            {
                // i++; // this was causing error, we don't need this, as toys[i] is not compared and put into any group
                break;
            }
            if (toys[i] <= max_range || toys[i] >= min_range)
            {
                i++;
            }
        }
        count++;
    }

    cout << count << endl;
}

// https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
/*
Given any triangle, if a, b, and c are the lengths of the sides, the following is always true:
a + b > c && b + c > a && c + a > b

Given a sorted array named 'a', if indices x < y < z then a[x] <= a[y] <= a[z] is alway true, which
makes a[y] + a[z] > a[x] and a[z] + a[x] > a[y] always true.
So to make a valid triangle on top of that, we only need to make sure that
one more condition is met: a[x] + a[y] > a[z] (in which a[x], a[y], a[z] are
the three sides and in that order)

From the description, we know we want a[z] to be the largest possible,
and given that, a[x] to be the largest possible.
What that implies is that they are the last three consecutive elements
in the sorted assending array which satisfy a[x] + a[y] > a[z].
(why consecutive indexed elements? because if some a[i-3] + a[i-1] > a[i] or a[i-3] + a[i-2] > a[i] we
know a[i-2] + a[i-1] > a[i], because the array is sorted and non-decreasing,
and the consecutive elements solution will give you the biggest smallest side if exists)

So we search from the back of the array, from the biggest to the
smallest of groups of the three consecutive elements in the array, and check if they
satisfy a[x] + a[y] > a[z], if satisfied then break out of the loop and print them,
if even when we reached the last possible iteration (the first and smallest element a[0] as a[x],
and the opposite condition a[x]+a[y]<=a[z] still passes the check, which means
it will never satisfy a[x] + a[y] > a[z] ever, we much now print -1 and return to end the search.)
*/
void maximum_peimeter_triangle()
{
    unsigned int n;
    vector <unsigned int> sticks;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        unsigned int val;
        cin >> val;
        sticks.push_back(val);
    }
    sort(sticks.begin(), sticks.end());

    bool flag = false; // checks if no triangle was found
    for (int i = n - 3; i >= 0; i--)
    {
        if (sticks[i] + sticks[i + 1] > sticks[i + 2]) // a[x]+a[y] > a[z]
        {
            flag = true;
            cout << sticks[i] << " " << sticks[i + 1] << " " << sticks[i + 2] << "\n";
            break;
        }
    }

    if (flag == false)
        cout << "-1\n";
}

// https://www.hackerrank.com/challenges/jim-and-the-orders/problem
bool cmp(pair<ulld, ulld> ob1, pair<ulld, ulld> ob2) // sort by second element
{
    return ob1.second < ob2.second;
}
void Jim_and_the_Orders()
{
    ulld n;
    vector <pair<ulld, ulld>> orderlist; // prep time and order
    cin >> n;
    for (ulld i = 0; i < n; i++)
    {
        ulld preptime, order;
        cin >> order >> preptime;
        orderlist.push_back(make_pair(i, order + preptime)); // customer number and order+preptime
    }

    sort(orderlist.begin(), orderlist.end(), cmp); // sort by prep time and order sum

    for (ulld i = 0; i < n; i++) // print result ids
    {
        cout << orderlist[i].first + 1 << " ";
    }
}

// don't know why but using multimap pass all test cases
// multimap is sorted by default using key values
/*
void Jim_and_the_Orders_multimap()
{
    ulld n;
    multimap<ulld, ulld> orderlist; // prep time and order
    cin >> n;
    for (ulld i = 0; i < n; i++)
    {
        ulld preptime, order;
        cin >> order >> preptime;
        orderlist.insert(order + preptime, i + 1); // customer number and order+preptime
    }


    for (multimap<ulld, ulld >::iterator me = orderlist.begin(); me != orderlist.end(); me++)
    {
        cout << me->second << " ";
    }
}
*/


// https://www.hackerrank.com/challenges/two-arrays/problem

bool cmp1(int n1, int n2)
{
    return n1 > n2;
}
void Permuting_Two_Arrays()
{
    ulld q, n, k;
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        vector<ulld> a1, a2;
        a1.clear();
        a2.clear();

        for (int i = 0; i < n; i++)
        {
            ulld val;
            cin >> val;
            a1.push_back(val);
        }
        for (int i = 0; i < n; i++)
        {
            ulld val;
            cin >> val;
            a2.push_back(val);
        }

        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end(), cmp1);

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (a1[i] + a2[i] < k)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return;
}

/*
2
3 10
2 1 3
7 8 9
4 5
1 2 2 1
3 3 3 4

We can sort array A ascending and sort array B descending,
and then because they are sorted we know that we are matching the highest possible
from B with the lowest possible from A each time and if 1 of those fails then we know
it is not possible. The reason we know this is true is because they are inversely sorted,
so we have already made the optimal decision at each stage in terms of the amount of
absolute difference we have 'wasted/extra' thus leaving us with the tightest bounding
number to k for each index. Because it is the tightest bound number,
there is no other permutation that will pass if 1 comparison fails.
*/

int main()
{
    closest_Numbers();
    return 0;
}
