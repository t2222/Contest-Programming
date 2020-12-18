#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#include <iomanip>
#include <cstdio>


using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
    string s;
    int a, b, c, ans;
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin >> a >> b >> c;
//    cin >> s;
    scanf("%d %d %d", &a, &b, &c);
    char str[50];
    scanf("%s", str);
    ans = a ? b : c; // to simplify: if (a) ans = b; else ans = c;
//    cout << ans << "\n";
//    cout << s << "\n";
    printf("%d\n", ans);
    printf("%s\n", str);
    return 0;
}

