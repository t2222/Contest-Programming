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


// Complete the camelcase function below.
int camelcase(string s) {
    int wordCount = 0, firstWordOccurance = 0;
    if (s != "")
    {
        wordCount = 1;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            firstWordOccurance = i;
            break;
        }
    }

    if (firstWordOccurance)
    {
        for (int i = firstWordOccurance; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                ++wordCount;
            }
        }
    }


    return wordCount;

}

int passwordStrength(string s) {
    int size_req = 0;
    if (s.size() < 6)
    {
        size_req = (6 - s.size());
    }

    int strength = 0;
    bool digit = false, lowerCase = false, uppercase = false, specialCharacter = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (strength >= 4)
            break;
        if ((s[i] >= '0' && s[i] <= '9') && digit == false)
        {
            strength++;
            digit = true;
        }
        if ((s[i] >= 'A' && s[i] <= 'Z') && uppercase == false)
        {
            strength++;
            uppercase = true;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') && lowerCase == false)
        {
            strength++;
            lowerCase = true;
        }
        if ((s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' ||
            s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')' ||
            s[i] == '-' || s[i] == '+') && specialCharacter == false)
        {
            strength++;
            specialCharacter = true;
        }
    }

    if (strength < 4)
    {
        return max(size_req, (4 - strength)); // see which type of improvement is most needed
    }

    else
    {
        return size_req; // if both are equal return any of them
    }

}

char* superReducedString(char* str) {
    int len = strlen(str);
    int i;
    char reduced_string[101];
    for (i = 0; i < len; i++)
    {
        if (str[i] != str[i + 1])
            continue;

        while (str[i] == str[i + 1])
        {

        }
    }
    return reduced_string;
}


int main()
{
    char input[101];
    scanf("%s", input);
    cout << superReducedString(input);
    return 0;
}
