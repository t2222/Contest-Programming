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


// https://www.hackerrank.com/challenges/camelcase/problem
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

// https://www.hackerrank.com/challenges/strong-password/problem
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


// https://www.hackerrank.com/challenges/caesar-cipher-1/problem
char shiftCapital(char c, int shift)
{
    if ((int(c) + shift) > 90) //overflow
    {
        c = 'A' + (c + shift - 91);
    }
    else
    {
        c = c + shift;
    }
    return c;
}

char shiftSmall(char c, int shift)
{
    if ((int(c) + shift) > 122) //overflow
    {
        c = 'a' + (c + shift - 123);
    }
    else
    {
        c = c + shift;
    }
    return c;
}

void caesarCipherProb()
{
    string inp;
    int shift, n;
    cin >> n >> inp >> shift;
    char c;
    for (int i = 0; i < inp.size(); i++)
    {
        /*
        // works for some case
        if (inp[i] >= 65 && inp[i] <= 90) // capital
        {
            inp[i] = shiftCapital(inp[i],shift);
        }
        else if (inp[i] >= 97 && inp[i] <= 122) // small
        {
            inp[i] = shiftSmall(inp[i],shift);
        }
        */

        if (inp[i] >= 97 && inp[i] <= 122)// small case
        {
            int relative_ascii_pos = inp[i] - 'a';
            int shifted_pos = relative_ascii_pos + shift;
            int modulus_roundedUp_pos = shifted_pos % 26;
            char final_shifted_char = modulus_roundedUp_pos + 'a';

            inp[i] = final_shifted_char;

            // this is step by step what needs to be done. it can be written in one line like this
            // inp[i] = ((inp[i]-'a'+shift) % 26) + 'a';
        }

        else if (inp[i] >= 65 && inp[i] <= 90)// capital case
        {
            int relative_ascii_pos = inp[i] - 'A';
            int shifted_pos = relative_ascii_pos + shift;
            int modulus_roundedUp_pos = shifted_pos % 26;
            char final_shifted_char = modulus_roundedUp_pos + 'A';

            inp[i] = final_shifted_char;

            // this is step by step what needs to be done. it can be written in one line like this
            // inp[i] = ((inp[i]-'A'+shift) % 26) + 'A';
        }


    }

    cout << inp << endl;
}

// https://www.hackerrank.com/challenges/mars-exploration/problem
void marsExploration()
{
    string msg = "SOS";
    string inp;
    cin >> inp;

    int num_message = inp.size() / msg.size();

    int total_changed_letters = 0;
    int i = 0;
    while (i < inp.size())
    {
        for (int j = 0; j < msg.size(); j++)
        {
            if (msg[j] != inp[i])
            {
                total_changed_letters++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }

    cout << total_changed_letters << endl;

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
