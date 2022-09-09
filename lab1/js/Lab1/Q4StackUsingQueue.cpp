#include <iostream>
#include "queue.h"

using namespace std;

class Stack {
    Queue q1, q2;
 
public:
    void push(int x)
    {
        q2.enqueue(x);
 
        while (!q1.isEmpty()) {
            if(!q2.isFull()){
               q2.enqueue(q1.peek());
               q1.dequeue();
            }
        }

        Queue q = q1;
        q1 = q2;
        q2 = q;
    }
 
    void pop()
    {
        if (q1.isEmpty())
            return;
        q1.dequeue();
    }
 
    int top()
    {
        if (q1.isEmpty())
            return -1;
        return q1.peek();
    }
 
    int size()
    {
        return q1.size();
    }

};

int main(){
    int e, n;
    cout << "Enter no of elements: ";
    cin >> n;

    Stack s;
    
    cout<<"Enter elements of stack: ";
    for(int i = 0; i < n; i++){
        cin >> e;
        s.push(e);
    }

    cout << "Stack: ";
    while(s.top() != -1){
        cout<<s.top() << " ";
        s.pop();
    }

    cout << "\n";

    return 0;

}