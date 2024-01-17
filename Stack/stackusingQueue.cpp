#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int stackSize = 0;
    queue<int> q;

    bool isEmpty()
    {
        return q.empty();
    }

    int  size()
    {
        return q.size();
    }

    void push(int x)
    {
        q.push(x);
        stackSize++;
        for (int i = 0; i < q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            q.pop();
            stackSize--;
        }
        else
        {
            cout << "Empty queue" << endl;
        }
    }

    int top()
    {
        if (!isEmpty())
            return q.front();
        return -1;
    }

};

int main()
{
    Stack st ;
    st.push(6);
    st.push(66);
    st.push(99);
    st.pop();



    cout<<st.size()<<endl;

    return 0;
}