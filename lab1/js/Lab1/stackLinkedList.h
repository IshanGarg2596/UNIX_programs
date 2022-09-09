struct node{
    int data;
    struct node* next;
};

class Stack{
    struct node* top;
public:
    Stack(){
        top = NULL;
    }

    void push(int data);
    void pop();
    void display();
    bool isEmpty();
    int peek();
    int stackTop();
};

void Stack::push(int data){
    node* temp = new node();
    if (!temp)
    {
        std::cout << "\nStack Overflow";
        exit(1);
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

void Stack::pop(){
    node* temp;

    if (top == NULL)
    {
        std::cout << "\nStack Underflow" << "\n";
        exit(1);
    }
    else
    {
        temp = top;
        top = top->next;
        std::free(temp);
    }
}

void Stack::display(){
    node* temp;
    
    if (top == NULL){
        std::cout << "\nStack Underflow";
        exit(1);
    } else{
        temp = top;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

bool Stack::isEmpty(){
    return top == NULL;
}

int Stack::peek()
{ 
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}
