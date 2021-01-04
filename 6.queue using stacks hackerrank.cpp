#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<utility>
#include<queue>
#include<map>
#include<set>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;


struct Queue
{
    stack <int> s1, s2;
    void enqueue(int val)
    {
        s1.push(val);
        return;
    }

    void printFront()
    {
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << s2.top() << "\n";
        return;
    }

    int dequeue()
    {
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;

    }

};



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Queue q;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int val;
            cin >> val;
            q.enqueue(val);
        }
        else if (op == 2)
        {
            q.dequeue();
        }
        else if (op == 3)
        {
            q.printFront();
        }
    }



}

/*
// tle

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<utility>
#include<queue>
#include<map>
#include<set>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;


struct Queue
{
    stack <int> s1, s2;
    void enqueue(int val)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return;
    }

    void printFront()
    {

cout << s1.top() << endl;

return;
    }

    int dequeue()
    {
        if (s1.empty())
            return 0;
        int val = s1.top();
        s1.pop();
        return val;
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Queue q;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int val;
            cin >> val;
            q.enqueue(val);
        }
        else if (op == 2)
        {
            q.dequeue();
        }
        else if (op == 3)
        {
            q.printFront();
        }
    }



}


*/