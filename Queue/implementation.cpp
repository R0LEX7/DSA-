#include<iostream>
using namespace std;

  class queue{
        int *arr;
        int size;
        int qfront;
        int rear;

    public:
        queue(){
            size = 1000001;
            arr = new int[size];
            qfront = rear = 0;
        };

        int getSize(){
            if(rear == qfront){
                return 0;
            }else{
                return (rear);
            }
        }

        void enqueue(int d){
            // if queue is full
            if(rear == size-1){
                cout<<"Queue is full"<<endl;
            }else{
                arr[rear] = d;
                rear++;
            }
        };

        int dequeue(){
            if(rear == qfront){
                return -1;
            }else{
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;
                if(rear == qfront){
                    rear = qfront = 0;
                }
                return ans;
            }
        }

        int front(){
            if(qfront == rear){
                cout<<"Queue is Underflow/Empty"<<endl;
                return -1;
            }else{
                return arr[qfront];
            }
        }

        bool empty(){
            if(qfront == rear){
                return true;
        }
        return false;
    };

  };
int main(){

    queue q;
    q.enqueue(2);
    cout<<"size -> "<<q.getSize()<<endl;
    cout<<"front -> "<<q.front()<<endl;
    q.dequeue();
    cout<<"size -> "<<q.getSize()<<endl;
    cout<<"front -> "<<q.front()<<endl;
    q.enqueue(100);
    cout<<"front -> "<<q.front()<<endl;

    if(q.empty()){
        
        cout<<"Queue Underflow"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }

    return 0;
}