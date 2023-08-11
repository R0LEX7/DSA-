#include<iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top = -1;

    Stack(int size){
        this->size = size;
        arr = new int[size];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == size-1;
    }

    void push(int d){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }else{
            top++;
            arr[top]=d;
        }
    }

        void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }else{
            top--;
        }
    }

    

    int peak(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }else{
        return arr[top];
        }
    }

};


int main(){

    // stack <int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(50);
    st.push(60);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    // st.pop();

   cout<<"peak element of stack is -> "<< st.peak()<<endl;
    return 0;
}