#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<utility>
#include<queue>
#include<set>
#include<map>
#include<set>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;

using namespace std;

void inputArray(vector<int>& arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
}

void outputArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

set<int> vecToSet(vector<int> arr)
{
    set<int> vset;
    for (int x : arr)
    {
        vset.insert(arr[x]);
    }
    return vset;
}

int main()
{
    /*
    1. Keep counter of both array's element's occurance in occA and occB,
    2. occA and occB can be addressed by input_value % 100, because input_value can't be greater than 100
    3. Also take input of both elements in a set: elements to keep track of how many unique elements are there,
    4. Finally traverse set and val%100 to compare both occA and occB to see and compare the occurances
    */
    set<int> elements;

    int occA[100];
    int occB[100];
    memset(occA, 0, sizeof(occA));
    memset(occB, 0, sizeof(occB));
    int m, n;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        occA[val % 100]++;
        elements.insert(val);
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        occB[val % 100]++;
        elements.insert(val);
    }

    set<int>::iterator itr;
    for (auto val : elements)
    {
        int position = val % 100;
        if (occB[position] != occA[position])
        {
            cout << val << " ";
        }
    }
}


