#include <iostream>
#include "stack.h"

using namespace std;
 
class Queue{
private:
    Stack e_stk;
    Stack d_stk;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};
 
void Queue::enqueue(int x) {
    e_stk.push(x);
}
 
int Queue::dequeue() {
    int x = -1;
    if (d_stk.isEmpty()){
        if (e_stk.isEmpty()){
            cout << "Queue Underflow" << endl;
            return x;
        } else {
            while (!e_stk.isEmpty()){
                d_stk.push(e_stk.stackTop());
                e_stk.pop();
            }
        }
    }
    x = d_stk.stackTop();
    d_stk.pop();
    return x;
}
 
int main() {
    int e, n;
    cout << "Enter no of elements: ";
    cin >> n;
  
    cout<<"Enter elements of queue: ";
    Queue q;
 
    for (int i=0; i<n; i++){
        cin>> e;
        q.enqueue(e);
    }
    cout << endl;
 
    cout << "Dequeue: " << flush;
    for (int i=0; i<n; i++){
        cout << q.dequeue() << flush;
        if (i < n-1){
            cout << " " << flush;
        }
    }

    cout<<"\n";
 
    return 0;
}