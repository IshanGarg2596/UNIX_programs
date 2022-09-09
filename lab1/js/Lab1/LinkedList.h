struct node{
    int data;
    struct node* next;
};

class linkedList{
    struct node* List;
public:
    linkedList(){
        List = NULL;
    }

    void insert(int data);
    void insertBack(int data);
    void printList();
    void reverse();
    void sort();
    node* getHead();
};

void linkedList::insert(int data){
    struct node* temp = new node;
    temp->data = data;
    if(List == NULL){
        List = temp;
        temp->next = NULL;
    } else{
        temp->next = List;
        List = temp;
    }
}

void linkedList::insertBack(int data){
    struct node* temp = new node;
    temp->data = data;
        
    if(List == NULL){
        List = temp;
        temp->next = NULL;
    } else{
        struct node* end = List;
        while(end->next != NULL){
            end = end->next;
        } 
        end->next = temp;
        temp->next = NULL;
    }
}

void linkedList::printList(){
    struct node* element = List;
    while(element->next != NULL){
        std::cout << element->data << " ";
        element = element->next;
    }

    std::cout << element->data << "\n";
}

node* linkedList::getHead(){
    return List;
}