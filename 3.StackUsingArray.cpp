#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
#define MAX 1000

using namespace std;
class StackClass
{
    int top;
public:
    int s[MAX];
    StackClass() { top = -1; memset(s, 0, MAX); }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int count_elements();
    // bool reverse_stack();
};

bool StackClass::push(int x)
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

int StackClass::pop()
{
    if (top < 0)
    {
        cout << "Stack underflow\n";
        return 0;
    }
    else
    {
        int val = s[top--];
        return val;
    }
}

int StackClass::peek()
{
    if (top < 0)
    {
        cout << "Stack Empty\n";
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

/*
bool StackClass::reverse_stack()
{
    if (top < -1)
        return false;
    else
    {
        int temp;
        int end = top+1, beg = 0;
        for (int i = 0; i < end; i++)
        {

        }
    }
}
*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    int* IntPtr;

    StackClass stk; // if i put this into while loop new instance of stk will be created and top will be zero
    while (tc--)
    {
        int cmd, input;
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> input;
            cout << stk.push(input) << endl;;
        }
        else if (cmd == 2)
        {
            cout << stk.pop() << endl;
        }
        else if (cmd == 3)
        {
            cout << stk.peek() << endl;;
        }
        else if (cmd == 4)
        {
            cout << stk.isEmpty() << endl;;
        }
        else if (cmd == 5)
        {
            cout << stk.count_elements() << endl;;
        }

    }
    return 0;
}

