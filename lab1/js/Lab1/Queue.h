#define SIZE 100

class Queue
{
    int *Q;      
    int capacity; //max size of array   
    int front;      
    int rear;      
    int count; //current size of the array

public:
    Queue(int size = SIZE);     // constructor

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();

};   

Queue::Queue(int size)
{
    Q = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

int Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        std::cout << "Underflow\nQueue is empty";
        return -1;
    }
 
    int x = Q[front];
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}

void Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        std::cout << "Overflow\nQueue is full";
        return;
    }
 
    rear = (rear + 1) % capacity;
    Q[rear] = item;
    count++;
}
 
int Queue::peek()
{
    if (isEmpty())
    {
        std::cout << "Underflow\nQueue is empty";
        return 0;
    }
    return Q[front];
}

bool Queue::isEmpty() {
    return (size() == 0);
}

int Queue::size() {
    return count;
}

bool Queue::isFull() {
    return (size() == capacity);
}