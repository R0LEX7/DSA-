#include <bits/stdc++.h>
using namespace std;

class Queue
{

public:
    stack<int> st;

    void pushHelper( int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int elem = st.top();
        st.pop();

        pushHelper( x);

        st.push(elem);
    }

    void push(int x){
        
        pushHelper( x);
    }

    void pop(){
        if(st.empty()){
            cout<< "Queue is empty"<<endl;
            return;
        }
        st.pop();
    }



    int front(){
        if(st.empty()) {
            cout<<"Queue is empty";
            return -1;
        }
        return st.top();
    }

};

int main()
{
    Queue q;
    q.push(9);
    q.push(71);
    q.pop();
    q.push(99);
    q.pop();
    q.pop();

    cout<<"Queue front -> "<<q.front()<<endl;

    return 0;
}