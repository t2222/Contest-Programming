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
#include <sstream>
#include <limits>


#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;
typedef unsigned long long int ulld;

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

