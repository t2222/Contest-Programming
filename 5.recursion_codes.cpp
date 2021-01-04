#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#define MAX 1000

typedef long long int lld;
typedef long double llf;

using namespace std;

unsigned long long int factorial(unsigned long long int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

unsigned long long int fibonacci(unsigned long long int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

unsigned long long int fiboSum(unsigned long long int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += fibonacci(n);
    }
    return sum;
}

unsigned long long int sumOfDigits(unsigned long long int n)
{
    if (n <= 0)
        return 0;
    else
    {
        return (n % 10 + sumOfDigits(n / 10));
    }
}

unsigned long long int sumOfNaturalNumbers(unsigned long long int n)
{
    if (n <= 0)
        return 0;
    else
        return (n + sumOfNaturalNumbers(n - 1));
}

long double geometricSum(int n)
{
    if (n == 0)
        return 1;
    else
        return (1 / (pow(3, n))) + geometricSum(n - 1);
}

long double power(long double n, int a)
{
    long double sum = 1;
    for (int i = 1; i <= a; i++)
    {
        sum *= n;
    }
    return sum;
}

long double powerRecursive(long long num, long long exp)
{
    if (exp == 0)
        return 1;
    else if (exp > 0)
    {
        return num * powerRecursive(num, exp - 1);
    }
    else if (exp < 0)
    {
        return 1 / powerRecursive(num, -exp); // -exp means calls become like powerRecursive(num, exp), answer will be 1/(powerRecursive(num, exp))
    }
}

long double serisSum(long double n)
{
    if (n == 1)
        return 1;
    else
    {
        return pow(n, n) + serisSum(n - 1);
    }
}

long arraySum(int a[], int n)
{
    if (n <= 0)
        return 0;
    else
        return  a[n - 1] + arraySum(a, n - 1);
}

void reverseString(char* str)
{
    if (*str)
    {
        reverseString(str + 1);
        printf("%c", *str);
    }
}

int stringLength(char* stringptr)
{
    if (*stringptr == '\0')
        return 0;
    else
        return 1 + stringLength(stringptr + 1);
}

int product(int a, int b)
{
    if (a < b)
        product(b, a);
    if (b <= 0)
        return 0;
    else
    {
        return (a + product(a, b - 1));
    }
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}


void findFactors(int n, int i = 1)
{
    try
    {
        if (i <= n)
        {
            if (i == 0)
                throw i;
            if (n % i == 0)
                cout << i << " ";
        }
    }
    catch (int i)
    {
        cout << "divide by " << i << " error\n";
    }
    findFactors(n, i + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;

    tc = 1;

    while (tc--)
    {
        long double n, m;
        //cin >> n;
        //cout << serisSum(n) << endl;
        //char c[] = "TOUSIF TASNIMUL AKUMAadafasd ADAF";
        //reverseString(c);
        /*
        string stringInput = "IA  AM AKUMA";
        char s[1024];
        strcpy(s, stringInput.c_str());
        cout << stringLength(s);
        */
        findFactors(16);


    }



}

// https://www.w3resource.com/c-programming-exercises/recursion/index.php

