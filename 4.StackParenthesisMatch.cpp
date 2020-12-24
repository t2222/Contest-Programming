#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#define MAX 1000
// partial match

using namespace std;
bool isMatched(char c1, char c2);
bool isBracketBalanced(string s);
class StackClass
{
    int top;
public:
    char s[MAX];
    StackClass() { top = -1; memset(s, 0, MAX); }
    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
    int count_elements();
    // bool reverse_stack();
};

bool StackClass::push(char x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow\n";
        return false;
    }
    else
    {
        s[++top] = x;
        return true;
    }
}

char StackClass::pop()
{
    if (top < 0)
    {
        //cout << "Stack underflow\n";
        return 0;
    }
    else
    {
        int val = s[top];
        s[top] = -1;
        --top;
        return val;
    }
}

char StackClass::peek()
{
    if (top < 0)
    {
        //cout << "Stack Empty\n";
        return 0;
    }
    else
    {
        return s[top];
    }
}


bool StackClass::isEmpty()
{
    if (top < 0)
        return true;
    return false;
}

int StackClass::count_elements()
{
    return top + 1;
}

bool isMatched(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '{' && c2 == '}')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    else
        return false;
}

bool isBracketBalanced(string s)
{
    StackClass stk;
    unsigned int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);
        if (isMatched(stk.peek(), s[i]))
            stk.pop();
    }
    if (stk.isEmpty() && i <= s.size())
        return true;
    else
        return false;
}

// GFG: pass all test cases
bool areBracketsBalanced(string expr)
{
    StackClass s;
    char x;

    // Traversing the Expression 
    for (unsigned int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack 
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.isEmpty())
            return false;

        switch (expr[i]) {
        case ')':

            // Store the top element in a 
            x = s.peek();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b 
            x = s.peek();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c 
            x = s.peek();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack 
    return (s.isEmpty());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        string inp;
        cin >> inp;
        string ans = (isBracketBalanced(inp)) ? "YES\n" : "NO\n";
        cout << ans;

    }
}

// 20 1 4 1 6 1 -55 1 600 1 98 2 3 3 