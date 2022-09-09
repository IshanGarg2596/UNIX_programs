// 1. Reverse the stack using recursion
// 2. Sort the stack data

#include <iostream>
#include "Stack.h"

using namespace std;

void insertBottom(Stack s, int data){
    if(s.isEmpty()){
        s.push(data);
        return;
    }

    int top = s.stackTop();
    s.pop();
    insertBottom(s, data);

    s.push(top);
}

void reverseStack(Stack s){
    if(s.isEmpty()){
        return;
    }

    int data = s.stackTop();
    s.pop();
    reverseStack(s);

    insertBottom(s, data);
}
 

Stack sortStack(Stack stack){
    Stack tempStack;

    while(!stack.isEmpty()){
        int temp = stack.stackTop();
        stack.pop();

        while (!tempStack.isEmpty() && tempStack.stackTop() > temp)
        {
            stack.push(tempStack.stackTop());
            tempStack.pop();
        }
        tempStack.push(temp);
 
    }

    return tempStack;
}


 int main(){
    
    int e, n;
    cout << "Enter no of elements: ";
    cin >> n;

    Stack s(n);
    
    cout<<"Enter elements of stack: ";
    for(int i = 0; i < n; i++){
        cin >> e;
        s.push(e);
    }

    reverseStack(s);
    cout<< "reversed stack: " << "\n"; 
    s.display();

    Stack temp = sortStack(s);
    cout<< "sorted Stack: " << "\n";
     while (!temp.isEmpty())
    {
        cout << temp.stackTop()<< " ";
        temp.pop();
    }
    cout << "\n";
    return 0;
 }