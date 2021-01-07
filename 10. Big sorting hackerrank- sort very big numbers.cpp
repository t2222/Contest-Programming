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
bool compare(string s1, string s2) // if true then s2 will be before s1, else keep s1 before s2
{
    if (s1.length() == s2.length())
    {
        return (s1 < s2); // if both are equal in size then return larger string, ie: keep original ordering
    }
    else
    {
        return (s1.length() < s2.length()); // else return bigger sized string
    }
}


// a more simplified method from GFG
bool compareNumbers(string str1, string str2)
{
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    // If lengths are same 
    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        if (str1[i] > str2[i])
            return false;
    }

    return false;
}

int main()
{
    vector<string> inputs;
    string val;
    int n;
    cin >> n;
    while (n--) {
        cin >> val;
        inputs.push_back(val);
    }
    sort(inputs.begin(), inputs.end(), compare);
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << inputs[i] << endl;
    }
}


/*
// A C++ program to demonstrate
// STL sort() using
// our own comparator
#include <bits/stdc++.h>
using namespace std;

// An interval has a start
// time and end time
struct Interval {
    int start, end;
};

// Compares two intervals
// according to staring times.
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

int main()
{
    Interval arr[]
        = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort the intervals in increasing order of
    // start time
    sort(arr, arr + n, compareInterval);

    cout << "Intervals sorted by start time : \n";
    for (int i = 0; i < n; i++)
        cout << "[" << arr[i].start << "," << arr[i].end
             << "] ";

    return 0;
}

*/