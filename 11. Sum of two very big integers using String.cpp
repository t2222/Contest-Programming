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

void swapCharacters(char& c1, char& c2)
{
    char temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
}

void swapStrings(string& s1, string& s2)
{
    string temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

void reverse_string(string& str)
{
    int n = str.size();
    for (int i = 0; i < n / 2; i++)
    {
        swapCharacters(str[i], str[n - 1 - i]);
    }
}

int charToInt(char c)
{
    return (c - '0');
}

char intToChar(int n)
{
    return (n + '0');
}

/*
do following:
1) Reverse both strings.
2) Keep adding digits one by one from 0’th index (in reversed strings) to end of smaller string,
append the sum % 10 to end of result and keep track of carry as sum/10.
3) Finally reverse the result.
*/
string sumOfTwoNumbers(string s1, string s2)
{
    if (s1.size() > s2.size())
        swapStrings(s1, s2);
    reverse_string(s1);
    reverse_string(s2);
    //reverse(s1.begin(), s1.end());
    //reverse(s2.begin(), s2.end());
    int carry = 0;
    int n1 = s1.size(), n2 = s2.size();
    string result = "";
    for (int i = 0; i < n1; i++)
    {
        int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = (s2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        result.push_back(carry + '0');

    reverse_string(result);
    return result;
}

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    cout << sumOfTwoNumbers(n1, n2);
    //cout <<  typeid(intToChar(0)).name() << " " << typeid(charToInt('9')).name();
    //swapStrings(n1, n2);
    //cout << n1 << " " << n2;

    //reverse(n1.begin(), n1.end());
    //reverse(n2.begin(), n2.end());
}