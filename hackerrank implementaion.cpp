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
#include <unordered_map>
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

// https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
void repeated_String()
{
    ulld n;
    string s;
    cin >> s;
    cin >> n;
    ulld len = s.length();
    ulld total_a_freq = 0;
    ulld full_string_count = n / len; // total full strings in the n lengthed substring
    ulld a_count = 0; //  count of a 

    if (len == 1 && s[0] == 'a') // length 1 string 
    {
        cout << n << endl;
        return;
    }

    else
    {
        // find a in string
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'a')
                a_count++;
        }
        total_a_freq += full_string_count * a_count; // multiply 'a'-s by formed full strings to get total freq of all full stirngs

        // process partial string
        a_count = 0;
        ulld partial_string_len = n % len; // partial strings
        for (ulld i = 0; i < partial_string_len; i++) // a-s in partial string
        {
            if (s[i] == 'a')
                a_count++;
        }

        total_a_freq += a_count; // total a-s

        cout << total_a_freq << endl;
    }

}

// https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps
void two_strings()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        string s1, s2;
        const int LEN = 27;
        cin >> s1 >> s2;
        bool flag_array_s1[LEN] = { false };
        bool status = false;

        for (int i = 0; i < s1.length(); i++)
        {
            int pos = (s1[i] - 'a') % 26;
            flag_array_s1[pos] = true;
        }

        for (int i = 0; i < s2.length(); i++)
        {
            int pos = (s2[i] - 'a') % 26;
            if (flag_array_s1[pos]) // char of s2 is found in s1
            {
                status = true;
                break;
            }
        }

        if (status)
            cout << "YES\n";
        else
            cout << "NO\n";
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



        sum += prices[i];
        if (sum > k)
            break;
        else
            count++;

    }

    cout << count << endl;

    return;
}

// https://www.hackerrank.com/challenges/picking-numbers/problem
void picking_numbers()
{
    int n;
    cin >> n;
    int arr[100];
    memset(arr, 0, sizeof(int) * 100);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr[val]++; // store frequency
    }

    int max_freq = -1; // find max of consecutive 2 elements
    for (int i = 0; i < n - 1; i++)
    {
        int sum = arr[i] + arr[i + 1];
        if (max_freq < sum)
            max_freq = sum;
    }

    cout << max_freq << endl;
}


//https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
void catAndMouse()
{
    int tc, catA, catB, mouseC;
    cin >> tc;
    while (tc--)
    {
        cin >> catA >> catB >> mouseC;
        int diffA = abs(catA - mouseC);
        int diffB = abs(catB - mouseC);
        if (diffA == diffB)
            cout << "Mouse C\n";
        else if (diffA > diffB)
            cout << "Cat B\n";
        else
            cout << "Cat A\n";
    }
}

int main()
{
    ransom_note();
    return 0;
}
