#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#define MAX 1000

using namespace std;

void leftRotateByOneElement(int a[], int n)
{
    int temp = a[0];
    for (int i = 0 ; i < n ; i++)
    {
        a[i] = a[i+1];
    }
    a[n-1] = temp;
}

void leftRotate(int a[], int n, int k)
{
    while (k--)
    {
        leftRotateByOneElement(a,n);
    }
}


int main()
{
    // For getting input from input.txt file
    //freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc, n, k;
    //cin >> tc ;
    tc = 1;
    while (tc--)
    {
        cin >> n >> k;
        int a[n];
        for (int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
        }

        leftRotate(a,n,k);
        for (int i = 0 ; i < n ; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;


    }

    return 0;
}
