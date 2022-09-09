#define SIZE 100

class Stack{
private:
    int size;
    int top;
    int* S;
public:
    Stack(int size = SIZE);
    void push(int x);
    int pop();
    int peek(int index);
    bool isFull();
    bool isEmpty();
    void display();
    int stackTop();
};
 
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new int[size];
}
 
void Stack::push(int x) {
    if (isFull()){
        std::cout << "Stack Overflow!" << "\n";
    } else {
        top++;
        S[top] = x;
    }
}
 
int Stack::pop() {
    int x = 1;
    if (isEmpty()){
        std::cout << "Stack Underflow!" << "\n";
    } else {
        x = S[top];
        top--;
    }
    return x;
}
 
int Stack::peek(int index) {
    int x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        std::cout << "Invalid position!" << "\n";
    } else {
        x = S[top-index+1];
    }
    return x;
}
 
bool Stack::isFull() {
    if (top == size-1){
        return true;
    }
    return false;
}
 
bool Stack::isEmpty() {
    if (top == -1){
        return true;
    }
    return false;
}
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        std::cout << S[i] << " ";
    }
    std::cout << "\n";
}
 
int Stack::stackTop() {
    if (isEmpty()){
        return -1;
    }
    return S[top];
}