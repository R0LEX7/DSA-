#include<iostream>
#include<queue>
using namespace std;


int main(){
    queue<int> q;

    q.push(2);
    cout<<"front -> "<<q.front()<<endl;
    q.push(20);
    cout<<"front -> "<<q.front()<<endl;
    q.push(200);
    cout<<"front -> "<<q.front()<<endl;
    q.push(2000);
    cout<<"front -> "<<q.front()<<endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<"front -> "<<q.front()<<endl;
    if(q.empty()){
        cout<<"Queue Underflow"<<endl;
    }else{
        cout<<"non-empty Queue "<<endl;

    }

    return 0;
}